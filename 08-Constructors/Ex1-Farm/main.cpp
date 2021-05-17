#include <iostream>
#include <cstdlib>

using namespace std;

class Animal
{
private:
    float revenue;
    float dailyPrice;
    float weight;
public:
    Animal(void);
    Animal(int,int);
    void Request_data();
    void Calculate_revenue(void);
};

Animal::Animal()
{
    Request_data();
    cout << "Animal created with prize " << dailyPrice << " and weight " << 20 << endl;
}

Animal::Animal(int p, int w): dailyPrice(p), weight(w)
{
    cout << "Animal created with prize " << dailyPrice << " and weight " << 20 << endl;
}

void Animal::Request_data()
{
    cout << "How is the daily price?"<< endl;
	cin >> dailyPrice;
	cout << "What is the weight of the animal?" << endl;
	cin >> weight;
}

void Animal::Calculate_revenue()
{
	revenue = weight * dailyPrice;
	cout << "Revenue: " << revenue << endl << endl;
}

int main()
{
	Animal a1 = Animal(10,20);
	a1.Calculate_revenue();

    Animal a2 = Animal();
    a2.Calculate_revenue();

	system("PAUSE");
	return 0;
}
