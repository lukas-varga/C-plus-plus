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

int main(){
    Vehicle v1 = Vehicle("Porsche","FSD-1565",150,1998);
    Vehicle v2 = Vehicle("Nissan","HHY-6955",163,2005);

    Car c = Car("Porsche Carrera GT","FSD-1565",150,1998,320.5);
    Truck t = Truck("Mercedes A80","FSD-5689",300,2005,15.5,8);

    v1.displayData();
    cout << endl;
    v2.displayData();
    cout << endl;
    c.displayData();
    cout << endl;
    t.displayData();
    cout << endl;

    system("pause");
    return 0;
};
