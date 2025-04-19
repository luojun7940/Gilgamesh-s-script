// all.cpp
#include "all.h"

#define MAX_LINE_LENGTH 256
#define MAX_NUMBERS 100

// ͼ��ȽϺ���������һ���ṹ��
MatchResult image_comparison(const char* device_serial, const char* adbPath, const char* templateImagePath, double threshold) {
    MatchResult match = { -1, -1, -1 };  // ��ʼ���ṹ��

    // ��ģ������ȡ��ͼ����
    std::vector<unsigned char> screenshotData = getScreenshotFromEmulator(device_serial, adbPath);

    if (screenshotData.empty()) {
        std::cerr << "�޷���ģ������ȡ��ͼ" << std::endl;
        return match;
    }

    // �����ڴ��еĽ�ͼ����
    cv::Mat target = cv::imdecode(screenshotData, cv::IMREAD_COLOR);

    if (target.empty()) {
        std::cerr << "�޷������ͼ����" << std::endl;
        return match;
    }

    // ���ر��ص�ģ��ͼ��
    cv::Mat temp = cv::imread(templateImagePath, cv::IMREAD_COLOR);

    if (temp.empty()) {
        std::cout << "�޷�����ģ��ͼ���ļ�" << std::endl;
        return match;
    }

    // ���ģ���Ƿ����Ŀ��ͼ��
    if (temp.cols > target.cols || temp.rows > target.rows) {
        std::cout << "ģ��ߴ����Ŀ��ͼ��" << std::endl;
        return match;
    }

    // ת��Ϊ�Ҷ�ͼ��
    cv::Mat target_gray, temp_gray;
    cv::cvtColor(target, target_gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(temp, temp_gray, cv::COLOR_BGR2GRAY);

    // �����������
    cv::Mat result;
    int result_cols = target_gray.cols - temp_gray.cols + 1;
    int result_rows = target_gray.rows - temp_gray.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);

    // ִ��ģ��ƥ��
    cv::matchTemplate(target_gray, temp_gray, result, cv::TM_CCOEFF_NORMED);

    // Ѱ�����ƥ��λ��
    double min_val, max_val;
    cv::Point min_loc, max_loc;
    cv::minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

    // ������ֵ�ж��Ƿ��ҵ�ƥ����
    if (max_val >= threshold) {
        //// ���ӻ����
        //cv::rectangle(target, max_loc, cv::Point(max_loc.x + temp.cols, max_loc.y + temp.rows), cv::Scalar(255, 0, 0), 2);
        //cv::imshow("Result", target);
        //cv::waitKey(0);

        match.x = max_loc.x;
        match.y = max_loc.y;
        match.status = 0;  // ��ʾƥ��ɹ�
    }
    else {
        std::cout << "δ�ҵ�����Ҫ���ƥ����" << std::endl;
    }

    return match;
}

