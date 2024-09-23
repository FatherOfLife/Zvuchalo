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

	int musics{}; // Количество песен
	struct _finddata_t file;
	intptr_t hFile;


	const int SIZE{ 50 };
	char musicR[SIZE]{ ".wav" };
	char musicName[SIZE]{ "1" };

	char newMusicName[SIZE]{ "1" };

	//char musicFullname[SIZE]{};
	//char arrFullname[SIZE][100]{}; Можно добавить выбор песни по её номеру для переименования и не только
	
	int i{};

	while (!(i == 1)) {
		std::cout << "Меню: (Для выхода нажмите Ctrl + C) " << std::endl;
		std::cout << "1) Отобразить список всех загруженных песен" << std::endl;
		std::cout << "2) Включить песню" << std::endl;
		std::cout << "3) Перемеиновать песню" << std::endl;
		std::cout << "4) Выйти" << std::endl;
		std::cout << "5) Справка/Помощь(?)" << std::endl; // Отвечает на основные вопросы
		std::cout << "Ваш выбор: ";
		std::cin >> switchMenu;
		razdel();
		switch (switchMenu)
		{
		case(1):
			if ((hFile = _findfirst("*.wav", &file)) == -1L) {
				std::cerr << "Не удалось открыть файлы" << std::endl;
				return 1;
			}
			else {
				do {

					std::cout << file.name << std::endl;
					++musics;
				} while (_findnext(hFile, &file) == 0);
				_findclose(hFile);
				std::cout << std::endl << "\tКоличество песен: " << musics << std::endl;
				musics = 0;
			}
			razdel();
			break;
		case(2):
			std::cout << "(Чтобы открыть список выбери соответствующий пункт в начале)" << std::endl;

			std::cout << "Введи имя файла(без расширения): ";
			std::cin >> musicName;
			strcat(musicName, musicR);

			PlaySoundA(musicName, NULL, SND_FILENAME);

			razdel();

			break;
		case(3):
			std::cout << "Выберите файл который хотите переименовать(без расширения): ";
			std::cin >> musicName;
			std::cout << "Выберите новое название(без расширения): ";
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
	std::cout << "Частые вопросы:" << std::endl << std::endl;

	std::cout << '-' << "Загрузил песню, а она не добавилось в список. Что делать?" << std::endl;
	std::cout << '\t' << "Прооверьте какое расширение у загруженного файла." << std::endl;
	std::cout << '\t' << "Программа обрабатывает только файлы формата .wav" << std::endl << std::endl;

	std::cout << '-' << "Выбрал песню а она не запустилась, хотя файл отображается в списке песен. Что делать?" << std::endl;
	std::cout << '\t' << "Проверьте имя файла. " << std::endl;
	std::cout << '\t' << "Имя файла должно состоять только из латиницы и знака дефиса." << std::endl << std::endl;

	std::cout << '-' << "Пытался переименовать песню, а она не переименовалась/ переименовалось но название повредилось. Что делать?" << std::endl;
	std::cout << '\t' << "Проверьте имя файла и новое название. " << std::endl;
	std::cout << '\t' << "Они должны состоять только из латиницы и знака дефиса." << std::endl << std::endl;

	razdel();
}