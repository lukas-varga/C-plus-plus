#include "cstdlib"
#include "iostream"

using namespace std;

class Vehicle
{
private:
    string brand;
    string licencePlate;
    int ps;
    int constructionYear;
public:
    int init = 1;
    int *ptrInit = &init;
    Vehicle()
    {
        cout << "Empty Vehicle was created!"<<endl;
    }
    Vehicle(string b, string l, int p, int c): brand(b),licencePlate(l),ps(p),constructionYear(c)
    {
        cout << "Vehicle with given data was created!"<<endl;
    }
    void displayData(){
        cout << "Brand: " << brand << endl;
        cout << "Licence Plate: " << licencePlate << endl;
        cout << "PS: " << ps << endl;
        cout << "Construction Year: " << constructionYear << endl;
    }
};

class Car : public Vehicle
{
private:
    float maxSpeed;
public:
    Car()
    {
        cout << "Empty Car was created!" <<endl;
    }

    Car(string b, string l, int p, int c, float ms): Vehicle(b,l,p,c), maxSpeed(ms)
    {
       cout <<  "Type: Car"<<endl;
    }

    displayData()
    {
        Vehicle::displayData();
        cout << "Maximum speed: " << maxSpeed << endl;
    }
};
class Truck : public Vehicle
{
private:
    float maxLoad;
    int numberWheels;
public:
    Truck()
    {
        cout << "Empty Truck was created!"<<endl;
    }

    Truck(string b, string l, int p, int c, float ml, int nw): Vehicle(b,l,p,c), maxLoad(ml), numberWheels(nw)
    {
       cout <<  "Type: Truck"<<endl;
    }

    displayData()
    {
        Vehicle::displayData();
        cout << "Maximum Load: " << maxLoad << endl;
        cout << "Number of Wheels: " << numberWheels << endl;
    }
};

int main()
{
    Car c = Car();
    Truck t = Truck();
    Car c2 = Car();

    Car *ptrC = &c;
    Truck *ptrT;
    ptrT = &t;
    Car &refC2 = c2;

    c = Car("Porsche Carrera GT","FSD-1565",150,1998,320.5);
    t = Truck("Mercedes A80","FSD-5689",300,2005,15.5,8);\
    c2 = Car("BMW M3","ABC-4951",100,2000,300.5);
    cout << endl;
    cout << endl;

    ptrC -> displayData();
    cout << endl;
    ptrT -> displayData();
    cout << endl;
    refC2.displayData();
    cout << endl;

    cout << endl << "init: " << ptrC -> init << endl;
    cout << "val of ptrInit: " << *ptrC -> ptrInit << endl;
    ptrC -> init = 2;
    cout << "init: " << ptrC -> init << endl;

    cout << endl << "init: " << refC2.init << endl;
    cout << "val of ptrInit: " << refC2.ptrInit << endl;
    refC2.init = 2;
    cout << "init: " << refC2.init << endl;

    system("pause");
    return 0;
};
