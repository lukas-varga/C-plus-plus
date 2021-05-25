#include <iostream>
#include <cstdlib>

using namespace std;

class Vehicle
{
protected:
    string brand;
};

class Car : public Vehicle
{
private:
    int numberPassengers;
public:
    Car();
    Car(string,int);
    void display();
    void boarding(int);
};

Car::Car()
{
    cout << "A new car has been created." << endl;
    cout << "Brand: ";
    cin >> brand;
    cout << "Passenger: ";
    cin >> numberPassengers;
}

void Car::display()
{
    cout << "Car: " << brand << ", number of passengers: "<<numberPassengers<<endl;
}

void Car::boarding(int passNum)
{
    numberPassengers += passNum;
}

class Truck : public Vehicle
{
private:
    int tones;
public:
    Truck();
    Truck(string,int);
    void display();
    void loading(int);
};

Truck::Truck()
{
    cout << "A new truck has been created." << endl;
    cout << "Brand: ";
    cin >> brand;
    cout << "Tones: ";
    cin >> tones;
}

void Truck::display()
{
    cout << "Truck: " << brand << ", tones: "<<tones<<" tones" <<endl;
}

void Truck::loading(int tonesNum)
{
    tones += tonesNum;
}

int main()
{
    cout << "VEHICLES" << endl;

    Car carArr[3] = Car();
    Truck truckArr[2] = Truck();

    int persons, tones;

    for(int i = 0; i<3; i++)
    {
        cout << "Car number: " << i+1 << endl;
		cout << "Number of passengers boarding: ";
		cin >> persons;
		carArr[i].boarding(persons);
    }

    for(int i = 0; i<2; i++)
    {
        cout << "Truck number: " << i+1 << endl;
		cout << "Number of tones: ";
		cin >> tones;
		truckArr[i].loading(tones);
    }

    for(int i = 0; i<3; i++)
    {
		carArr[i].display();
    }

    for(int i = 0; i<2; i++)
    {
		truckArr[i].display();
    }

    system("pause");
    return 0;
}
