#pragma once
#ifndef MODULE_SPORTSMEN_H
#define MODULE_SPORTSMEN_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;

// Функція знаходить спортсмена з найкращим показником бігу на швидкість
void Ahaw();

void Ahaw()
{
    ifstream f("sportsmen.dat", ios::binary);
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

#endif