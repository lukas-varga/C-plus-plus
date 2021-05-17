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
    void setData();
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
	return revenue;
}

int main()
{
	Animal a1;
	a1.setData();
	float rev = a1.getRevenue();

	cout << "Revenue: " << rev << endl;

	system("PAUSE");
	return 0;
}
