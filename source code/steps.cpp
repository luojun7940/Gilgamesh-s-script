#include"steps.h"

void start(const char* device_serial, const char* adbPath) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	for (;;Sleep(500)) {
		adbTouchDown(device_serial, adbPath, 1 + rand() % 20, 1 + rand() % 20);

		match = image_comparison(device_serial, adbPath, ".\\image\\start\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 5, match.y + rand() % 5);
		}
		else {
			Sleep(500);
			match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				break;
			}
		}
	}
	std::cout << "开始\n\n" << std::endl;
}

void crusade(const char* device_serial, const char* adbPath,const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "讨伐\n\n" << std::endl;
	for (int i=0;i++<10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\讨伐战.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 5, match.y + rand() % 5);
			Sleep(5000);
			break;
		}
	}

	//选择目标
	std::cout << "选择目标\n\n" << std::endl;
	const char* checkpoint[2] = { "常驻","活动" };
	for (int i = 0;i < 2;i++) {
		if (isSubstring(line, checkpoint[i])) {
			switch (i) {
			case 0:adbTouchDown(device_serial, adbPath, 104 + rand() % 10, 104 + rand() % 10);
				break;
			case 1:adbTouchDown(device_serial, adbPath, 262 + rand() % 10, 104 + rand() % 10);
				break;
			}
		}
	}
	Sleep(3000);

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\筛选.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			//对象
			const char* checkpoint1[3] = { "全部","世界","联盟"};
			//能力
			const char* checkpoint2[7] = { "全部","火","水" ,"木","光","暗","混沌"};
			//难度
			const char* checkpoint3[4] = { "全部","NORMAL","VERY HARD","HARD"};
			for (int j = 0;j < 3;j++) {
				if (isSubstring(line, checkpoint1[j])) {
					switch (j) {
					case 0:adbTouchDown(device_serial, adbPath, 146 + rand() % 10, 198 + rand() % 10);break;

					case 1:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\世界.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 2:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\联盟.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;
					default:break;
					}
					break;
				}
			}
			Sleep(1000);
			for (int j = 0;j < 7;j++) {
				if (isSubstring(line, checkpoint2[j])) {
					switch (j) {
					case 0:adbTouchDown(device_serial, adbPath, 88 + rand() % 10, 309 + rand() % 10);

					case 1:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\火.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 2:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\水.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 3:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\木.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 4:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\光.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 5:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\暗.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 6:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\混沌.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					default:break;
					}
					break;
				}
			}
			Sleep(1000);
			for (int j = 0;j < 4;j++) {
				if (isSubstring(line, checkpoint3[j])) {
					switch (j) {
					case 0:adbTouchDown(device_serial, adbPath, 97 + rand() % 10, 437 + rand() % 10);break;

					case 1:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\NORMAL.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 2:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\VERY HARD.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;
					case 3:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\HARD.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;
					default:break;
					}
					break;
				}
			}
			Sleep(1000);
			for (int j = 0;j < 10;j++) {
				match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\确定.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					break;
				}
			}
			break;
		}
	}
	Sleep(1000);

	//开始战斗
	for (;;Sleep(500)) {
	start:int x = 0,y = 0;
		std::cout << "选择满血\n\n" << std::endl;
		if (isSubstring(line, "满血")) {
			for (;;Sleep(1000)) {
				match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\满血.png", 0.98);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 378 + rand() % 20, match.y + 26 + rand() % 20);
					Sleep(1000);
					x = match.x;
					y = match.y;
					break;
				}
				else {
					adbTouchDown(device_serial, adbPath, 1148 + rand() % 10, 664 + rand() % 10);
					Sleep(1000);
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\讨伐战.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					}
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\救援清单.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					}
					Sleep(1000);

					//选择目标
					const char* checkpoint[2] = { "常驻","活动" };
					for (int i = 0;i < 2;i++) {
						if (isSubstring(line, checkpoint[i])) {
							switch (i) {
							case 0:adbTouchDown(device_serial, adbPath, 104 + rand() % 10, 104 + rand() % 10);
								break;
							case 1:adbTouchDown(device_serial, adbPath, 262 + rand() % 10, 104 + rand() % 10);
								break;
							}
						}
					}
					Sleep(1000);
				}
			}
		}
		else {
			adbTouchDown(device_serial, adbPath, 1130, 180);
			Sleep(1000);
		}

		std::cout << "开始战斗\n\n" << std::endl;
		for (int i = 0;i++ < 15;Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\挑战.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + 107 + rand() % 20, match.y + 27 + rand() % 20);
				Sleep(1000);
				break;
			}
			else {
				adbTouchDown(device_serial, adbPath, x + 378 + rand() % 20, y + 26 + rand() % 20);
			}
		}

		for (int i = 0;i++ < 15;Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\BP回复.png", threshold97);
			if (match.status == 0) {
				std::cout << "回复BP\n\n" << std::endl;
				if (isSubstring(line, "BP")) {
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\小BP.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + 300 + rand() % 20, match.y + rand() % 20);
						Sleep(1000);
						adbTouchDown(device_serial, adbPath, 820 + rand() % 20, 420 + rand() % 20);
						Sleep(500);
						adbTouchDown(device_serial, adbPath, 750 + rand() % 10, 560 + rand() % 10);
						Sleep(3000);
						adbTouchDown(device_serial, adbPath, 640 + rand() % 5, 660 + rand() % 5);
						Sleep(1000);
						adbTouchDown(device_serial, adbPath, 1144 + rand() % 5, 667 + rand() % 5);
						Sleep(2000);
						adbTouchDown(device_serial, adbPath, 646 + rand() % 5, 605 + rand() % 5);
						Sleep(1000);
						goto start;
					}
					else {
						match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\大BP.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + 300 + rand() % 20, match.y + rand() % 20);
							Sleep(1000);
							adbTouchDown(device_serial, adbPath, 750 + rand() % 10, 560 + rand() % 10);
							Sleep(3000);
							adbTouchDown(device_serial, adbPath, 640 + rand() % 5, 660 + rand() % 5);
							Sleep(1000);
							adbTouchDown(device_serial, adbPath, 1144 + rand() % 5, 667 + rand() % 5);
							Sleep(2000);
							adbTouchDown(device_serial, adbPath, 646 + rand() % 5, 605 + rand() % 5);
							Sleep(1000);
							goto start;
						}
						else {
							adbTouchDown(device_serial, adbPath, 640 + rand() % 5, 660 + rand() % 5);
							Sleep(1000);
							adbTouchDown(device_serial, adbPath, 1144 + rand() % 5, 667 + rand() % 5);
							Sleep(1000);
							return;
						}
					}
				}
				else {
					adbTouchDown(device_serial, adbPath, 640 + rand() % 5, 660 + rand() % 5);
					Sleep(1000);
					adbTouchDown(device_serial, adbPath, 1144 + rand() % 5, 667 + rand() % 5);
					Sleep(1000);
					return;
				}
			}
		}

		std::cout << "等待结束\n\n" << std::endl;
		for (;;Sleep(1000)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\点击画面结束.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
		}
		std::cout << "结束\n\n" << std::endl;
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "讨伐结束\n\n" << std::endl;
}

