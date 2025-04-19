// all.cpp
#include "all.h"

#define MAX_LINE_LENGTH 256
#define MAX_NUMBERS 100

// 图像比较函数，返回一个结构体
MatchResult image_comparison(const char* device_serial, const char* adbPath, const char* templateImagePath, double threshold) {
    MatchResult match = { -1, -1, -1 };  // 初始化结构体

    // 从模拟器获取截图数据
    std::vector<unsigned char> screenshotData = getScreenshotFromEmulator(device_serial, adbPath);

    if (screenshotData.empty()) {
        std::cerr << "无法从模拟器获取截图" << std::endl;
        return match;
    }

    // 解码内存中的截图数据
    cv::Mat target = cv::imdecode(screenshotData, cv::IMREAD_COLOR);

    if (target.empty()) {
        std::cerr << "无法解码截图数据" << std::endl;
        return match;
    }

    // 加载本地的模板图像
    cv::Mat temp = cv::imread(templateImagePath, cv::IMREAD_COLOR);

    if (temp.empty()) {
        std::cout << "无法加载模板图像文件" << std::endl;
        return match;
    }

    // 检查模板是否大于目标图像
    if (temp.cols > target.cols || temp.rows > target.rows) {
        std::cout << "模板尺寸大于目标图像" << std::endl;
        return match;
    }

    // 转换为灰度图像
    cv::Mat target_gray, temp_gray;
    cv::cvtColor(target, target_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(temp, temp_gray, cv::COLOR_BGR2GRAY);

    // 创建结果矩阵
    cv::Mat result;
    int result_cols = target_gray.cols - temp_gray.cols + 1;
    int result_rows = target_gray.rows - temp_gray.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);

    // 执行模板匹配
    cv::matchTemplate(target_gray, temp_gray, result, cv::TM_CCOEFF_NORMED);

    // 寻找最佳匹配位置
    double min_val, max_val;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

    // 根据阈值判断是否找到匹配结果
    if (max_val >= threshold) {
        //// 可视化标记
        //cv::rectangle(target, max_loc, cv::Point(max_loc.x + temp.cols, max_loc.y + temp.rows), cv::Scalar(255, 0, 0), 2);
        //cv::imshow("Result", target);
        //cv::waitKey(0);

        match.x = max_loc.x;
        match.y = max_loc.y;
        match.status = 0;  // 表示匹配成功
    }
    else {
        std::cout << "未找到符合要求的匹配结果" << std::endl;
    }

    return match;
}

