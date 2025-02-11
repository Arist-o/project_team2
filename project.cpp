#include <iostream>
#include <Windows.h>
#include "Ahaw.h"
#include "Viktor.h"
using namespace std;
struct sportsmen
{
    char prizv[50];
    char name[50];
    double speed_run = 0;
    double km3_run = 0;
    int pres = 0;
    double jump = 0;
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int variant = 0,variant2=0,kilk=0;
    bool povtor = true;
    fstream file;
    sportsmen s;
    while (povtor)
    {
        cout << R"(Виберіть що хочете зробити зі списку запропонованих дій:
                                                                    1 Створення файлу
                                                                    2 Прочитати файл на екран
                                                                    3 Вибрати з дальнійшого варіанту списку дій для дозапису в файл
                                                                    4 дозапис даних у файл)" << endl;
        cin >> variant;
        switch (variant)
        {
        case 1:
            create_file(file, s,kilk);
            cucl(povtor);
            break;
        case 2:
            read_file(file);
            cucl(povtor);
            break;
        case 3:
            cout << "Введіть варіант: ";
            cin >> variant2;
            switch (variant2)
            {
            case 1:
                Ahaw_1();
                break;
            case 2:
                break;
            case 3:
                Ahaw_3();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            }
            cucl(povtor);
            break;
        case 4:
            dopus(file, s,kilk);
            cucl(povtor);
            break;
        }
    }

}