// ��ģ������ȡ��ͼ���ڴ�
std::vector<unsigned char> getScreenshotFromEmulator(const char* device_serial, const char* adbPath) {
    // ��� adbPath �� device_serial �Ƿ���Ч
    if (adbPath == nullptr || device_serial == nullptr) {
        std::cerr << "adbPath �� device_serial Ϊ��" << std::endl;
        return {};
    }

    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;
    saAttr.lpSecurityDescriptor = NULL;

    HANDLE hChildStd_OUT_Rd = NULL, hChildStd_OUT_Wr = NULL;
    if (!CreatePipe(&hChildStd_OUT_Rd, &hChildStd_OUT_Wr, &saAttr, 0)) {
        std::cerr << "�����ܵ�ʧ��" << std::endl;
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

    // ������豸���кŵ� adb ����
    std::string command = std::string(adbPath) + " -s ";
    command += device_serial;
    command += " exec-out screencap -p";
    //std::cout << "command=" << command <<"\n\n"<< std::endl;

    int wideLen = MultiByteToWideChar(CP_ACP, 0, command.c_str(), -1, NULL, 0);
    auto wideCommand = std::make_unique<wchar_t[]>(wideLen);
    MultiByteToWideChar(CP_ACP, 0, command.c_str(), -1, wideCommand.get(), wideLen);

    if (!CreateProcess(NULL, wideCommand.get(), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        // ��ȡ�������
        DWORD errorCode = GetLastError();
        std::cerr << "��������ʧ�ܣ��������: " << errorCode << std::endl;
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

// ���ڴ��вü�ͼ��
cv::Mat cropImageInMemory(const cv::Mat& image, int x, int y, int width, int height) {
    cv::Rect roi(x, y, width, height);
    return image(roi).clone();
}

// UTF-8 ת GB2312
std::unique_ptr<char[]> utf8_to_gb2312(const char* utf8_str) {
    // �ȼ��� UTF-8 ת��Ϊ���ַ��ĳ���
    int wide_len = MultiByteToWideChar(CP_UTF8, 0, utf8_str, -1, NULL, 0);
    if (wide_len == 0) {
        return nullptr;
    }
    // ������ַ�����
    auto wide_str = std::make_unique<wchar_t[]>(wide_len);
    // ���� UTF-8 �����ַ���ת��
    MultiByteToWideChar(CP_UTF8, 0, utf8_str, -1, wide_str.get(), wide_len);

    // ������ַ�ת��Ϊ GB2312 �ĳ���
    int gb2312_len = WideCharToMultiByte(CP_ACP, 0, wide_str.get(), -1, NULL, 0, NULL, NULL);
    if (gb2312_len == 0) {
        return nullptr;
    }
    // ���� GB2312 �ַ�����
    auto gb2312_str = std::make_unique<char[]>(gb2312_len);
    // ���п��ַ��� GB2312 ��ת��
    WideCharToMultiByte(CP_ACP, 0, wide_str.get(), -1, gb2312_str.get(), gb2312_len, NULL, NULL);

    return gb2312_str;
}

// OCR ʶ���ڴ��е�ͼ��
std::string performOCR(const cv::Mat& image) {
    auto api = std::make_unique<TessBaseAPI>();
    if (api->Init(NULL, "chi_sim")) {
        std::cerr << "�޷���ʼ�� Tesseract" << std::endl;
        return "";
    }

    // ת��Ϊ 8 λ�Ҷ�ͼ��
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // ��ͼ�����Ϊ PNG �ڴ���
    std::vector<uchar> pngBuffer;
    if (!cv::imencode(".png", grayImage, pngBuffer)) {
        std::cerr << "ͼ�����ʧ��" << std::endl;
        return "";
    }

    // ���ڴ��ж�ȡ PNG ���ݵ� Pix
    Pix* pix = pixReadMem(pngBuffer.data(), pngBuffer.size());
    if (!pix) {
        std::cerr << "�޷���ȡ Pix ͼ��" << std::endl;
        return "";
    }
    auto pixDeleter = [](Pix* p) { pixDestroy(&p); };
    std::unique_ptr<Pix, decltype(pixDeleter)> uniquePix(pix, pixDeleter);

    api->SetImage(uniquePix.get());
    char* outText = api->GetUTF8Text();
    auto outTextDeleter = [](char* p) { delete[] p; };
    std::unique_ptr<char, decltype(outTextDeleter)> uniqueOutText(outText, outTextDeleter);

    std::string utf8Result(uniqueOutText.get() ? uniqueOutText.get() : "");

    // �� UTF-8 ����ת��Ϊ GB2312
    auto gb2312Result = utf8_to_gb2312(utf8Result.c_str());
    std::string finalResult;
    if (gb2312Result) {
        finalResult = gb2312Result.get();
    }
    else {
        std::cerr << "UTF-8 ת GB2312 ʧ��" << std::endl;
    }

    // �Ƴ��ַ����еĿո�
    finalResult.erase(std::remove(finalResult.begin(), finalResult.end(), ' '), finalResult.end());

    return finalResult;
}

// ��ָ���豸��ȡ��ͼ���ü�
cv::Mat adb_screenshot_and_crop(const char* device_serial,const char* adbPath, int x, int y, int width, int height) {
    std::vector<unsigned char> screenshotData = getScreenshotFromEmulator(device_serial,adbPath);
    if (screenshotData.empty()) {
        return cv::Mat();
    }

    cv::Mat image = cv::imdecode(screenshotData, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "�޷������ͼ����" << std::endl;
        return cv::Mat();
    }

    return cropImageInMemory(image, x, y, width, height);
}

// �Բü����ͼ����� OCR ʶ��
std::unique_ptr<char[]> ocrImage(const cv::Mat& croppedImage) {
    if (croppedImage.empty()) {
        std::cerr << "�ü����ͼ��Ϊ��" << std::endl;
        return nullptr;
    }

    std::string result = performOCR(croppedImage);
    if (result.empty()) {
        return nullptr;
    }

    auto resultStr = std::make_unique<char[]>(result.length() + 1);
    // ʹ�ð�ȫ�� strcpy_s
    if (strcpy_s(resultStr.get(), result.length() + 1, result.c_str()) != 0) {
        std::cerr << "�ַ�������ʧ��" << std::endl;
        return nullptr;
    }
    return resultStr;
}

// ִ������������
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

// ��������ı��Ƿ�����ȡ�ı����Ӵ�
int isSubstring(const char* extractedText, const char* sampleText) {
    if (strstr(extractedText, sampleText) != NULL) {
        return 1;
    }
    return 0;
}

// ִ������ĺ���
void runAdbCommand(const char* command) {
    int result = system(command);
    if (result != 0) {
        std::cerr << "ִ�� ADB ����ʧ��: " << command << std::endl;
    }
}

// ģ�ⴥ�����²���
void adbTouchDown(const char* device_serial, const char* adbPath, int x, int y) {
    char command[256];
    // ƴ�Ӵ��� ADB ����·��������
    snprintf(command, sizeof(command), "\"%s\" -s %s shell input tap %d %d", adbPath, device_serial, x, y);
    runAdbCommand(command);
}

// ģ�ⴥ���ƶ�����
void adbTouchMove(const char* device_serial, const char* adbPath, int x1, int y1, int x2, int y2, int duration) {
    char command[256];
    // ƴ�Ӵ��� ADB ����·��������
    snprintf(command, sizeof(command), "\"%s\" -s %s shell input swipe %d %d %d %d %d", adbPath, device_serial, x1, y1, x2, y2, duration);
    runAdbCommand(command);
}

// �Զ��庯�� read����ȡ Settings.txt �ļ��е����ֵ�����
int readtxt(int* numbers) {
    const char* filename = ".\\Settings.txt";
    FILE* file;
    errno_t err;

    // ������׷��ģʽ���ļ�������ļ��������򴴽���
    err = fopen_s(&file, filename, "a");
    if (err != 0) {
        perror("�޷���������ļ�");
        return -1;
    }
    fclose(file);

    // ������ֻ��ģʽ���ļ�
    err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("�޷����ļ�");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL && count < MAX_NUMBERS) {
        // ��������ǰ�ķ������ַ�
        char* num_start = line;
        while (*num_start != '\0' && (*num_start < '0' || *num_start > '9')) {
            num_start++;
        }

        // ����ҵ����֣�����ת��Ϊ�������洢������
        if (*num_start != '\0') {
            numbers[count++] = atoi(num_start);
        }
    }

    fclose(file);
    return count;
}

// �� address.txt �ļ��ж�ȡ��ַ
int readAddressFromFile(char* address, size_t size) {
    FILE* file;
    errno_t err = fopen_s(&file, ".\\address.txt", "r");  // ʹ�� fopen_s ��� fopen
    if (err != 0) {
        perror("�޷��� address.txt �ļ�");
        return -1;
    }

    char line[256];
    if (fgets(line, sizeof(line), file) == NULL) {
        if (feof(file)) {
            printf("address.txt �ļ�Ϊ��\n");
        }
        else if (ferror(file)) {
            perror("��ȡ address.txt �ļ�ʱ����");
        }
        fclose(file);
        return -1;
    }

    // ���ҵ�һ��ð��
    char* colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("address.txt �ļ���һ��δ�ҵ�ð��\n");
        return -1;
    }

    // ��ȡð�ź���ĵ�ַ
    char* addrStart = colonPos + 1;

    // ȥ�����з�
    char* newline = strchr(addrStart, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }

    // ���Ƶ�ַ��������ַ�����
    if (strlen(addrStart) >= size) {
        fclose(file);
        printf("��ַ������������������С\n");
        return -1;
    }
    err = strcpy_s(address, size, addrStart);  // ʹ�� strcpy_s ��� strcpy
    if (err != 0) {
        fclose(file);
        printf("�ַ�������ʧ��\n");
        return -1;
    }

    fclose(file);
    return 0;
}

// ִ��ϵͳ����
void executeCommand(const char* command) {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // �����ֽ��ַ���ת��Ϊ���ַ��ַ���
    int wideLen = MultiByteToWideChar(CP_ACP, 0, command, -1, NULL, 0);
    std::wstring wideCommand(wideLen, L'\0');
    MultiByteToWideChar(CP_ACP, 0, command, -1, &wideCommand[0], wideLen);

    // �����½���ִ������
    if (!CreateProcess(NULL, &wideCommand[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        // ��ȡ�������
        DWORD errorCode = GetLastError();
        std::cerr << "ִ������ " << command << " ʧ�ܣ��������: " << errorCode << std::endl;
        return;
    }

    // �ȴ����̽���
    WaitForSingleObject(pi.hProcess, INFINITE);

    // ��ȡ�����˳�����
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    if (exitCode != 0) {
        std::cerr << "���� " << command << " ִ��ʧ�ܣ��˳�����: " << exitCode << std::endl;
    }

    // �رս��̺��߳̾��
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

// ���ģ�����Ƿ����ӳɹ�
int isEmulatorConnected(const char* adbPath, const char* connectAddr) {
    char devicesCommand[256];
    // ƴ�� adb devices ����
    snprintf(devicesCommand, sizeof(devicesCommand), "\"%s\" devices", adbPath);

    // ִ�������ȡ���
    std::string output = executeCommandAndGetOutput(devicesCommand);

    std::istringstream iss(output);
    std::string line;
    int connected = 0;
    while (std::getline(iss, line)) {
        // �ָ��ַ�����ȡ�豸��ַ��״̬
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

// ���ӵ�ģ����
// adb �����豸�ĺ���
void adb_connect(const char* adbPath, const char* connectAddr) {
    char command[1024];
    // ƴ�������� ADB ��������
    snprintf(command, sizeof(command), "\"%s\" connect %s", adbPath, connectAddr);
    executeCommandAndGetOutput(command);
}

// ���ļ��ж�ȡ��ַ
int readAddressesFromFile1(const char* filename, char* adbPath, size_t adbPathSize, char* connectAddr, size_t connectAddrSize) {
    FILE* file;
    // ʹ�� fopen_s ��� fopen
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0) {
        perror("�޷����ļ�");
        return -1;
    }

    char line[256];
    // ������һ��
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("�ļ�ֻ�� 0 ������\n");
        return -1;
    }

    // ��ȡ�ڶ��У�adb ��ַ��
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("�ļ�ֻ�� 1 ������\n");
        return -1;
    }
    char* colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("�ڶ���δ�ҵ�ð��\n");
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
        printf("adb ��ַ������������������С\n");
        return -1;
    }
    // ʹ�� strcpy_s ��� strcpy
    err = strcpy_s(adbPath, adbPathSize, adbAddrStart);
    if (err != 0) {
        fclose(file);
        printf("���� adb ��ַʧ��\n");
        return -1;
    }

    // ��ȡ�����У����ӵ�ַ��
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        printf("�ļ�ֻ�� 2 ������\n");
        return -1;
    }
    colonPos = strchr(line, ':');
    if (colonPos == NULL) {
        fclose(file);
        printf("������δ�ҵ�ð��\n");
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
        printf("���ӵ�ַ������������������С\n");
        return -1;
    }
    // ʹ�� strcpy_s ��� strcpy
    err = strcpy_s(connectAddr, connectAddrSize, connectAddrStart);
    if (err != 0) {
        fclose(file);
        printf("�������ӵ�ַʧ��\n");
        return -1;
    }

    fclose(file);
    return 0;
}

// ִ�����������ض����ļ�
void runAdbCommandToFile(const char* command, const char* outputFile) {
    char fullCommand[512];
    snprintf(fullCommand, sizeof(fullCommand), "%s > %s", command, outputFile);
    int result = system(fullCommand);
    if (result != 0) {
        printf("ִ�� ADB ����ʧ��: %s\n", command);
    }
}

// ���ָ���豸�ϵ�Ӧ���Ƿ�������
int isAppRunning(const char* deviceSerial, const char* packageName, const char* adbPath) {
    const char* outputFile = "ps_output.txt";
    char command[256];
    // ʹ�� findstr ��� grep����ָ���豸���к�
    snprintf(command, sizeof(command), "%s -s %s shell ps | findstr %s", adbPath, deviceSerial, packageName);
    runAdbCommandToFile(command, outputFile);

    FILE* file;
    errno_t err = fopen_s(&file, outputFile, "r");
    if (err != 0 || file == NULL) {
        printf("�޷����ļ� %s\n", outputFile);
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
    remove(outputFile);  // ɾ����ʱ�ļ�
    return isRunning;
}

// �� const char* ת��Ϊ wchar_t*
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

// ��ȡָ���е�����
int readLineFromFile(const char* filename, int x,char* line) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");  // ʹ�� fopen_s ���ļ�
    if (err != 0) {
        perror("�޷����ļ�");
        return -1;
    }

    int currentLine = 1;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (currentLine == x) {
            // ȥ�����з�
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }

            // ���� UTF-8 �� GB2312 ��ת��
            auto gb2312_line = utf8_to_gb2312(line);
            if (gb2312_line) {
                err = strcpy_s(line, MAX_LINE_LENGTH, gb2312_line.get());
                if (err != 0) {
                    fclose(file);
                    return -4;  // ��ʾ�ַ�������ʧ��
                } // ת��������ݸ��Ƶ� line
            }
            else {
                fclose(file);
                return -3;  // ��ʾ����ת��ʧ��
            }

            fclose(file);
            return 0;
        }
        currentLine++;
    }

    fclose(file);
    // δ�ҵ�ָ����
    return -2;
}

void change(char arr[][MAX_LINE_LENGTH], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i][0] == '/' && arr[i][1] == '/') {
            arr[i][0] = '\0';
        }
    }
}