void email(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "领取邮箱\n\n" << std::endl;
	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\邮箱.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			break;
		}
		else {
			match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			}
		}
	}

	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\全部领取.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 1 + rand() % 20, 1 + rand() % 20);
			match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				std::cout << "领取邮箱结束\n\n" << std::endl;
				return;
			}
		}
	}
}

void adventure(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//冒险
	std::cout << "冒险\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\冒险.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//战备任务
	std::cout << "战备任务\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\战备任务.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\SKIP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\回地图.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//魔渊监狱
	std::cout << "魔渊监狱\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\魔渊监狱.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	const char* check[3] = { "难度1","难度2","难度3" };
	for (int i = 0;i < 3;i++) {
		if (isSubstring(line, check[i])){
			switch (i) {
			case 0:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\难度1.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(2000);
				}
				break;
			case 1:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\难度2.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(2000);
				}
				break;
			case 2:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\难度3.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(2000);
				}
				break;
			}
			break;
		}
		else {
			if (i == 2) {
				match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\难度3.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(500);
				}
				break;
			}
		}
	}

	//检查次数是否可用
	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			for (int i = 0;i++ < 5;Sleep(500)) {
				match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					Sleep(1000);
					return;
				}
			}
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\MAX.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\回地图.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//冒险结束
	std::cout << "冒险结束\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}
}

