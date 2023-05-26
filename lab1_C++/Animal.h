
class Animal
{
private:
    char* _name;
    char* _clss;
    double _weight;

public:
    Animal();
    Animal(const char* name, const char* clss, double weight);
    Animal(const Animal& original);
    Animal(int x);
    ~Animal();
    int SetName(char* name);
    char* GetName();
    char* GetNameBuff(char* buff, int size);
    int SetClass(char* clss);
    char* GetClass();
    char* GetClassBuff(char* buff, int size);
    int SetWeight(double weight);
    double GetWeight();
    void Print();


};

