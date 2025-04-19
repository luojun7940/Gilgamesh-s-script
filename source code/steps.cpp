#include"steps.h"

void start(const char* device_serial, const char* adbPath) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	for (;;Sleep(500)) {
		adbTouchDown(device_serial, adbPath, 1 + rand() % 20, 1 + rand() % 20);

		match = image_comparison(device_serial, adbPath, ".\\image\\start\\�ر�.png", threshold97);
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
	std::cout << "��ʼ\n\n" << std::endl;
}

void crusade(const char* device_serial, const char* adbPath,const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "�ַ�\n\n" << std::endl;
	for (int i=0;i++<10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\�ַ�ս.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 5, match.y + rand() % 5);
			Sleep(5000);
			break;
		}
	}

	//ѡ��Ŀ��
	std::cout << "ѡ��Ŀ��\n\n" << std::endl;
	const char* checkpoint[2] = { "��פ","�" };
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
		match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\ɸѡ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			//����
			const char* checkpoint1[3] = { "ȫ��","����","����"};
			//����
			const char* checkpoint2[7] = { "ȫ��","��","ˮ" ,"ľ","��","��","����"};
			//�Ѷ�
			const char* checkpoint3[4] = { "ȫ��","NORMAL","VERY HARD","HARD"};
			for (int j = 0;j < 3;j++) {
				if (isSubstring(line, checkpoint1[j])) {
					switch (j) {
					case 0:adbTouchDown(device_serial, adbPath, 146 + rand() % 10, 198 + rand() % 10);break;

					case 1:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\����.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 2:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\����.png", threshold97);
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

					case 1:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 2:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\ˮ.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 3:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\ľ.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 4:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 5:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��.png", threshold97);
						if (match.status == 0) {
							adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
						}break;

					case 6:match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\����.png", threshold97);
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
				match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\ȷ��.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					break;
				}
			}
			break;
		}
	}
	Sleep(1000);

	//��ʼս��
	for (;;Sleep(500)) {
	start:int x = 0,y = 0;
		std::cout << "ѡ����Ѫ\n\n" << std::endl;
		if (isSubstring(line, "��Ѫ")) {
			for (;;Sleep(1000)) {
				match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��Ѫ.png", 0.98);
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
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\�ַ�ս.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					}
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��Ԯ�嵥.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
					}
					Sleep(1000);

					//ѡ��Ŀ��
					const char* checkpoint[2] = { "��פ","�" };
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

		std::cout << "��ʼս��\n\n" << std::endl;
		for (int i = 0;i++ < 15;Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��ս.png", threshold97);
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
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\BP�ظ�.png", threshold97);
			if (match.status == 0) {
				std::cout << "�ظ�BP\n\n" << std::endl;
				if (isSubstring(line, "BP")) {
					match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\СBP.png", threshold97);
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
						match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\��BP.png", threshold97);
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

		std::cout << "�ȴ�����\n\n" << std::endl;
		for (;;Sleep(1000)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\crusade\\����������.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
		}
		std::cout << "����\n\n" << std::endl;
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}
	std::cout << "�ַ�����\n\n" << std::endl;
}

void email(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "��ȡ����\n\n" << std::endl;
	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\����.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\ȫ����ȡ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\email\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 1 + rand() % 20, 1 + rand() % 20);
			match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				std::cout << "��ȡ�������\n\n" << std::endl;
				return;
			}
		}
	}
}

void adventure(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//ð��
	std::cout << "ð��\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\ð��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//ս������
	std::cout << "ս������\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\ս������.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�ص�ͼ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//ħԨ����
	std::cout << "ħԨ����\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\ħԨ����.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	const char* check[3] = { "�Ѷ�1","�Ѷ�2","�Ѷ�3" };
	for (int i = 0;i < 3;i++) {
		if (isSubstring(line, check[i])){
			switch (i) {
			case 0:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�Ѷ�1.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(2000);
				}
				break;
			case 1:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�Ѷ�2.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(2000);
				}
				break;
			case 2:match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�Ѷ�3.png", threshold97);
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
				match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�Ѷ�3.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + 10 + rand() % 20, match.y + 160 + rand() % 20);
					Sleep(500);
				}
				break;
			}
		}
	}

	//�������Ƿ����
	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\ȷ��.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\adventure\\�ص�ͼ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//ð�ս���
	std::cout << "ð�ս���\n\n" << std::endl;
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

	std::cout << "�����ļ\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\ÿ�����.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\ū����Լ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\һ��.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + 70 + rand() % 20);
				Sleep(2000);
				for (int j = 0;j++ < 20;Sleep(1000)) {
					match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\����������.png", threshold90);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\������Լ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\һ��.png", threshold90);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + 70 + rand() % 20);
				Sleep(2000);
				for (int j = 0;j++ < 20;Sleep(1000)) {
					match = image_comparison(device_serial, adbPath, ".\\image\\free_call\\����������.png", threshold90);
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
	std::cout << "�����ļ����\n\n" << std::endl;
}