// 从模拟器获取截图到内存
std::vector<unsigned char> getScreenshotFromEmulator(const char* device_serial, const char* adbPath) {
    // 检查 adbPath 和 device_serial 是否有效
    if (adbPath == nullptr || device_serial == nullptr) {
        std::cerr << "adbPath 或 device_serial 为空" << std::endl;
        return {};
    }

    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    HANDLE hChildStd_OUT_Rd = NULL, hChildStd_OUT_Wr = NULL;
    if (!CreatePipe(&hChildStd_OUT_Rd, &hChildStd_OUT_Wr, &saAttr, 0)) {
        std::cerr << "创建管道失败" << std::endl;
        return {};
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.hStdError = hChildStd_OUT_Wr;
    si.hStdOutput = hChildStd_OUT_Wr;
    si.dwFlags |= STARTF_USESTDHANDLES;
    ZeroMemory(&pi, sizeof(pi));

    // 构造带设备序列号的 adb 命令
    std::string command = std::string(adbPath) + " -s ";
    command += device_serial;
    command += " exec-out screencap -p";
    //std::cout << "command=" << command <<"\n\n"<< std::endl;

    int wideLen = MultiByteToWideChar(CP_ACP, 0, command.c_str(), -1, NULL, 0);
    auto wideCommand = std::make_unique<wchar_t[]>(wideLen);
    MultiByteToWideChar(CP_ACP, 0, command.c_str(), -1, wideCommand.get(), wideLen);

    if (!CreateProcess(NULL, wideCommand.get(), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        // 获取错误代码
        DWORD errorCode = GetLastError();
        std::cerr << "创建进程失败，错误代码: " << errorCode << std::endl;
        CloseHandle(hChildStd_OUT_Rd);
        CloseHandle(hChildStd_OUT_Wr);
        return {};
    }
    CloseHandle(hChildStd_OUT_Wr);

    std::vector<unsigned char> buffer;
    DWORD bytesRead;
    const int bufferSize = 4096;
    unsigned char temp[bufferSize];
    while (ReadFile(hChildStd_OUT_Rd, temp, bufferSize, &bytesRead, NULL) && bytesRead > 0) {
        buffer.insert(buffer.end(), temp, temp + bytesRead);
    }

    CloseHandle(hChildStd_OUT_Rd);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return buffer;
}

// 在内存中裁剪图像
cv::Mat cropImageInMemory(const cv::Mat& image, int x, int y, int width, int height) {
    cv::Rect roi(x, y, width, height);
    return image(roi).clone();
}

// UTF-8 转 GB2312
std::unique_ptr<char[]> utf8_to_gb2312(const char* utf8_str) {
    // 先计算 UTF-8 转换为宽字符的长度
    int wide_len = MultiByteToWideChar(CP_UTF8, 0, utf8_str, -1, NULL, 0);
    if (wide_len == 0) {
        return nullptr;
    }
    // 分配宽字符数组
    auto wide_str = std::make_unique<wchar_t[]>(wide_len);
    // 进行 UTF-8 到宽字符的转换
    MultiByteToWideChar(CP_UTF8, 0, utf8_str, -1, wide_str.get(), wide_len);

    // 计算宽字符转换为 GB2312 的长度
    int gb2312_len = WideCharToMultiByte(CP_ACP, 0, wide_str.get(), -1, NULL, 0, NULL, NULL);
    if (gb2312_len == 0) {
        return nullptr;
    }
    // 分配 GB2312 字符数组
    auto gb2312_str = std::make_unique<char[]>(gb2312_len);
    // 进行宽字符到 GB2312 的转换
    WideCharToMultiByte(CP_ACP, 0, wide_str.get(), -1, gb2312_str.get(), gb2312_len, NULL, NULL);

    return gb2312_str;
}

// OCR 识别内存中的图像
std::string performOCR(const cv::Mat& image) {
    auto api = std::make_unique<TessBaseAPI>();
    if (api->Init(NULL, "chi_sim")) {
        std::cerr << "无法初始化 Tesseract" << std::endl;
        return "";
    }

    // 转换为 8 位灰度图像
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // 将图像编码为 PNG 内存流
    std::vector<uchar> pngBuffer;
    if (!cv::imencode(".png", grayImage, pngBuffer)) {
        std::cerr << "图像编码失败" << std::endl;
        return "";
    }

    // 从内存中读取 PNG 数据到 Pix
    Pix* pix = pixReadMem(pngBuffer.data(), pngBuffer.size());
    if (!pix) {
        std::cerr << "无法读取 Pix 图像" << std::endl;
        return "";
    }
    auto pixDeleter = [](Pix* p) { pixDestroy(&p); };
    std::unique_ptr<Pix, decltype(pixDeleter)> uniquePix(pix, pixDeleter);

    api->SetImage(uniquePix.get());
    char* outText = api->GetUTF8Text();
    auto outTextDeleter = [](char* p) { delete[] p; };
    std::unique_ptr<char, decltype(outTextDeleter)> uniqueOutText(outText, outTextDeleter);

    std::string utf8Result(uniqueOutText.get() ? uniqueOutText.get() : "");

    // 将 UTF-8 编码转换为 GB2312
    auto gb2312Result = utf8_to_gb2312(utf8Result.c_str());
    std::string finalResult;
    if (gb2312Result) {
        finalResult = gb2312Result.get();
    }
    else {
        std::cerr << "UTF-8 转 GB2312 失败" << std::endl;
    }

    // 移除字符串中的空格
    finalResult.erase(std::remove(finalResult.begin(), finalResult.end(), ' '), finalResult.end());

    return finalResult;
}

// 从指定设备获取截图并裁剪
cv::Mat adb_screenshot_and_crop(const char* device_serial,const char* adbPath, int x, int y, int width, int height) {
    std::vector<unsigned char> screenshotData = getScreenshotFromEmulator(device_serial,adbPath);
    if (screenshotData.empty()) {
        return cv::Mat();
    }

    cv::Mat image = cv::imdecode(screenshotData, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "无法解码截图数据" << std::endl;
        return cv::Mat();
    }

    return cropImageInMemory(image, x, y, width, height);
}

// 对裁剪后的图像进行 OCR 识别
std::unique_ptr<char[]> ocrImage(const cv::Mat& croppedImage) {
    if (croppedImage.empty()) {
        std::cerr << "裁剪后的图像为空" << std::endl;
        return nullptr;
    }

    std::string result = performOCR(croppedImage);
    if (result.empty()) {
        return nullptr;
    }

    auto resultStr = std::make_unique<char[]>(result.length() + 1);
    // 使用安全的 strcpy_s
    if (strcpy_s(resultStr.get(), result.length() + 1, result.c_str()) != 0) {
        std::cerr << "字符串复制失败" << std::endl;
        return nullptr;
    }
    return resultStr;
}

// 执行命令并返回输出
std::string executeCommandAndGetOutput(const char* command) {
    std::string output;
    FILE* pipe = _popen(command, "r");
    if (!pipe) {
        return output;
    }
    char buffer[128];
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) {
            output += buffer;
        }
    }
    _pclose(pipe);
    return output;
}

