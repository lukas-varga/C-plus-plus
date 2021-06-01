#include <iostream>
#include <cstdlib>

using namespace std;

class Phone
{
protected:
    long number;
    string color;
public:
    Phone(long n, string c): number(n), color(c){}
    virtual void displayData()
    {
        cout << "Number: " << number << "\t Color: " << color << endl;
    }
};

class MobilePhone : public Phone
{
private:
    string network;
public:
    MobilePhone(long n, string c, string net): Phone(n, c), network(net){}
    void displayData()
    {
        cout << "Number: " << number << "\t Color: " << color;
        cout << "\t Network: " << network << endl;
    }
};

class CablePhone : public Phone
{
private:
    float cableLenght;
public:
    CablePhone(long n, string c, float len): Phone(n, c), cableLenght(len){}
    void displayData()
    {
        cout << "Number: " << number << "\t Color: " << color;
        cout << "\t Cable lenght: " << cableLenght << endl;
    }
};

int main()
{
    cout << "Phone!" << endl;

    Phone *tp;

    Phone *p = new Phone(737233303,"blue");
    MobilePhone *m = new MobilePhone(604543693,"black", "t-mobile");
    CablePhone *c = new CablePhone(737233346,"red",1.5);

    tp = p;
    tp->displayData();

    tp = m;
    tp->displayData();

    tp = c;
    tp->displayData();

    system("pause");
    return 0;
}