void free_call(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "免费招募\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\每日免费.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
		else {
			return;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\list.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\奴隶契约.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\一日.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + 70 + rand() % 20);
				Sleep(2000);
				for (int j = 0;j++ < 20;Sleep(1000)) {
					match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\点击画面结束.png", threshold90);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
						Sleep(2000);
						break;
					}
					else {
						adbTouchDown(device_serial, adbPath, 1 + rand() % 20, 1 + rand() % 20);
					}
				}
			}
			break;
		}
		else {
			adbTouchMove(device_serial, adbPath, 265, 582, 277, 104, 500);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\武器契约.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\一日.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + 70 + rand() % 20);
				Sleep(2000);
				for (int j = 0;j++ < 20;Sleep(1000)) {
					match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\点击画面结束.png", threshold90);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
						Sleep(2000);
						break;
					}
				}
			}
			break;
		}
		else {
			adbTouchMove(device_serial, adbPath, 265, 582, 277, 104, 500);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "免费招募结束\n\n" << std::endl;
}

void explore(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "探索\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\探索.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\一键领取.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\追加回数.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\explore\\MAX.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
				Sleep(2000);
				match = image_comparison(device_serial, adbPath, ".\\image\\explore\\确定.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					Sleep(3000);
				}
			}
		}
		else {
			adbTouchMove(device_serial, adbPath, 1130, 520, 1130, 220, 500);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "探索结束\n\n" << std::endl;
}

void dispatch(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "派驻\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\派驻.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\一键验收.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\确定.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\一键派遣.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "派驻结束\n\n" << std::endl;
}

void receive_AP(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "领取AP\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\领取AP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(1000)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\领取.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
		}
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}
	std::cout << "领取AP结束\n\n" << std::endl;
}

void task(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "领取任务\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\任务.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\全部领取.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	std::cout << "领取任务结束\n\n" << std::endl;
}

void alliance(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "联盟日常\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//签到
	std::cout << "签到\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\联盟.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\EMPTY.png", threshold70);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
		else {
			if (i == 4) {
				match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\旅费赞助.png", threshold97);
				if (match.status == 0) {
					std::cout << "已签到\n\n" << std::endl;
					goto next1;
				}
			}
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\返回.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

next1:
	//旅费赞助
	std::cout << "旅费赞助\n\n" << std::endl;
	if (isSubstring(line, "不赞助")) {
		goto next2;
	}
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\旅费赞助.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(5000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\本日赞助.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			const char* check[5] = {"1x","2x","3x","4x","5x"};
			for (int j = 0;j < 5;j++) {
				if (isSubstring(line, check[j])) {
					switch (j) {
					case 0:adbTouchDown(device_serial, adbPath, 868 + rand() % 10, 508 + rand() % 10);break;
					case 1:for (int k = 0;k < j;k++,Sleep(200)) { adbTouchDown(device_serial, adbPath, 868 + rand() % 10, 508 + rand() % 10); }break;
					case 2:for (int k = 0;k < j;k++, Sleep(200)) { adbTouchDown(device_serial, adbPath, 868 + rand() % 10, 508 + rand() % 10); }break;
					case 3:for (int k = 0;k < j;k++, Sleep(200)) { adbTouchDown(device_serial, adbPath, 868 + rand() % 10, 508 + rand() % 10); }break;
					case 4:for (int k = 0;k < j;k++, Sleep(200)) { adbTouchDown(device_serial, adbPath, 868 + rand() % 10, 508 + rand() % 10); }break;
					}
					break;
				}
			}
			break;
		}
	}

	Sleep(500);
	adbTouchDown(device_serial, adbPath, 565 + rand() % 10, 506 + rand() % 10);

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

next2:
	//商谈
	std::cout << "商谈\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\成员名单.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 4;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\商谈.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(500);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(500);
		}
	}

	std::cout << "联盟日常结束\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
}

