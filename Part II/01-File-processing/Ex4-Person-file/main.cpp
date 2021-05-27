#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Person
{
private:
    int number;
    string name;
    int hours;
    float wage;
public:
    Person(){}
    Person(int nmbr, string nm, int h, float w): number(nmbr),name(nm),hours(h),wage(w){}
    displayData()
    {
        cout << number << "\t" << name << "\t" << hours << "\t" << wage << "\t" << endl;
    }
};

int main()
{
    ifstream reader;
    reader.open("data.txt", ios::in);

    if(!reader.good())
    {
        cout << "Unknown error while reading file: data.txt" << endl;
        system("pause");
        return 0;
    }

    // Take column names
    string title;
    getline(reader,title);
    cout << title << endl;

    int num,hours;
    string name;
    float wage;

    Person arr[4];
    int i = 0;

    while ((reader >> num >> name >> hours >> wage) && i < 4)
    {
        arr[i] = Person(num, name, hours,wage);
        i++;
    }

    for (int j=0;j<4; j++)
    {
        arr[j].displayData();
    }

    system("pause");
    return 0;
}
