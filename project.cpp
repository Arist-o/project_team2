
#include <iostream>
#include <Windows.h>
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
    cout << R"(Виберіть що хочете зробити зі списку запропонованих дій:
                                                                    1
                                                                    2
                                                                    3
                                                                    4 )" << endl;
    
}
