#ifndef STEPS_H
#define STEPS_H

#include "cmmonhfile.h"
#include"all.h"

//开始启动
void start(const char* device_serial, const char* adbPath);

//讨伐
void crusade(const char* device_serial, const char* adbPath, const char* line);

//领取邮箱
void email(const char* device_serial, const char* adbPath, const char* line);

//冒险
void adventure(const char* device_serial, const char* adbPath, const char* line);

//免费招募
void free_call(const char* device_serial, const char* adbPath, const char* line);

//探索
void explore(const char* device_serial, const char* adbPath, const char* line);

//派驻
void dispatch(const char* device_serial, const char* adbPath, const char* line);

//领取AP
void receive_AP(const char* device_serial, const char* adbPath, const char* line);

//领取任务
void task(const char* device_serial, const char* adbPath, const char* line);

//联盟日常
void alliance(const char* device_serial, const char* adbPath, const char* line);

//活动
void activity(const char* device_serial, const char* adbPath, const char* line);

//等级提升任务
void level_up(const char* device_serial, const char* adbPath, const char* line);

//竞技场
void arena(const char* device_serial, const char* adbPath, const char* line);

#endif
