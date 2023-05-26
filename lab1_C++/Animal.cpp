#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#include "Animal.h"
#define FU

using namespace::std;

Animal::Animal()
{
    _name = new char[10];
    strcpy(_name, "NoName");
    _clss = new char[10];
    strcpy(_clss,"NoClass");
    _weight = 0;
#ifdef FU
    cout << "ініціалізація () \n";
#endif
}

Animal::Animal(const char* name, const char* clss, double weight)
{
    this->_name = new char[strlen(name) + 1];
    if (_name == 0)
    {
        exit(1);
#ifdef FU
        cout << "проблема з памʼяттю \n";
#endif
    }
    strcpy(_name, name);
    this->_clss = new char[strlen(clss) + 1];
    if (_clss == 0)
    {
        exit(1);
#ifdef FU
        cout << "проблема з памʼяттю \n";
#endif
    }
    strcpy(_clss, clss);
    if (weight > 0)
    {
        this->_weight = weight;
    }
#ifdef FU
    cout << "ініціалізація (параметри) \n";
#endif

}
Animal::Animal(const Animal& original)
{
    _name = new char[strlen(original._name) + 1];
    if (!_name)
    {
#ifdef FU
        cout << "Memory problem\n";
#endif
        exit(1);
    }
    _clss = new char[strlen(original._clss) + 1];
    if (!_clss)
    {
#ifdef FU
        cout << "Memory problem\n";
#endif
        exit(1);
    }
    else
    {
        strcpy(_name, original._name);
        strcpy(_clss, original._clss);
    }
    _weight = original._weight;
#ifdef FU
    cout << "ініціалізація (копіювання) \n";
#endif
}

Animal::Animal(int x)
{
    if (x > 0)
    {
        this->_weight = x;
    }
    else
    {
#ifdef FU
        cout << "Initialisation problem\n";
#endif
        exit(2);
    }
#ifdef FU
    cout << "ініціалізація (перетворення) \n";
#endif
}

Animal::~Animal()
{
#ifdef FU
    cout << "знищення\n";
#endif
    if (_name != 0)
    {
        delete[]_name;
    }
    else
    {

#ifdef FU
        cout << "_name points to NULL\n";
#endif
    }
    if (_clss != 0)
    {
        delete[]_clss;
    }
    else
    {
#ifdef FU
        cout << "_clss points to NULL\n";
#endif
    }

}

char* Animal::GetName()
{
    /*
    pomylka
    char* name="\0";
    name=_name;
    */
    char* name;
    name = new char[strlen(_name) + 1];
    if (name != 0)
    {
        strcpy(name, _name);
    }
    return name;
}

char* Animal::GetNameBuff(char* buff, int size)
{
    if (buff != NULL && size > strlen(_name))
    {
        strcpy(buff, _name);
    }
    else
    {
#ifdef FU
        printf("not enough memory\n");
#endif
    }
    return buff;
}

int Animal::SetName(char* name)
{
    if (_name != NULL)
    {
        delete[]_name;
    }
    this->_name = new char[strlen(name) + 1];
    if (_name != NULL)
    {
        strcpy(_name, name);
    }
    else
    {
        return 0;
    }
    return 1;
}

void Animal::Print()
{
    cout << endl << _name << endl << _clss << endl << _weight << endl;
}

int Animal::SetWeight(double weight)
{
    if (weight > 0)
    {
        _weight = weight;
        return 0;
    }
    else
    {
        //#ifdef FU
        cout << "Weight cannot be 0 or less \n";
        //#endif
        return 1;

    }
}

double Animal::GetWeight()
{
    return _weight;
}

int Animal::SetClass(char* clss)
{
    if (_clss != NULL)
    {
        delete[]_clss;
    }
    this->_clss = new char[strlen(clss) + 1];
    if (_clss != NULL)
    {
        strcpy(_clss, clss);
    }
    else
    {
        return 0;
    }
    return 1;
}

char* Animal::GetClass()
{
    char* clss;
    clss = new char[strlen(_clss) + 1];
    if (clss != 0)
    {
        strcpy(clss, _clss);
    }
    return clss;
}

char* Animal::GetClassBuff(char* buff, int size)
{
    if (buff != NULL && size > strlen(_clss))
    {
        strcpy(buff, _clss);
    }
    else
    {
#ifdef FU
        printf("not enough memory\n");
#endif
    }
    return buff;
}

