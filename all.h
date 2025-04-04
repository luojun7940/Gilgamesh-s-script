// all.h
#ifndef ALL_H
#define ALL_H

#include "cmmonhfile.h"

// ��������
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

// ����һ���ṹ�����洢ƥ����
struct MatchResult {
    int x;  // ƥ��λ�õ� x ����
    int y;  // ƥ��λ�õ� y ����
    int status;  // ƥ��״̬��0 ��ʾ�ɹ���-1 ��ʾʧ��
};

// ͼ��ȽϺ���������һ���ṹ��
MatchResult image_comparison(const char* device_serial, const char* adbPath, const char* templateImagePath, double threshold);

// ��ģ������ȡ��ͼ���ڴ�
std::vector<unsigned char> getScreenshotFromEmulator(const char* device_serial, const char* adbPath);

// ���ڴ��вü�ͼ��
cv::Mat cropImageInMemory(const cv::Mat& image, int x, int y, int width, int height);

// UTF-8 ת GB2312
std::unique_ptr<char[]> utf8_to_gb2312(const char* utf8_str);

// OCR ʶ���ڴ��е�ͼ��
std::string performOCR(const cv::Mat& image);

// ��ָ���豸��ȡ��ͼ���ü�
cv::Mat adb_screenshot_and_crop(const char* device_serial, const char* adbPath, int x, int y, int width, int height);

// �Բü����ͼ����� OCR ʶ��
std::unique_ptr<char[]> ocrImage(const cv::Mat& croppedImage);

// ִ��ϵͳ�����鷵��״̬
void execute_command(const char* command);

// �ж���ȡ���ı��Ƿ���������ı����Ӵ�
int isSubstring(const char* extractedText, const char* sampleText);

// ִ�� ADB ����
void runAdbCommand(const char* command);

// ģ�������²���
void adbTouchDown(const char* device_serial, const char* adbPath, int x, int y);

// ģ�⻬������
void adbTouchMove(const char* device_serial, const char* adbPath, int x1, int y1, int x2, int y2, int duration);

// �Զ���ȡ Settings.txt �ļ��е�����ֵ
int readtxt(int* numbers);

// �� address.txt �ļ��ж�ȡ��ַ
int readAddressFromFile(char* address, size_t size);

// ִ��ϵͳ����
void executeCommand(const char* command);

// ���ӵ�ģ����
void adb_connect(const char* adbPath, const char* connectAddr);

// ���ļ��ж�ȡ��ַ
int readAddressesFromFile1(const char* filename, char* adbPath, size_t adbPathSize, char* connectAddr, size_t connectAddrSize);

// ���ģ�����Ƿ����ӳɹ�
int isEmulatorConnected(const char* adbPath, const char* connectAddr);

// ���Ӧ���Ƿ���������
int isAppRunning(const char* deviceSerial, const char* packageName, const char* adbPath);

// ִ����������������浽�ļ�
void runAdbCommandToFile(const char* command, const char* outputFile);

// �� const char* ת��Ϊ wchar_t*
wchar_t* charToWChar(const char* str);

// ��ȡָ���е�����
int readLineFromFile(const char* filename, int x, char* line);

//����һ�����ַ�Ϊ��//���ĺ�����Ϊ��
void change(char arr[][MAX_LINE_LENGTH], int size);

#endif