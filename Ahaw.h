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

void Ahaw_3();

void Ahaw_3()
{
    ifstream f("sportsmen.dat", ios::binary);
    if (!f)
    {
        cout << "������� �������� �����." << endl;
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
        cout << "��� ��� ���������� ������." << endl;
        return;
    }

    cout << "����� ���������� � ��������� ��������� ����������� � '��� 3 ��' (�7,359%):\n";

    bool mt[100] = { 0 };

    for (int i = 0; i < count; i++)
    {
        if (mt[i]) continue;

        cout << "�����:\n";
        cout << "�������: " << sp[i].prizv << ", ��'�: " << sp[i].name << ", ��� 3 ��: " << sp[i].km3_run << " ��\n";

        mt[i] = true;

        for (int j = i + 1; j < count; j++)
        {
            double diff = abs(sp[j].km3_run - sp[i].km3_run) / sp[i].km3_run * 100.0;

            if (diff <= 7.359)
            {
                cout << "�������: " << sp[j].prizv << ", ��'�: " << sp[j].name << ", ��� 3 ��: " << sp[j].km3_run << " ��\n";
                mt[j] = true;
            }
        }
        cout << "-------------------------\n";
    }

    _getch();
}

#endif