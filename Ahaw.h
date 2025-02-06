#pragma once
#ifndef MODULE_SPORTSMEN_H
#define MODULE_SPORTSMEN_H

#include <iostream>
#include <conio.h>
#include <fstream>
#include <Windows.h>
using namespace std;

// ������� ��������� ���������� � ��������� ���������� ��� �� ��������
void Ahaw();

void Ahaw()
{
    ifstream f("sportsmen.dat", ios::binary);
    if (!f)
    {
        cout << "������� �������� �����." << endl;
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
        cout << "��������� � ��������� ���������� �������� ���:\n";
        cout << "�������: " << bestSp.prizv << endl;
        cout << "��'�: " << bestSp.name << endl;
        cout << "�������� ���: " << bestSp.speed_run << " ��/���" << endl;
    }
    else
    {
        cout << "��� ��� ���������� ������." << endl;
    }

    _getch();
}

#endif