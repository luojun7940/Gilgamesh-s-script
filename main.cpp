#include"cmmonhfile.h"
#include"all.h"
#include"steps.h"

int main() {
    std::cout << "����һ���򵥵Ŀ����еĽ������ű�����\n\n����᲻��ʱ����QAQ��Դ���ѷ�GitHub��\n\n" << std::endl;
    // �����ȡ��������
    char line[50][MAX_LINE_LENGTH] = { 0 };
    for (int i = 0; i < 50; i++) {
        int result = readLineFromFile("Settings.txt", i, line[i]);
    }

    int size = sizeof(line) / sizeof(line[0]);
    change(line, size);

    printf("��ȡ�����ã�\n");
    for (int i = 0;i < 50;i++) {
        if (line[i][0] != '\0') {
            printf("%d��%s\n",i, line[i]);
        }
    }
    std::cout << "\n\n" << std::endl;

    //����mumuģ����
    char address[256];
    if (readAddressFromFile(address, sizeof(address)) != 0) {
        return -1;
    }
    printf("%s\n\n", address);
    // �򿪳���
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


    //����adb
    char adbPath[MAX_PATH_LENGTH];
    char connectAddr[MAX_PATH_LENGTH];

    // ���ļ��ж�ȡ��ַ
    if (readAddressesFromFile1(".\\address.txt", adbPath, sizeof(adbPath), connectAddr, sizeof(connectAddr)) != 0) {
        return -1;
    }
    printf("%s\n\n", adbPath);
    adb_connect(adbPath, connectAddr);
    for (int i = 0; i < 20; i++) {
        // ����Ƿ����ӳɹ�
        if (isEmulatorConnected(adbPath, connectAddr)) {
            printf("�ɹ����ӵ�ģ����: %s\n\n", connectAddr);
            break;
        }
        else {
            if (i > 10) {
                printf("δ�����ӵ�ģ����: %s\n�������³���......\n\n", connectAddr);
                // ���� adb_connect ����
                adb_connect(adbPath, connectAddr);
                Sleep(3000);
            }
        }
    }


    Sleep(1000);


    const char* packageName = "com.fy.rebgil";
    const char* activityName = "com.unity3d.player.UnityPlayerActivity";
    char command[256];
    // ƴ�Ӵ��� -s ѡ��� ADB �������ָ���豸
    snprintf(command, sizeof(command), "%s -s %s shell am start -n %s/%s", adbPath, connectAddr, packageName, activityName);
    execute_command(command);

    for (int j = 0; j < 10; j++, Sleep(500)) {
        // ���Ӧ���Ƿ�������
        if (isAppRunning(connectAddr, packageName, adbPath)) {
            printf("Ӧ���ѳɹ�������\n\n");
            break;
        }
        else {
            if (j > 3) {
                printf("Ӧ��δ�ɹ�������\n\n");
                // ���� ADB ����
                runAdbCommand(command);
            }
        }
    }

    Sleep(1000);

    std::cout << "��ʼ�ű�\n\n" << std::endl;

    start(connectAddr, adbPath);

    const char* checkpoint[11] = {"��פ","����","ð��","��ļ","̽��","�ַ�","��ȡAP","����","����","�","�ȼ�����"};
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
    std::cout << "�ű�����\n\n" << std::endl;
    int xxx = getchar();
	return 0;
}