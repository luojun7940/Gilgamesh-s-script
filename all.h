// all.h
#ifndef ALL_H
#define ALL_H

#include "cmmonhfile.h"

// 常量定义
constexpr auto MAX_LINE_LENGTH = 256;
constexpr auto MAX_NUMBERS = 100;
constexpr auto MAX_PATH_LENGTH = 100;

constexpr auto startx = 0;
constexpr auto emailx = 1;
constexpr auto basex = 2;
constexpr auto sequential_challengex = 3;
constexpr auto activityx = 4;
constexpr auto crusadex = 5;
constexpr auto elementalsx = 6;
constexpr auto residual_strength = 7;
constexpr auto fightx = 8;
constexpr auto dailyx = 9;
constexpr auto mercenaryx = 10;
constexpr auto storex = 11;
constexpr auto daily_callx = 12;
constexpr auto friendship_shopx = 13;

// 定义一个结构体来存储匹配结果
struct MatchResult {
    int x;  // 匹配位置的 x 坐标
    int y;  // 匹配位置的 y 坐标
    int status;  // 匹配状态，0 表示成功，-1 表示失败
};

// 图像比较函数，返回一个结构体
MatchResult image_comparison(const char* device_serial, const char* adbPath, const char* templateImagePath, double threshold);

// 从模拟器获取截图到内存
std::vector<unsigned char> getScreenshotFromEmulator(const char* device_serial, const char* adbPath);

// 在内存中裁剪图像
cv::Mat cropImageInMemory(const cv::Mat& image, int x, int y, int width, int height);

// UTF-8 转 GB2312
std::unique_ptr<char[]> utf8_to_gb2312(const char* utf8_str);

// OCR 识别内存中的图像
std::string performOCR(const cv::Mat& image);

// 从指定设备获取截图并裁剪
cv::Mat adb_screenshot_and_crop(const char* device_serial, const char* adbPath, int x, int y, int width, int height);

// 对裁剪后的图像进行 OCR 识别
std::unique_ptr<char[]> ocrImage(const cv::Mat& croppedImage);

// 执行系统命令并检查返回状态
void execute_command(const char* command);

// 判断提取的文本是否包含样本文本的子串
int isSubstring(const char* extractedText, const char* sampleText);

// 执行 ADB 命令
void runAdbCommand(const char* command);

// 模拟点击按下操作
void adbTouchDown(const char* device_serial, const char* adbPath, int x, int y);

// 模拟滑动操作
void adbTouchMove(const char* device_serial, const char* adbPath, int x1, int y1, int x2, int y2, int duration);

// 自动读取 Settings.txt 文件中的数字值
int readtxt(int* numbers);

// 从 address.txt 文件中读取地址
int readAddressFromFile(char* address, size_t size);

// 执行系统命令
void executeCommand(const char* command);

// 连接到模拟器
void adb_connect(const char* adbPath, const char* connectAddr);

// 从文件中读取地址
int readAddressesFromFile1(const char* filename, char* adbPath, size_t adbPathSize, char* connectAddr, size_t connectAddrSize);

// 检查模拟器是否连接成功
int isEmulatorConnected(const char* adbPath, const char* connectAddr);

// 检查应用是否正在运行
int isAppRunning(const char* deviceSerial, const char* packageName, const char* adbPath);

// 执行命令并将输出结果保存到文件
void runAdbCommandToFile(const char* command, const char* outputFile);

// 将 const char* 转换为 wchar_t*
wchar_t* charToWChar(const char* str);

// 读取指定行的内容
int readLineFromFile(const char* filename, int x, char* line);

//将第一二个字符为“//”的函数变为空
void change(char arr[][MAX_LINE_LENGTH], int size);

#endif