// 检查样例文本是否是提取文本的子串
int isSubstring(const char* extractedText, const char* sampleText) {
    if (strstr(extractedText, sampleText) != NULL) {
        return 1;
    }
    return 0;
}

// 执行命令的函数
void runAdbCommand(const char* command) {
    int result = system(command);
    if (result != 0) {
        std::cerr << "执行 ADB 命令失败: " << command << std::endl;
    }
}

// 模拟触摸按下操作
void adbTouchDown(const char* device_serial, const char* adbPath, int x, int y) {
    char command[256];
    // 拼接带有 ADB 完整路径的命令
    snprintf(command, sizeof(command), "\"%s\" -s %s shell input tap %d %d", adbPath, device_serial, x, y);
    runAdbCommand(command);
}

// 模拟触摸移动操作
void adbTouchMove(const char* device_serial, const char* adbPath, int x1, int y1, int x2, int y2, int duration) {
    char command[256];
    // 拼接带有 ADB 完整路径的命令
    snprintf(command, sizeof(command), "\"%s\" -s %s shell input swipe %d %d %d %d %d", adbPath, device_serial, x1, y1, x2, y2, duration);
    runAdbCommand(command);
}

// 自定义函数 read，读取 Settings.txt 文件中的数字到数组
int readtxt(int* numbers) {
    const char* filename = ".\\Settings.txt";
    FILE* file;
    errno_t err;

    // 尝试以追加模式打开文件，如果文件不存在则创建它
    err = fopen_s(&file, filename, "a");
    if (err != 0) {
        perror("无法创建或打开文件");
        return -1;
    }
    fclose(file);

    // 尝试以只读模式打开文件
    err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("无法打开文件");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_NUMBERS) {
        // 跳过数字前的非数字字符
        char* num_start = line;
        while (*num_start != '\0' && (*num_start < '0' || *num_start > '9')) {
            num_start++;
        }

        // 如果找到数字，将其转换为整数并存储到数组
        if (*num_start != '\0') {
            numbers[count++] = atoi(num_start);
        }
    }

    fclose(file);
    return count;
}

