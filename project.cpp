
#include <iostream>
#include <Windows.h>
#include "viktor.h"
using namespace std;
struct sportsmen
{
    string prizv="";
    string name = "";
    double speed_run = 0;
    double km3_run = 0;
    int pres = 0;
    double jump = 0;
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int variant = 0;
    bool povtor = true;
    while (povtor)
    {
        cout << R"(Виберіть що хочете зробити зі списку запропонованих дій:
                                                                    1 Створення бінарного файлу
                                                                    2 Прочитати файл на екран
                                                                    3 Вибрати з дальнійшого варіанту списку дію
                                                                    4 дозапис даних у файл)" << endl;
        cin >> variant;
        switch (variant)
        {
        case 1:
            cucl(povtor);
            break;
        case 2:
            cucl(povtor);
            break;
        case 3:
            cucl(povtor);
            break;
        case 4:
            cucl(povtor);
            break;
        }
    }

}
