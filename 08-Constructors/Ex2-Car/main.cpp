#include <iostream>
#include <cstdlib>

using namespace std;

class Car
{
private:
    string brand;
    int milage;
    static int drivesCT;
public:
    Car();
    Car(string,int);
    ~Car();
    void drive(int);
};

Car::Car():brand("Audi"),milage(0)
{
    cout << "Car created: " << brand << endl;
}

Car::Car(string b, int m):brand(b),milage(m)
{
    cout << "Car created: " << brand << endl;
}

Car::~Car()
{
    cout << "Car removed: " << brand << endl;
}

void Car::drive(int m)
{
    milage += m;
    drivesCT++;
    cout << "Milage of " << brand << ": " << milage <<" miles" <<endl;
    cout << "Number of drives: " << drivesCT << endl << endl;
}

int Car::drivesCT = 0;

int main()
{
    cout << "CARS" << endl;

    Car audi = Car();
    Car porsche = Car("Porsche", 1);

    audi.drive(10);
    porsche.drive(5);
    porsche.drive(12);

    system("pause");
    return 0;
}