// 从 address.txt 文件中读取地址
int readAddressFromFile(char* address, size_t size) {
    FILE* file;
    errno_t err = fopen_s(&file, ".\\address.txt", "r");  // 使用 fopen_s 替代 fopen
    if (err != 0) {
        perror("无法打开 address.txt 文件");
        return -1;
    }

    char line[256];
    if (fgets(line, sizeof(line), file) == NULL) {
        if (feof(file)) {
            printf("address.txt 文件为空\n");
        }
        else if (ferror(file)) {
            perror("读取 address.txt 文件时出错");
        }
        fclose(file);
        return -1;
    }

    // 查找第一个冒号
    char* colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("address.txt 文件第一行未找到冒号\n");
        return -1;
    }

    // 提取冒号后面的地址
    char* addrStart = colonPos + 1;

    // 去除换行符
    char* newline = strchr(addrStart, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    // 复制地址到传入的字符数组
    if (strlen(addrStart) >= size) {
        fclose(file);
        printf("地址过长，超出缓冲区大小\n");
        return -1;
    }
    err = strcpy_s(address, size, addrStart);  // 使用 strcpy_s 替代 strcpy
    if (err != 0) {
        fclose(file);
        printf("字符串复制失败\n");
        return -1;
    }

    fclose(file);
    return 0;
}

// 执行系统命令
void executeCommand(const char* command) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // 将多字节字符串转换为宽字符字符串
    int wideLen = MultiByteToWideChar(CP_ACP, 0, command, -1, NULL, 0);
    std::wstring wideCommand(wideLen, L'\0');
    MultiByteToWideChar(CP_ACP, 0, command, -1, &wideCommand[0], wideLen);

    // 创建新进程执行命令
    if (!CreateProcess(NULL, &wideCommand[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // 获取错误代码
        DWORD errorCode = GetLastError();
        std::cerr << "执行命令 " << command << " 失败，错误代码: " << errorCode << std::endl;
        return;
    }

    // 等待进程结束
    WaitForSingleObject(pi.hProcess, INFINITE);

    // 获取进程退出代码
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    if (exitCode != 0) {
        std::cerr << "命令 " << command << " 执行失败，退出代码: " << exitCode << std::endl;
    }

    // 关闭进程和线程句柄
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

// 检查模拟器是否连接成功
int isEmulatorConnected(const char* adbPath, const char* connectAddr) {
    char devicesCommand[256];
    // 拼接 adb devices 命令
    snprintf(devicesCommand, sizeof(devicesCommand), "\"%s\" devices", adbPath);

    // 执行命令并获取输出
    std::string output = executeCommandAndGetOutput(devicesCommand);

    std::istringstream iss(output);
    std::string line;
    int connected = 0;
    while (std::getline(iss, line)) {
        // 分割字符串获取设备地址和状态
        size_t pos = line.find('\t');
        if (pos != std::string::npos) {
            std::string addr = line.substr(0, pos);
            std::string status = line.substr(pos + 1);
            if (addr == connectAddr && status == "device") {
                connected = 1;
                break;
            }
        }
    }
    return connected;
}

// 连接到模拟器
// adb 连接设备的函数
void adb_connect(const char* adbPath, const char* connectAddr) {
    char command[1024];
    // 拼接完整的 ADB 连接命令
    snprintf(command, sizeof(command), "\"%s\" connect %s", adbPath, connectAddr);
    executeCommandAndGetOutput(command);
}

// 从文件中读取地址
int readAddressesFromFile1(const char* filename, char* adbPath, size_t adbPathSize, char* connectAddr, size_t connectAddrSize) {
    FILE* file;
    // 使用 fopen_s 替代 fopen
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("无法打开文件");
        return -1;
    }

    char line[256];
    // 跳过第一行
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("文件只有 0 行内容\n");
        return -1;
    }

    // 读取第二行（adb 地址）
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("文件只有 1 行内容\n");
        return -1;
    }
    char* colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("第二行未找到冒号\n");
        return -1;
    }
    const char* adbAddrStart = colonPos + 1;
    const char* newline = strchr(adbAddrStart, '\n');
    if (newline != NULL) {
        char* non_const_addrStart = (char*)adbAddrStart;
        non_const_addrStart[newline - adbAddrStart] = '\0';
    }
    if (strlen(adbAddrStart) >= adbPathSize) {
        fclose(file);
        printf("adb 地址过长，超出缓冲区大小\n");
        return -1;
    }
    // 使用 strcpy_s 替代 strcpy
    err = strcpy_s(adbPath, adbPathSize, adbAddrStart);
    if (err != 0) {
        fclose(file);
        printf("复制 adb 地址失败\n");
        return -1;
    }

    // 读取第三行（连接地址）
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("文件只有 2 行内容\n");
        return -1;
    }
    colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("第三行未找到冒号\n");
        return -1;
    }
    const char* connectAddrStart = colonPos + 1;
    newline = strchr(connectAddrStart, '\n');
    if (newline != NULL) {
        char* non_const_addrStart = (char*)connectAddrStart;
        non_const_addrStart[newline - connectAddrStart] = '\0';
    }
    if (strlen(connectAddrStart) >= connectAddrSize) {
        fclose(file);
        printf("连接地址过长，超出缓冲区大小\n");
        return -1;
    }
    // 使用 strcpy_s 替代 strcpy
    err = strcpy_s(connectAddr, connectAddrSize, connectAddrStart);
    if (err != 0) {
        fclose(file);
        printf("复制连接地址失败\n");
        return -1;
    }

    fclose(file);
    return 0;
}

