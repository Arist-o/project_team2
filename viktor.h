#pragma once
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
