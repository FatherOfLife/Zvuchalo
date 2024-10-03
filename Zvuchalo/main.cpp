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
	int musicsL{}; // Количество песен локально
	struct _finddata_t file;
	intptr_t hFile;


	const int SIZE{ 50 };
	const int sizeOfMusic{ 100 };

	char musicR[SIZE]{ ".wav" };
	char musicName[SIZE]{ "1" };
	char musicWay[SIZE]{ "allMusic/" };

	char newMusicName[SIZE]{ "1" };

	
	const char* arrFullname[sizeOfMusic]; //Можно добавить выбор песни по её номеру для переименования и не только
	
	int i{};
	int i2{}; // для выхода из цикла в плейлистах

	while (!(i == 1)) {
		std::cout << "Меню: (Для выхода нажмите Ctrl + C) " << std::endl;
		std::cout << "1) Отобразить список всех загруженных песен" << std::endl;
		std::cout << "2) Включить песню" << std::endl;
		std::cout << "3) Переименовать песню" << std::endl;
		std::cout << "4) Плейлисты (НЕ РАБОТАЕТ)" << std::endl;
		std::cout << "5) Выйти" << std::endl;
		std::cout << "6) Справка/Помощь(?)" << std::endl; // Отвечает на основные вопросы
		std::cout << "7) Эксперементвальный вывод массива" << std::endl;
		std::cout << "Ваш выбор: ";
		std::cin >> switchMenu;
		razdel();
		switch (switchMenu)
		{
		case(1):
			if ((hFile = _findfirst("AllMusic/*.wav", &file)) == -1L) {
				std::cerr << "Не удалось открыть файлы" << std::endl;
				return 1;
			}
			else {
				do {
					
					arrFullname[musicsL] = file.name;
					musicsL++;
					std::cout << file.name << std::endl;
					
				} while (_findnext(hFile, &file) == 0);
				_findclose(hFile);

				std::cout << std::endl << "\tКоличество песен: " << musicsL << std::endl;
				musics = musicsL;
				musicsL = 0;
			}
			razdel();
			break;
		case(2):
			std::cout << "(Чтобы открыть список выбери соответствующий пункт в начале)" << std::endl;

			std::cout << "Введи имя файла(без расширения): ";
			std::cin >> musicName;
			strcat(musicWay, musicName);
			strcat(musicWay, musicR);

			PlaySoundA(musicWay, NULL, SND_FILENAME);

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
			
			/*do {
				int i{};
				std::cout << "Меню плейлистов: " << std::endl;
				std::cout << "1) Выбрать плейлист" << std::endl;
				std::cout << "2) Переименовать плейлист" << std::endl;
				std::cout << "3) Назад" << std::endl;
				std::cout << "Ваш выбор: ";
				std::cin >> i;

				switch (i)
				{
				case(1):
					if ((hFile = _findfirst("PLs/*", &file)) == -1L) {
						std::cerr << "Не удалось открыть файлы" << std::endl;
						return 1;
					}
					else {
						do {

							std::cout << file.name << std::endl;
							++musics;
						} while (_findnext(hFile, &file) == 0);
						_findclose(hFile);
						std::cout << std::endl << "\tКоличество плейлистов: " << musics - 2 << std::endl;
						musics = 0;
					}
					razdel();
					break;
				case(2):
					std::cout << "Название плейлиста который хотите переименовать: ";
					std::cin >> musicName;
					std::cout << "Новое название: ";
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
	std::cout << "Что хотите узнать?" << std::endl;
	std::cout << "1) Инструкция" << std::endl;
	std::cout << "2) Частые вопросы" << std::endl;
	std::cout << "Ваш выбор: ";
	std::cin >> i;

	razdel();

	switch (i) {
	case(1):


		break;
	case(2):
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
		break;
	default:
		break;
	}
	
}