// 执行命令并将输出重定向到文件
void runAdbCommandToFile(const char* command, const char* outputFile) {
    char fullCommand[512];
    snprintf(fullCommand, sizeof(fullCommand), "%s > %s", command, outputFile);
    int result = system(fullCommand);
    if (result != 0) {
        printf("执行 ADB 命令失败: %s\n", command);
    }
}

// 检查指定设备上的应用是否已启动
int isAppRunning(const char* deviceSerial, const char* packageName, const char* adbPath) {
    const char* outputFile = "ps_output.txt";
    char command[256];
    // 使用 findstr 替代 grep，并指定设备序列号
    snprintf(command, sizeof(command), "%s -s %s shell ps | findstr %s", adbPath, deviceSerial, packageName);
    runAdbCommandToFile(command, outputFile);

    FILE* file;
    errno_t err = fopen_s(&file, outputFile, "r");
    if (err != 0 || file == NULL) {
        printf("无法打开文件 %s\n", outputFile);
        return 0;
    }

    char buffer[1024];
    int isRunning = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, packageName) != NULL) {
            isRunning = 1;
            break;
        }
    }
    fclose(file);
    remove(outputFile);  // 删除临时文件
    return isRunning;
}

// 将 const char* 转换为 wchar_t*
wchar_t* charToWChar(const char* str) {
    int len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    if (len == 0) {
        return NULL;
    }
    wchar_t* wstr = (wchar_t*)malloc(len * sizeof(wchar_t));
    if (wstr == NULL) {
        return NULL;
    }
    MultiByteToWideChar(CP_ACP, 0, str, -1, wstr, len);
    return wstr;
}

// 读取指定行的内容
int readLineFromFile(const char* filename, int x,char* line) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");  // 使用 fopen_s 打开文件
    if (err != 0) {
        perror("无法打开文件");
        return -1;
    }

    int currentLine = 1;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (currentLine == x) {
            // 去除换行符
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }

            // 进行 UTF-8 到 GB2312 的转换
            auto gb2312_line = utf8_to_gb2312(line);
            if (gb2312_line) {
                err = strcpy_s(line, MAX_LINE_LENGTH, gb2312_line.get());
                if (err != 0) {
                    fclose(file);
                    return -4;  // 表示字符串复制失败
                } // 转换后的数据复制到 line
            }
            else {
                fclose(file);
                return -3;  // 表示编码转换失败
            }

            fclose(file);
            return 0;
        }
        currentLine++;
    }

    fclose(file);
    // 未找到指定行
    return -2;
}

void change(char arr[][MAX_LINE_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i][0] == '/' && arr[i][1] == '/') {
            arr[i][0] = '\0';
        }
    }
}
