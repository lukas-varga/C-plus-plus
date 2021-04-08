#include <iostream>

using namespace std;

void Calculate_revenue();
void Data_query();

int weight;
float dailyPrize;
float revenue;

int main()
{
    cout << "Hello user and welcome at out farm!" << endl << endl;

    Data_query();
    Calculate_revenue();

    system("pause");
    return 0;
}

void Data_query()
{
    cout << "Please enter the weight of the pig: ";
    cin >> weight;

    cout << "Please enter the daily prize of the pig: ";
    cin >> dailyPrize;
}

void Calculate_revenue()
{
    revenue = weight * dailyPrize;
    cout << "Revenue is: " << revenue << endl;
}



