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
    Vehicle(){}
    Vehicle(string b, string l, int p, int c): brand(b),licencePlate(l),ps(p),constructionYear(c){}
    void init(){};
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
    Car(): Vehicle("BRAND","XXX-XXXX",100,2000), maxSpeed(200){}
    Car(string b, string l, int p, int c, float ms): Vehicle(b,l,p,c), maxSpeed(ms){}
    static Car* init(Car *c)
    {
        string brand, licencePlate;
        int ps, constructionYear;
        float maxSpeed;

        cout << "Brand: ";
        cin >> brand;
        cout << "Licence plate: ";
        cin >> licencePlate;
        cout << "PS: ";
        cin >> ps;
        cout << "Construction year: ";
        cin >> constructionYear;

        cout << "Max speed: ";
        cin >> maxSpeed;

        c = new Car(brand,licencePlate,ps,constructionYear,maxSpeed);
        return c;
    }
    void displayData()
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
    Truck(): Vehicle("BRAND","XXX-XXXX",100,2000), maxLoad(10), numberWheels(8){}
    Truck(string b, string l, int p, int c, float ml, int nw): Vehicle(b,l,p,c), maxLoad(ml), numberWheels(nw){}
    static Truck* init(Truck* t)
    {
        string brand, licencePlate;
        int ps, constructionYear, numberWheels;
        float maxLoad;

        cout << "Brand: ";
        cin >> brand;
        cout << "Licence plate: ";
        cin >> licencePlate;
        cout << "PS: ";
        cin >> ps;
        cout << "Construction year: ";
        cin >> constructionYear;

        cout << "Load: ";
        cin >> maxLoad;
        cout << "Num. of wheels: ";
        cin >> numberWheels;

        t = new Truck(brand,licencePlate,ps,constructionYear,maxLoad,numberWheels);
        return t;
    }
    void displayData()
    {
        Vehicle::displayData();
        cout << "Maximum Load: " << maxLoad << endl;
        cout << "Number of Wheels: " << numberWheels << endl;
    }
};

int main()
{
    cout << "CARS" << endl;
    const int SIZE = 1;
    string brand, licencePlate;
    int ps, constructionYear;

    Car *cars[SIZE];
    float maxSpeed;
    for(int i=0; i<SIZE; i++)
    {
        cars[i] = Car::init(cars[i]);
    }

    cout << endl <<"TRUCKS" << endl;
    Truck *trucks[SIZE];
    float load, numWheels;
    for(int i=0; i<SIZE; i++)
    {
        trucks[i] = Truck::init(trucks[i]);
    }


    cout << endl << "Display CARS" << endl;
    for(int i=0; i<SIZE; i++)
    {
        cars[i]->displayData();
    }

    cout << endl << "Display TRUCKS" << endl;
    for(int i=0; i<SIZE; i++)
    {
        trucks[i]->displayData();
    }

    delete [] cars;
    delete [] trucks;

    system("pause");
    return 0;
};
