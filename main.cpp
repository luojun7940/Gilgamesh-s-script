#include"cmmonhfile.h"
#include"all.h"
#include"steps.h"

int main() {
    std::cout << "这是一个简单的开发中的金闪闪脚本测试\n\n鼠鼠会不定时更新QAQ，源码已发GitHub。\n\n" << std::endl;
    // 输出读取到的设置
    char line[50][MAX_LINE_LENGTH] = { 0 };
    for (int i = 0; i < 50; i++) {
        int result = readLineFromFile("Settings.txt", i, line[i]);
    }

    int size = sizeof(line) / sizeof(line[0]);
    change(line, size);

    printf("读取到设置：\n");
    for (int i = 0;i < 50;i++) {
        if (line[i][0] != '\0') {
            printf("%d、%s\n",i, line[i]);
        }
    }
    std::cout << "\n\n" << std::endl;

    //启动mumu模拟器
    char address[256];
    if (readAddressFromFile(address, sizeof(address)) != 0) {
        return -1;
    }
    printf("%s\n\n", address);
    // 打开程序
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));


    if (!CreateProcessA(NULL, (LPSTR)address, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        printf("CreateProcessA failed (%d).\n", GetLastError());
        return 1;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);


    Sleep(1000);


    //连接adb
    char adbPath[MAX_PATH_LENGTH];
    char connectAddr[MAX_PATH_LENGTH];

    // 从文件中读取地址
    if (readAddressesFromFile1(".\\address.txt", adbPath, sizeof(adbPath), connectAddr, sizeof(connectAddr)) != 0) {
        return -1;
    }
    printf("%s\n\n", adbPath);
    adb_connect(adbPath, connectAddr);
    for (int i = 0; i < 20; i++) {
        // 检查是否连接成功
        if (isEmulatorConnected(adbPath, connectAddr)) {
            printf("成功连接到模拟器: %s\n\n", connectAddr);
            break;
        }
        else {
            if (i > 10) {
                printf("未能连接到模拟器: %s\n正在重新尝试......\n\n", connectAddr);
                // 调用 adb_connect 函数
                adb_connect(adbPath, connectAddr);
                Sleep(3000);
            }
        }
    }


    Sleep(1000);


    const char* packageName = "com.fy.rebgil";
    const char* activityName = "com.unity3d.player.UnityPlayerActivity";
    char command[256];
    // 拼接带有 -s 选项的 ADB 命令，用于指定设备
    snprintf(command, sizeof(command), "%s -s %s shell am start -n %s/%s", adbPath, connectAddr, packageName, activityName);
    execute_command(command);

    for (int j = 0; j < 10; j++, Sleep(500)) {
        // 检查应用是否已启动
        if (isAppRunning(connectAddr, packageName, adbPath)) {
            printf("应用已成功启动。\n\n");
            break;
        }
        else {
            if (j > 3) {
                printf("应用未成功启动。\n\n");
                // 调用 ADB 命令
                runAdbCommand(command);
            }
        }
    }

    Sleep(1000);

    std::cout << "开始脚本\n\n" << std::endl;

    start(connectAddr, adbPath);

    const char* checkpoint[11] = {"派驻","邮箱","冒险","招募","探索","讨伐","领取AP","任务","联盟","活动","等级提升"};
    for (int i = 0;i++ < 50;Sleep(50)) {
        for (int j = 0;j < 11;j++) {
            if (isSubstring(line[i], checkpoint[j])) {
                switch (j) {
                case 0:dispatch(connectAddr, adbPath, line[i]);
                    break;
                case 1:email(connectAddr, adbPath, line[i]);
                    break;
                case 2:adventure(connectAddr, adbPath, line[i]);
                    break;
                case 3:free_call(connectAddr, adbPath, line[i]);
                    break;
                case 4:explore(connectAddr, adbPath, line[i]);
                    break;
                case 5:crusade(connectAddr, adbPath, line[i]);
                    break;
                case 6:receive_AP(connectAddr, adbPath, line[i]);
                    break;
                case 7:task(connectAddr, adbPath, line[i]);
                    break;
                case 8:alliance(connectAddr, adbPath, line[i]);
                    break;
                case 9:activity(connectAddr, adbPath, line[i]);
                    break;
                case 10:level_up(connectAddr, adbPath, line[i]);
                    break;
                }
                break;
            }
        }
    }
    std::cout << "脚本结束\n\n" << std::endl;
    int xxx = getchar();
	return 0;
}