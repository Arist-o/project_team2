#pragma once
#include <iostream>
#include <cstring>
using namespace std;
void cucl(bool& povtor)
{
	char var;
	bool vidpovid = true;
	while (vidpovid) {
		cout << "������ �� ��� ��������� ��������?Y/N" << endl;
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
			cout << "���������� �������� ������.������ �� ���\a" << endl;
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
			cout << "����������� ������� �������" << endl;
		}
	} while (kilk <= 0 || kilk > 30);
	for (int i = 0; i < kilk; i++)
	{

		cout << endl << "���������" << endl;
		cout << "������ ��'�" << endl;
		cin.ignore();
		do {
			cin.getline(s.name, 50);
			if (strlen(s.name) == 0) {
				cout << "��'� �� ���� ���� ������! ������ �� ���: ";
			}
		} while (strlen(s.name) == 0);

		cout << "������ �������" << endl;
		do {
			cin.getline(s.prizv, 50);
			if (strlen(s.prizv) == 0) {
				cout << "������� �� ���� ���� ������! ������ �� ���: ";
			}
		} while (strlen(s.prizv) == 0);

		cout << "������ �������� ��� (��/���)" << endl;
		do {
			cin >> s.speed_run;
			if (s.speed_run <= 0) {
				cout << "�������� ������� ���� ��������\a" << endl;
			}
		} while (s.speed_run <= 0);

		cout << "������ ��������� ��� (��)" << endl;
		do {
			cin >> s.km3_run;
			if (s.km3_run <= 0) {
				cout << "��������� ������� ���� ��������\a" << endl;
			}
		} while (s.km3_run <= 0);

		cout << "������ ������� ��������" << endl;
		do {
			cin >> s.pres;
			if (s.pres < 0) {
				cout << "ʳ������ �������� �� ���� ���� ��'�����\a" << endl;
			}
		} while (s.pres < 0);

		cout << "������ ������ ������� (�)" << endl;
		do {
			cin >> s.jump;
			if (s.jump < 0) {
				cout << "������ ������� �� ���� ���� ��'�����\a" << endl;
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
		cout << "�� ������� ������� ����." << endl;
		return;
	}

	sportsmen s;
	while (file.read((char*)&s, sizeof(s))) { 
		cout << "��'�: " << s.name << ", �������: " << s.prizv
			<< ", ��������: " << s.speed_run << ", ���������: " << s.km3_run
			<< ", ³��������: " << s.pres << ", �������: " << s.jump << endl;
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
		cout << "������� �������� �����" << endl;
		return;
	}
	cout << "������ ������� ���������� ��� ��������" << endl;
	do {
		cin >> kilk;
		if (kilk <+ 0 || kilk > 30)
		{
			cout << "����������� ������� �������" << endl;
		}
	} while (kilk <= 0 || kilk > 30);
	for (int i = 0; i < kilk; i++)
	{
		cout << endl << "���������" << endl;
		cout << "������ ��'�" << endl;
		do {
			cin.getline(s.name, 50);
			if (strlen(s.name) == 0) {
				cout << "��'� �� ���� ���� ������! ������ �� ���: ";
			}
		} while (strlen(s.name) == 0);

		cout << "������ �������" << endl;
		do {
			cin.getline(s.prizv, 50);
			if (strlen(s.prizv) == 0) {
				cout << "������� �� ���� ���� ������! ������ �� ���: ";
			}
		} while (strlen(s.prizv) == 0);

		cout << "������ �������� ��� (��/���)" << endl;
		do {
			cin >> s.speed_run;
			if (s.speed_run <= 0) {
				cout << "�������� ������� ���� ��������\a" << endl;
			}
		} while (s.speed_run <= 0);

		cout << "������ ��������� ��� (��)" << endl;
		do {
			cin >> s.km3_run;
			if (s.km3_run <= 0) {
				cout << "��������� ������� ���� ��������\a" << endl;
			}
		} while (s.km3_run <= 0);

		cout << "������ ������� ��������" << endl;
		do {
			cin >> s.pres;
			if (s.pres < 0) {
				cout << "ʳ������ �������� �� ���� ���� ��'�����\a" << endl;
			}
		} while (s.pres < 0);

		cout << "������ ������ ������� (�)" << endl;
		do {
			cin >> s.jump;
			if (s.jump < 0) {
				cout << "������ ������� �� ���� ���� ��'�����\a" << endl;
			}
		} while (s.jump < 0);

		cin.ignore();
		file.write((char*)&s, sizeof(s));
	}
	file.close();
}
