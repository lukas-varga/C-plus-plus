#include <iostream>

using namespace std;

float calcRev(int,float);

int main()
{
    int weight;
    float dailyPrize;
    float revenue;

    cout << "Hello user and welcome at out farm!" << endl;

    cout << "Please enter the weight of the pig: " << endl;
    cin >> weight;

    cout << "Please enter the daily prize of the pig: " << endl;
    cin >> dailyPrize;

    revenue = calcRev(weight,dailyPrize);
    cout << "Revenue is: " << revenue << endl;

    system("pause");
    return 0;
}

float calcRev(int weight, float prize)
{
    return weight * prize;
}



