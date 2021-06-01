#include <iostream>
#include <cstdlib>

using namespace std;

class Vehicle
{
protected:
    int number;
public:
    Vehicle(){}//Default constructor
    Vehicle(int numb):number(numb){} // Constructor with member initializer list
    int getNumber(){ return number; }
};

class Car: public Vehicle
{
friend class ListOfCars;
// Data members
private:
    int carNo;
    float weight;
    Car  *successor; // Concatenation pointer to the successor
// Member functions
public:
// Constructor
    Car (int numb = 0,int no = 0, float wei = 0.0): Vehicle(numb), carNo(no), weight(wei), successor(0){}
    ~Car(){ delete successor; }
    int getcarNo() const { return carNo; }
    float getWeight() const{ return weight; }
    Car *next(){ return successor; }

    void print()
    {
        cout << "Number: " << number << ", CarNo: " << carNo << ", weight: " << weight << endl;
    }
};

class ListOfCars // List of cars
{
private:
    Car* head;
public:
    ListOfCars()
    {
        head = 0;
    }
    ~ListOfCars()
    {
        delete head;
    }

    void add(Car *newCar)
    {
        if (head == 0)
        {
            head = newCar;
        }
        else
        {
            newCar->successor = head;
            head = newCar;
        }
    }

    Car* remove()
    {
        Car *c = head;
        if (c != 0)
        {
            cout << "Following car was removed!" << endl;
            c->print();

            head = c->successor;
            c->successor = 0;
        }
        return c;
    }

    void displayAll()
    {
        Car *c;
        for (c = head; c != NULL; c = c->successor)
        {
            c->print();
        }
    }

    Car* search(int searchedNum)
    {
        Car *c;
        for (c = head; c != NULL; c = c->successor)
        {
            if(c->getcarNo() == searchedNum)
            {
                return c;
            }
        }

        return 0;
    }

    void clear()
    {
        Car *nextCar;
        while(head != NULL)
        {
            nextCar = head->successor;
            delete head;
            head = nextCar;
            cout << "Car removed!" << endl;
        }
    }
};

int main ()

{
    int selection = 1;
    ListOfCars list;
    int numb, carNo;
    float wei;
    Car *kp;

    do
    {
        system("cls");

        cout << "---- CAR MANAGEMENT ----" << endl;
        cout << "1. Create a new car" << endl;
        cout << "2. Delete last car" << endl;
        cout << "3. Show list" << endl;
        cout << "4. Search for CarNo" << endl;
        cout << "0. Exit program" << endl;
        cout << "> Make a selection [Return]: ";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
            case 0: // End
                break;
            case 1: // Create
            {
                system("cls");

                cout << "Please fill following data!" << endl;
                cout << "Number: ";
                cin >> numb;

                cout << "Car No: ";
                cin >> carNo;

                cout << "Weight: ";
                cin >> wei;

                kp = new Car(numb, carNo, wei);
                list.add(kp);

                system("pause");
                break;
            }

            case 2: // Delete
            {
                system("cls");

                list.remove();

                system("pause");
                break;
            }
            case 3: // List of all cars
            {
                system("cls");

                list.displayAll();

                system("pause");
                break;
            }
            case 4: // Search for car by carNo. and if found, then output number of passengers/weight
             {
                system("cls");


                cout << "Enter \'Car No\' you are looking for: ";
                cin >> carNo;

                kp = list.search(carNo);
                if(kp == 0)
                {
                    cout << "Car not found!" << endl;
                }
                else
                {
                    cout << "Car found!" << endl;
                    kp->print();
                }

                system("pause");
                break;
             }
            default: // Incorrect input
                break;
        }
    } while (selection != 0);

    //Delete all elements of the list
    list.clear();

    system("pause");
    return 0;
}
