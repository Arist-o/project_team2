#pragma once
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
