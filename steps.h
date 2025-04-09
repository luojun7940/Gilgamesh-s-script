#ifndef STEPS_H
#define STEPS_H

#include "cmmonhfile.h"
#include"all.h"

//��ʼ����
void start(const char* device_serial, const char* adbPath);

//�ַ�
void crusade(const char* device_serial, const char* adbPath, const char* line);

//��ȡ����
void email(const char* device_serial, const char* adbPath, const char* line);

//ð��
void adventure(const char* device_serial, const char* adbPath, const char* line);

//�����ļ
void free_call(const char* device_serial, const char* adbPath, const char* line);

//̽��
void explore(const char* device_serial, const char* adbPath, const char* line);

//��פ
void dispatch(const char* device_serial, const char* adbPath, const char* line);

//��ȡAP
void receive_AP(const char* device_serial, const char* adbPath, const char* line);

//��ȡ����
void task(const char* device_serial, const char* adbPath, const char* line);

//�����ճ�
void alliance(const char* device_serial, const char* adbPath, const char* line);

//�
void activity(const char* device_serial, const char* adbPath, const char* line);

//�ȼ���������
void level_up(const char* device_serial, const char* adbPath, const char* line);

//������
void arena(const char* device_serial, const char* adbPath, const char* line);

#endif