void activity(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "活动\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	adbTouchDown(device_serial, adbPath, 1076 + rand() % 20, 194 + rand() % 20);
	Sleep(200);
	adbTouchDown(device_serial, adbPath, 1076 + rand() % 20, 194 + rand() % 20);
	Sleep(3000);

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\活动冒险.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(100);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 1076 + rand() % 20, 194 + rand() % 20);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\boss周回.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\SKIP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 940 + rand() % 20, 344 + rand() % 20);
		}
	}

	//检测体力
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\AP回复.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, 640 + rand() % 10, 664 + rand() % 10);
			Sleep(1000);
			adbTouchDown(device_serial, adbPath, 1228 + rand() % 10, 34 + rand() % 10);
			Sleep(1000);
			for (int i = 0;i++ < 10;Sleep(500)) {
				match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					Sleep(2000);
					return;
				}
			}
		}
		else {
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\MAX.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	adbTouchDown(device_serial, adbPath, 1228 + rand() % 10, 34 + rand() % 10);
	Sleep(500);
	adbTouchDown(device_serial, adbPath, 1228 + rand() % 10, 34 + rand() % 10);
	Sleep(1000);

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "活动结束\n\n" << std::endl;
}

void level_up(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "提升等级任务\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\奴隶.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i < 5;i++,Sleep(500)) {
		adbTouchMove(device_serial, adbPath, 1261 + rand() % 20, 306 + rand() % 20, 59 + rand() % 20, 329 + rand() % 20, 1000);
	}
	Sleep(2000);
	adbTouchDown(device_serial, adbPath, 1186 + rand() % 20, 335 + rand() % 20);
	Sleep(1000);

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\LV强化.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\小经验.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + 319 + rand() % 10, match.y + rand() % 10);
			Sleep(50);
			adbTouchDown(device_serial, adbPath, match.x + 319 + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 35 + rand() % 10, 360 + rand() % 10);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	std::cout << "提升等级任务结束\n\n" << std::endl;
}

void arena(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//竞技场
	std::cout << "竞技场\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\冒险.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\竞技场.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 4;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\挑战1.png", threshold97);
		if (match.status == 0) {
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 1225, 35);
		}
	}

	//获取挑战次数
	int x = 5;
	const char* check[5] = {"1次","2次","3次","4次","5次"};
	for (int i = 0;i < 5;i++) {
		if (isSubstring(line, check[i])) {
			x = i + 1;
			std::cout << "挑战次数：" << x << "次\n\n" << std::endl;
		}
	}
	//开始挑战
	for (int i = 0;i < x;i++) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\挑战1.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}

		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\挑战2.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
		}

		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\挑战2.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
		}

		//检测次数是否不足
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\确定.png", threshold97);
		if (match.status == 0) {
			std::cout << "次数不足 \n\n" << std::endl;
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
		else {
			match = image_comparison(device_serial, adbPath, ".\\image\\arena\\返回.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(2000);
			}
			else {
				match = image_comparison(device_serial, adbPath, ".\\image\\arena\\离开.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					Sleep(2000);
				}
			}
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	//竞技场结束
	std::cout << "竞技场结束\n\n" << std::endl;
}

void ruins(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//遗迹
	std::cout << "遗迹\n\n" << std::endl;
	for (int i = 0; i++ < 10; Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	adbTouchDown(device_serial, adbPath, 1076 + rand() % 20, 194 + rand() % 20);
	Sleep(200);
	adbTouchDown(device_serial, adbPath, 1076 + rand() % 20, 194 + rand() % 20);
	Sleep(3000);
	adbTouchDown(device_serial, adbPath, 1117 + rand() % 20, 477 + rand() % 20);
	Sleep(2000);

	start:for (int i = 0; i++ < 10; Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\SKIP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
		else {
			Sleep(1000);
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\挑战.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\SKIP.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					Sleep(1000);
					break;
				}
			}
		}
	}

	for (int i = 0; i < 5; i++,Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	int sum[] = { 0,0,0,1,0,0,1,1 };
	for (int i = 0; i < 8;i++, Sleep(500)) {
		if (sum[i] == 0) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\左.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(3000);
			}
		}
		else {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\右.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(3000);
			}
		}

		int a = 0;
		for (int j = 0; j < 10; j++, Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\挑战.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
			else {
				match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\打开.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					Sleep(1000);
					match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\确定.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
						Sleep(1000);
						match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\关闭.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
							Sleep(1000);
							a = 1;
							break;
						}
					}
				}
			}
		}
		if (a == 1) {
			continue;
		}

		for (int j = 0; j < 10; j++, Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\SKIP.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
		}

		for (int j = 0; j < 10; j++, Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\关闭.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\挑战.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}
	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\SKIP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}
	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\关闭.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	for (int i = 0; i < 5; i++,Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\再战.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\确定.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}
	goto start;
}