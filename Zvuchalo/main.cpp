#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
void razdel();
void spravka();



int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int switchMenu{};

	int musics{}; // ���������� �����
	int musicsL{}; // ���������� ����� ��������
	struct _finddata_t file;
	intptr_t hFile;


	const int SIZE{ 50 };
	const int sizeOfMusic{ 100 };

	char musicR[SIZE]{ ".wav" };
	char musicName[SIZE]{ "1" };
	char musicWay[SIZE]{ "allMusic/" };

	char newMusicName[SIZE]{ "1" };

	
	const char* arrFullname[sizeOfMusic]; //����� �������� ����� ����� �� � ������ ��� �������������� � �� ������
	
	int i{};
	int i2{}; // ��� ������ �� ����� � ����������

	while (!(i == 1)) {
		std::cout << "����: (��� ������ ������� Ctrl + C) " << std::endl;
		std::cout << "1) ���������� ������ ���� ����������� �����" << std::endl;
		std::cout << "2) �������� �����" << std::endl;
		std::cout << "3) ������������� �����" << std::endl;
		std::cout << "4) ��������� (�� ��������)" << std::endl;
		std::cout << "5) �����" << std::endl;
		std::cout << "6) �������/������(?)" << std::endl; // �������� �� �������� �������
		std::cout << "7) ������������������ ����� �������" << std::endl;
		std::cout << "��� �����: ";
		std::cin >> switchMenu;
		razdel();
		switch (switchMenu)
		{
		case(1):
			if ((hFile = _findfirst("AllMusic/*.wav", &file)) == -1L) {
				std::cerr << "�� ������� ������� �����" << std::endl;
				return 1;
			}
			else {
				do {
					
					arrFullname[musicsL] = file.name;
					musicsL++;
					std::cout << file.name << std::endl;
					
				} while (_findnext(hFile, &file) == 0);
				_findclose(hFile);

				std::cout << std::endl << "\t���������� �����: " << musicsL << std::endl;
				musics = musicsL;
				musicsL = 0;
			}
			razdel();
			break;
		case(2):
			std::cout << "(����� ������� ������ ������ ��������������� ����� � ������)" << std::endl;

			std::cout << "����� ��� �����(��� ����������): ";
			std::cin >> musicName;
			strcat(musicWay, musicName);
			strcat(musicWay, musicR);

			PlaySoundA(musicWay, NULL, SND_FILENAME);

			razdel();

			break;
		case(3):
			std::cout << "�������� ���� ������� ������ �������������(��� ����������): ";
			std::cin >> musicName;
			std::cout << "�������� ����� ��������(��� ����������): ";
			std::cin >> newMusicName;
			strcat(musicName, musicR);
			strcat(newMusicName, musicR);
			std::rename(musicName, newMusicName);
			razdel();
			break;
		case(4):
			
			/*do {
				int i{};
				std::cout << "���� ����������: " << std::endl;
				std::cout << "1) ������� ��������" << std::endl;
				std::cout << "2) ������������� ��������" << std::endl;
				std::cout << "3) �����" << std::endl;
				std::cout << "��� �����: ";
				std::cin >> i;

				switch (i)
				{
				case(1):
					if ((hFile = _findfirst("PLs/*", &file)) == -1L) {
						std::cerr << "�� ������� ������� �����" << std::endl;
						return 1;
					}
					else {
						do {

							std::cout << file.name << std::endl;
							++musics;
						} while (_findnext(hFile, &file) == 0);
						_findclose(hFile);
						std::cout << std::endl << "\t���������� ����������: " << musics - 2 << std::endl;
						musics = 0;
					}
					razdel();
					break;
				case(2):
					std::cout << "�������� ��������� ������� ������ �������������: ";
					std::cin >> musicName;
					std::cout << "����� ��������: ";
					std::cin >> newMusicName;
					std::rename(musicName, newMusicName);
					break;
				case(3):
					++i2;
					break;
				default:

					break;
				}
			} while (i2 == 0);
			break;
			i2 = 0;*/
		case(5):
			i = 1;
			break;
		case(6):
			spravka();

			break;
		case(7):
			for (int i{ 0 }; i < musics; i++) {
				std::cout << arrFullname[i] << std::endl;
			}
			razdel();
			break;
		default:
			break;
		}
	}


	







}

void razdel() {
	std::cout << std::endl << "---------------------------------------" << std::endl << std::endl;
}

void spravka() {
	int i;
	std::cout << "��� ������ ������?" << std::endl;
	std::cout << "1) ����������" << std::endl;
	std::cout << "2) ������ �������" << std::endl;
	std::cout << "��� �����: ";
	std::cin >> i;

	razdel();

	switch (i) {
	case(1):


		break;
	case(2):
		std::cout << "������ �������:" << std::endl << std::endl;

		std::cout << '-' << "�������� �����, � ��� �� ���������� � ������. ��� ������?" << std::endl;
		std::cout << '\t' << "���������� ����� ���������� � ������������ �����." << std::endl;
		std::cout << '\t' << "��������� ������������ ������ ����� ������� .wav" << std::endl << std::endl;

		std::cout << '-' << "������ ����� � ��� �� �����������, ���� ���� ������������ � ������ �����. ��� ������?" << std::endl;
		std::cout << '\t' << "��������� ��� �����. " << std::endl;
		std::cout << '\t' << "��� ����� ������ �������� ������ �� �������� � ����� ������." << std::endl << std::endl;

		std::cout << '-' << "������� ������������� �����, � ��� �� ���������������/ ��������������� �� �������� �����������. ��� ������?" << std::endl;
		std::cout << '\t' << "��������� ��� ����� � ����� ��������. " << std::endl;
		std::cout << '\t' << "��� ������ �������� ������ �� �������� � ����� ������." << std::endl << std::endl;

		razdel();
		break;
	default:
		break;
	}
	
}