void explore(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "̽��\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\̽��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\һ����ȡ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\explore\\׷�ӻ���.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			match = image_comparison(device_serial, adbPath, ".\\image\\explore\\MAX.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
				Sleep(2000);
				match = image_comparison(device_serial, adbPath, ".\\image\\explore\\ȷ��.png", threshold97);
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
	std::cout << "̽������\n\n" << std::endl;
}

void dispatch(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "��פ\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\��פ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\һ������.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\ȷ��.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\dispatch\\һ����ǲ.png", threshold90);
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
	std::cout << "��פ����\n\n" << std::endl;
}

void receive_AP(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "��ȡAP\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\��ȡAP.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 5;Sleep(1000)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\��ȡ.png", threshold90);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
		}
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\receive_AP\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			break;
		}
	}
	std::cout << "��ȡAP����\n\n" << std::endl;
}

void task(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "��ȡ����\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\����.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\ȫ����ȡ.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(3000);
			break;
		}
	}

	for (int i = 0;i++ < 20;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\task\\�ر�.png", threshold97);
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

	std::cout << "��ȡ�������\n\n" << std::endl;
}

void alliance(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "�����ճ�\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	//ǩ��
	std::cout << "ǩ��\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\����.png", threshold97);
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
				match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\�÷�����.png", threshold97);
				if (match.status == 0) {
					std::cout << "��ǩ��\n\n" << std::endl;
					goto next1;
				}
			}
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\����.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

next1:
	//�÷�����
	std::cout << "�÷�����\n\n" << std::endl;
	if (isSubstring(line, "������")) {
		goto next2;
	}
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\�÷�����.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(5000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\��������.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

next2:
	//��̸
	std::cout << "��̸\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\��Ա����.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 4;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\alliance\\��̸.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(1000);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(500);
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(500);
		}
	}

	std::cout << "�����ճ�����\n\n" << std::endl;
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

	std::cout << "�\n\n" << std::endl;
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
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\�ð��.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\boss�ܻ�.png", threshold97);
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

	//�������
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\AP�ظ�.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\activity\\�ر�.png", threshold97);
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
	std::cout << "�����\n\n" << std::endl;
}

void level_up(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	std::cout << "�����ȼ�����\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\ū��.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\LVǿ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 10, match.y + rand() % 10);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\level_up\\С����.png", threshold97);
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

	std::cout << "�����ȼ��������\n\n" << std::endl;
}

void arena(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//������
	std::cout << "������\n\n" << std::endl;
	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\home.png", threshold80);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\ð��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
	}

	for (int i = 0;i++ < 10;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\������.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
			break;
		}
	}

	for (int i = 0;i++ < 4;Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\��ս1.png", threshold97);
		if (match.status == 0) {
			break;
		}
		else {
			adbTouchDown(device_serial, adbPath, 1225, 35);
		}
	}

	//��ȡ��ս����
	int x = 5;
	const char* check[5] = {"1��","2��","3��","4��","5��"};
	for (int i = 0;i < 5;i++) {
		if (isSubstring(line, check[i])) {
			x = i + 1;
			std::cout << "��ս������" << x << "��\n\n" << std::endl;
		}
	}
	//��ʼ��ս
	for (int i = 0;i < x;i++) {
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\��ս1.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}

		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\��ս2.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
		}

		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\��ս2.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
		}

		//�������Ƿ���
		match = image_comparison(device_serial, adbPath, ".\\image\\arena\\ȷ��.png", threshold97);
		if (match.status == 0) {
			std::cout << "�������� \n\n" << std::endl;
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(2000);
			break;
		}
		else {
			match = image_comparison(device_serial, adbPath, ".\\image\\arena\\����.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(2000);
			}
			else {
				match = image_comparison(device_serial, adbPath, ".\\image\\arena\\�뿪.png", threshold97);
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

	//����������
	std::cout << "����������\n\n" << std::endl;
}

void ruins(const char* device_serial, const char* adbPath, const char* line) {
	MatchResult match;
	cv::Mat croppedImage;
	int rand(void);

	//�ż�
	std::cout << "�ż�\n\n" << std::endl;
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
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��ս.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	int sum[] = { 0,0,0,1,0,0,1,1 };
	for (int i = 0; i < 8;i++, Sleep(500)) {
		if (sum[i] == 0) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(3000);
			}
		}
		else {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(3000);
			}
		}

		int a = 0;
		for (int j = 0; j < 10; j++, Sleep(500)) {
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��ս.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
			else {
				match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��.png", threshold97);
				if (match.status == 0) {
					adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
					Sleep(1000);
					match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\ȷ��.png", threshold97);
					if (match.status == 0) {
						adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
						Sleep(1000);
						match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\�ر�.png", threshold97);
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
			match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\�ر�.png", threshold97);
			if (match.status == 0) {
				adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
				Sleep(1000);
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��ս.png", threshold97);
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
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\�ر�.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	for (int i = 0; i < 5; i++,Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\��ս.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}

	for (int i = 0; i < 5; i++, Sleep(500)) {
		match = image_comparison(device_serial, adbPath, ".\\image\\ruins\\ȷ��.png", threshold97);
		if (match.status == 0) {
			adbTouchDown(device_serial, adbPath, match.x + rand() % 20, match.y + rand() % 20);
			Sleep(1000);
		}
	}
	goto start;
}