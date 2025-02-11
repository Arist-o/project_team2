#pragma once
#ifndef MODULE_SPORTSMEN_H
#define MODULE_SPORTSMEN_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;


void Ahaw_1()
{
    ifstream f("file.dat", ios::binary);
    if (!f)
    {
        cout << "Помилка відкриття файлу." << endl;
        return;
    }

    sportsmen sp, bestSp;
    bool found = false;

    while (f.read((char*)&sp, sizeof(sportsmen)))
    {
        if (!found || sp.speed_run > bestSp.speed_run)
        {
            bestSp = sp;
            found = true;
        }
    }

    f.close();

    if (found)
    {
        cout << "Спортсмен з найкращим показником швидкості бігу:\n";
        cout << "Прізвище: " << bestSp.prizv << endl;
        cout << "Ім'я: " << bestSp.name << endl;
        cout << "Швидкість бігу: " << bestSp.speed_run << " км/год" << endl;
    }
    else
    {
        cout << "Дані про спортсменів відсутні." << endl;
    }

    _getch();
}

void Ahaw_3();

void Ahaw_3()
{
    ifstream f("sportsmen.dat", ios::binary);
    if (!f)
    {
        cout << "Помилка відкриття файлу." << endl;
        return;
    }

    sportsmen sp[100];
    int count = 0;

    while (f.read((char*)&sp[count], sizeof(sportsmen)))
    {
        count++;
    }
    f.close();

    if (count == 0)
    {
        cout << "Дані про спортсменів відсутні." << endl;
        return;
    }

    cout << "Групи спортсменів з приблизно однаковим результатом у 'Біг 3 км' (±7,359%):\n";

    bool mt[100] = { 0 };

    for (int i = 0; i < count; i++)
    {
        if (mt[i]) continue;

        cout << "Група:\n";
        cout << "Прізвище: " << sp[i].prizv << ", Ім'я: " << sp[i].name << ", Біг 3 км: " << sp[i].km3_run << " хв\n";

        mt[i] = true;

        for (int j = i + 1; j < count; j++)
        {
            double diff = abs(sp[j].km3_run - sp[i].km3_run) / sp[i].km3_run * 100.0;

            if (diff <= 7.359)
            {
                cout << "Прізвище: " << sp[j].prizv << ", Ім'я: " << sp[j].name << ", Біг 3 км: " << sp[j].km3_run << " хв\n";
                mt[j] = true;
            }
        }
        cout << "-------------------------\n";
    }

    _getch();
}

#endif