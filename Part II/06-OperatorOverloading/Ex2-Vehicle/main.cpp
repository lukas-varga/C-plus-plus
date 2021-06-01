#include "iostream"
#include "cstdlib"

using namespace std;

class Vehicle
{
private:
	string brand;
	string licencePlate;
	int hp;
	int yearOfConstruction;
public:
    Vehicle(string b, string lp, int h, int y): brand(b), licencePlate(lp), hp(h), yearOfConstruction(y) {}
	void displayData()
	{
		cout << "Brand: " << brand << endl;
		cout << "Licence plate: " << licencePlate << endl;
		cout << "Number of HP: " << hp << endl;
		cout << "Year of construction: " << yearOfConstruction << endl;
	}

    bool operator==(Vehicle &b)
    {
        return (this->brand == b.brand &&
                this->licencePlate == b.licencePlate &&
                this->hp == b.hp &&
                this->yearOfConstruction == b.yearOfConstruction);
    }

    friend bool operator<(Vehicle &a, Vehicle &b);
    bool operator>(Vehicle &b);
};

bool operator<(Vehicle &a, Vehicle &b)
{
    return a.yearOfConstruction < b.yearOfConstruction;
}

bool Vehicle::operator>(Vehicle &b)
{
    return this->yearOfConstruction > b.yearOfConstruction;
}

int main()
{
    Vehicle v1 = Vehicle("Porsche","CHU-23",120,1999);
    Vehicle v2 = Vehicle("Porsche","CHU-23",120,2000);

    v1.displayData();
    cout << endl;
    v2.displayData();
    cout << endl;

    string same = (v1.operator==(v2)) ? "true" : "false";
    cout << "Same: " << same << endl;

    string younger = (operator<(v1,v2)) ? "true" : "false";
    cout << "Younger: " << younger << endl;

    string older = (v1.operator>(v2)) ? "true" : "false";
    cout << "Older: " << older << endl;

    system("pause");
    return 0;
};
