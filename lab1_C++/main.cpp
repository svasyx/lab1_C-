#include <iostream>
#include <cstdlib>
#include "cstring"
#include <windows.h>
#include "string.h"
#include "Animal.h"


int main(int argc, const char* argv[])
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char* buff = new char[255];
    Animal c1;
    Animal c2("����", "������", 200);
    Animal c3(c2);
    Animal c4(1.6);
    char name[25] = "���";
    char clss[30] = "������";
    char SecondName[25] = "����";
    char SecondClss[30] = "�����";
    c1.SetName(name);
    c1.SetClass(clss);
    c1.SetWeight(190);
    c4.SetName(SecondName);
    c4.SetClass(SecondClss);
    c1.GetClassBuff(buff, 255);
    printf("%s", buff);
    c1.Print();
    c2.Print();
    c3.Print();
    c4.Print();

    delete[]buff;
    return 0;
}
