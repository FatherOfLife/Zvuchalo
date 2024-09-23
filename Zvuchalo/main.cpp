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
	struct _finddata_t file;
	intptr_t hFile;


	const int SIZE{ 50 };
	char musicR[SIZE]{ ".wav" };
	char musicName[SIZE]{ "1" };

	char newMusicName[SIZE]{ "1" };

	//char musicFullname[SIZE]{};
	//char arrFullname[SIZE][100]{}; ����� �������� ����� ����� �� � ������ ��� �������������� � �� ������
	
	int i{};

	while (!(i == 1)) {
		std::cout << "����: (��� ������ ������� Ctrl + C) " << std::endl;
		std::cout << "1) ���������� ������ ���� ����������� �����" << std::endl;
		std::cout << "2) �������� �����" << std::endl;
		std::cout << "3) ������������� �����" << std::endl;
		std::cout << "4) �����" << std::endl;
		std::cout << "5) �������/������(?)" << std::endl; // �������� �� �������� �������
		std::cout << "��� �����: ";
		std::cin >> switchMenu;
		razdel();
		switch (switchMenu)
		{
		case(1):
			if ((hFile = _findfirst("*.wav", &file)) == -1L) {
				std::cerr << "�� ������� ������� �����" << std::endl;
				return 1;
			}
			else {
				do {

					std::cout << file.name << std::endl;
					++musics;
				} while (_findnext(hFile, &file) == 0);
				_findclose(hFile);
				std::cout << std::endl << "\t���������� �����: " << musics << std::endl;
				musics = 0;
			}
			razdel();
			break;
		case(2):
			std::cout << "(����� ������� ������ ������ ��������������� ����� � ������)" << std::endl;

			std::cout << "����� ��� �����(��� ����������): ";
			std::cin >> musicName;
			strcat(musicName, musicR);

			PlaySoundA(musicName, NULL, SND_FILENAME);

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
			i = 1;
			break;
		case(5):
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
}