#pragma once
#include <iostream>
#include <cstring>
using namespace std;
void cucl(bool& povtor)
{
	char var;
	bool vidpovid = true;
	while (vidpovid) {
		cout << "Бажаєте ще раз запустити програму?Y/N" << endl;
		vidpovid = true;
		cin >> var;
		if (var == 'N')
		{
			povtor = false;
			vidpovid = false;
		}
		else if (var == 'Y')
		{
			povtor = true;
			vidpovid = false;
		}
		else
		{
			cout << "Некоректне введення відповіді.Введіть ще раз\a" << endl;
		}
	}
}
void create_file(fstream& file,sportsmen& s,int& kilk)
{
	file.open("file.dat", ios::out | ios::binary);
	do {
		cin >> kilk;
		if (kilk <= 0 || kilk > 30)
		{
			cout << "Неправильно введена кількість" << endl;
		}
	} while (kilk <= 0 || kilk > 30);
	for (int i = 0; i < kilk; i++)
	{

		cout << endl << "Спортсмен" << endl;
		cout << "Введіть ім'я" << endl;
		cin.ignore();
		do {
			cin.getline(s.name, 50);
			if (strlen(s.name) == 0) {
				cout << "Ім'я не може бути пустим! Введіть ще раз: ";
			}
		} while (strlen(s.name) == 0);

		cout << "Введіть прізвище" << endl;
		do {
			cin.getline(s.prizv, 50);
			if (strlen(s.prizv) == 0) {
				cout << "Прізвище не може бути пустим! Введіть ще раз: ";
			}
		} while (strlen(s.prizv) == 0);

		cout << "Введіть швидкість бігу (км/год)" << endl;
		do {
			cin >> s.speed_run;
			if (s.speed_run <= 0) {
				cout << "Швидкість повинна бути додатною\a" << endl;
			}
		} while (s.speed_run <= 0);

		cout << "Введіть дистанцію бігу (км)" << endl;
		do {
			cin >> s.km3_run;
			if (s.km3_run <= 0) {
				cout << "Дистанція повинна бути додатною\a" << endl;
			}
		} while (s.km3_run <= 0);

		cout << "Введіть кількість віджимань" << endl;
		do {
			cin >> s.pres;
			if (s.pres < 0) {
				cout << "Кількість віджимань не може бути від'ємною\a" << endl;
			}
		} while (s.pres < 0);

		cout << "Введіть висоту стрибка (м)" << endl;
		do {
			cin >> s.jump;
			if (s.jump < 0) {
				cout << "Висота стрибка не може бути від'ємною\a" << endl;
			}
		} while (s.jump < 0);

		cin.ignore();
		file.write((char*)&s, sizeof(s)); 

	}
	file.close();
}
void read_file(fstream& file) {
	file.open("file.dat", ios::in | ios::binary);
	if (!file.is_open()) {
		cout << "Не вдалося відкрити файл." << endl;
		return;
	}

	sportsmen s;
	while (file.read((char*)&s, sizeof(s))) { 
		cout << "Ім'я: " << s.name << ", Прізвище: " << s.prizv
			<< ", Швидкість: " << s.speed_run << ", Дистанція: " << s.km3_run
			<< ", Віджимання: " << s.pres << ", Стрибок: " << s.jump << endl;
	}

	file.close();

}

void dopus(fstream& file, sportsmen& s,int& kilk)
{
	string text;
	bool text_povtor = true;
	cin.ignore();
	text_povtor = false;
	file.open("file.dat", ios::app | ios::binary);
	if (!file) {
		cout << "Помилка відкриття файлу" << endl;
		return;
	}
	cout << "Введіть кількість спорстменів для дозапису" << endl;
	do {
		cin >> kilk;
		if (kilk <+ 0 || kilk > 30)
		{
			cout << "Неправильно введена кількість" << endl;
		}
	} while (kilk <= 0 || kilk > 30);
	for (int i = 0; i < kilk; i++)
	{
		cout << endl << "Спортсмен" << endl;
		cout << "Введіть ім'я" << endl;
		do {
			cin.getline(s.name, 50);
			if (strlen(s.name) == 0) {
				cout << "Ім'я не може бути пустим! Введіть ще раз: ";
			}
		} while (strlen(s.name) == 0);

		cout << "Введіть прізвище" << endl;
		do {
			cin.getline(s.prizv, 50);
			if (strlen(s.prizv) == 0) {
				cout << "Прізвище не може бути пустим! Введіть ще раз: ";
			}
		} while (strlen(s.prizv) == 0);

		cout << "Введіть швидкість бігу (км/год)" << endl;
		do {
			cin >> s.speed_run;
			if (s.speed_run <= 0) {
				cout << "Швидкість повинна бути додатною\a" << endl;
			}
		} while (s.speed_run <= 0);

		cout << "Введіть дистанцію бігу (км)" << endl;
		do {
			cin >> s.km3_run;
			if (s.km3_run <= 0) {
				cout << "Дистанція повинна бути додатною\a" << endl;
			}
		} while (s.km3_run <= 0);

		cout << "Введіть кількість віджимань" << endl;
		do {
			cin >> s.pres;
			if (s.pres < 0) {
				cout << "Кількість віджимань не може бути від'ємною\a" << endl;
			}
		} while (s.pres < 0);

		cout << "Введіть висоту стрибка (м)" << endl;
		do {
			cin >> s.jump;
			if (s.jump < 0) {
				cout << "Висота стрибка не може бути від'ємною\a" << endl;
			}
		} while (s.jump < 0);

		cin.ignore();
		file.write((char*)&s, sizeof(s));
	}
	file.close();
}
