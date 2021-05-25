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
    void setData(void);
    float getRevenue(void);
};

void Animal::setData()
{
    cout << "How is the daily price?"<< endl;
	cin >> dailyPrice;
	cout << "What is the weight of the animal?" << endl;
	cin >> weight;
}

float Animal::getRevenue()
{
	revenue = weight * dailyPrice;
	cout << "Revenue: " << revenue << endl;
	return revenue;
}

int main()
{
	Animal a1, a2;
    Animal animalArr[2];
    for(int i=0; i<2; i++)
    {
        cout << "Animal["<< i+1 <<"]: "<< endl;
        animalArr[i].setData();
        cout << endl;
    }

    float total = 0;
    for(int i=0; i<2; i++)
    {
        cout << "Animal["<< i+1 <<"]: ";
        total += animalArr[i].getRevenue();
    }
    cout << "Total revenue: " << total << endl;

	system("PAUSE");
	return 0;
}

