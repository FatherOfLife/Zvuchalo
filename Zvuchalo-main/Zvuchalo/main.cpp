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

	int musics{1}; // ���������� �����
	int musicsL{}; // ���������� ����� ��������

	int pls{ 1 };
	int plsL{};

	struct _finddata_t file;
	intptr_t hFile;


	const int SIZE{ 50 };
	const int sizeOfMusic{ 100 };

	char musicR[SIZE]{ ".wav" };
	char musicName[SIZE]{ "1" };
	char musicWay[SIZE]{ "allMusic/" };

	char newMusicFullname[]{ "" };
	char musicFullname[]{""};

	

	char newMusicName[SIZE]{ "" };

	
	char* arrFullname[sizeOfMusic]; //����� �������� ����� ����� �� � ������ ��� �������������� � �� ������
	
	int i{};
	int i2{}; // ��� ������ �� ����� � ����������
	int i3{}; // ��� case(2)

	std::cout << "������ ���� ����������� �����: " << std::endl << std::endl;
	if ((hFile = _findfirst("AllMusic/*.wav", &file)) == -1L) {
		std::cerr << "�� ������� ������� �����" << std::endl;
		return 1;
	}
	else {
		do {

			arrFullname[musicsL] = new char[strlen(file.name)];
			strcpy(arrFullname[musicsL], file.name);
			musicsL++;
			std::cout << musicsL << ") " << file.name << std::endl;

		} while (_findnext(hFile, &file) == 0);
		_findclose(hFile);

		std::cout << std::endl << "\t���������� �����: " << musicsL << std::endl;
		musics = musicsL;
		musicsL = 0;
	}
	razdel();

	while (!(i == 1)) {
		std::cout << "����: (��� ������ ������� Ctrl + C) " << std::endl;
		std::cout << "1) ���������� ������ ���� ����������� �����" << std::endl;
		std::cout << "2) �������� �����" << std::endl;
		std::cout << "3) ������������� �����" << std::endl;
		std::cout << "4) ��������� (�� ��������)" << std::endl;
		std::cout << "5) �����" << std::endl;
		std::cout << "6) �������/������(?)" << std::endl; // �������� �� �������� �������
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
					
					arrFullname[musicsL] = new char[strlen(file.name)];
					strcpy(arrFullname[musicsL], file.name);
					musicsL++;
					std::cout << musicsL << ") " << file.name << std::endl;
					
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
			std::cout << "��� �� ������ ��������?:" << std::endl;
			std::cout << "1) �� ��������" << std::endl;
			std::cout << "2) �� ������ � ������" << std::endl;
			std::cout << "��� �����: ";
			std::cin >> i3;
			if (i3 == 1) {
				std::cout << "����� ��� �����(��� ����������): ";
				std::cin >> musicName;
				strcpy(musicFullname, musicWay);
				strcat(musicFullname, musicName);
				strcat(musicFullname, musicR);

				PlaySoundA(musicFullname, NULL, SND_FILENAME);

				strcpy(musicFullname, "");
				razdel();

				break;
			}
			else if(i3 == 2){
				int numOfMus{};
				std::cout << "������� ����� ����������: ";
				std::cin >> numOfMus;
				
				if (numOfMus <= musics && numOfMus > 0) {
					strcpy(musicFullname, musicWay);
					strcat(musicFullname, arrFullname[numOfMus - 1]); // -1 �.�. ������ � 0 ����������

					PlaySoundA(musicFullname, NULL, SND_FILENAME);

					strcpy(musicFullname, "");
					
				}
				else{
					std::cerr << "������: ���������� � ������ ������� �� ����������";
				}
				


				razdel();

				break;
			}
			else {
				std::cerr << "������ �����";

			}

			razdel();

			break;
		case(3):
			std::cout << "������� ��� �����, ������� ������ �������������(��� ����������): ";
			std::cin >> musicName;
			std::cout << "�������� ����� ��������(��� ����������): ";
			std::cin >> newMusicName;
			strcpy(musicFullname, musicWay);
			strcat(musicFullname, musicName);
			strcat(musicFullname, musicR);
			
			strcpy(newMusicFullname, musicWay);
			strcat(newMusicFullname, newMusicName);
			strcat(newMusicFullname, musicR);
			std::rename(musicFullname, newMusicFullname);
			
			strcpy(musicFullname, "");
			strcpy(newMusicFullname, "");
			
			razdel();
			break;
		case(4):
			
			do {
				int i{};
				std::cout << "���� ����������: " << std::endl;
				std::cout << "1) ������ ����������" << std::endl;
				std::cout << "2) ������� ��������" << std::endl;
				std::cout << "3) ������������� ��������" << std::endl;
				std::cout << "4) �����" << std::endl;
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
							++plsL;
						} while (_findnext(hFile, &file) == 0);
						_findclose(hFile);
						std::cout << std::endl << "\t���������� ����������: " << plsL - 2  << std::endl;
						pls = plsL;
						plsL = 0;
					}
					razdel();
					break;
				case(2):

					break;
				case(3):
					std::cout << "�������� ��������� ������� ������ �������������: ";
					std::cin >> musicName;
					std::cout << "����� ��������: ";
					std::cin >> newMusicName;
					std::rename(musicName, newMusicName);
					break;
				case(4):
					++i2;

					razdel();
					break;
				default:

					break;
				}
			} while (i2 == 0);
			break;
			i2 = 0;
		case(5):
			i = 1;
			break;
		case(6):
			spravka();

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