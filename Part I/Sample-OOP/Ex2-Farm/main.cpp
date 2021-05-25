#include <iostream>
#include <cstdlib>

using namespace std;

class Animal
{
private:
    int animalNum;
    string species;
    float weight;
    bool isStock;
    float dailyPrize;
    float revenue;
    static int animalCounter;
    static float totalRevenue;
public:
    Animal();
    void requestData();
    void display();
    void sell();
    int getAnimalNum();
    bool getIsStock();
    static int getAnimalCounter();
    static float getTotalRevenue();
};

Animal::Animal()
{
    isStock=false;
    animalNum = 0;
}

void Animal::requestData()
{
    cout << "What is the species of animal?"<< endl;
	cin >> species;
	cout << "What is the weight of the animal?" << endl;
	cin >> weight;
	animalCounter++;
	isStock = true;
	animalNum = animalCounter;
}

void Animal::display()
{
    cout << "Number: " << animalNum << "\t ";
    cout << "Species: " << species << "\t ";
    cout << "Weight: " << weight << "\t ";

    string answerStock = (isStock) ? "yes" : "no";
    cout << "Is in stock: " << answerStock << endl;
}

void Animal::sell()
{
    cout << "Enter the daily prize of " << species << ": ";
    cin >> dailyPrize;

	revenue = weight * dailyPrize;
	cout << "Revenue: " << revenue << endl;

    totalRevenue += revenue;
    cout << "Total revenue is: " << totalRevenue << endl;

    isStock = false;
}

int Animal::getAnimalNum()
{
    return animalNum;
}

bool Animal::getIsStock()
{
    return isStock;
}

float Animal::totalRevenue = 0;

float Animal::getTotalRevenue()
{
    return totalRevenue;
}

int Animal::animalCounter = 0;

int Animal::getAnimalCounter()
{
    return animalCounter;
}

int main()
{
    cout << "Hello user and welcome at out farm!" << endl << endl;
    int input = -1;

    Animal animalArr[100] = Animal();

    do
    {
        system("cls");
        cout << "1: Enter animal" << endl;
        cout << "2: Show animal" << endl;
        cout << "3: Sell animal" << endl;
        cout << "0: Exit program" << endl;

        cout << "Input: ";
        cin >> input;
        switch(input)
        {
            case 1:
            {
                system("cls");
                int num = Animal::getAnimalCounter();
                animalArr[num].requestData();
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                for(int i = 0; i<100; i++)
                {
                    if(animalArr[i].getAnimalNum() != 0)
                    {
                        animalArr[i].display();
                    }
                }
                system("pause");
                break;
            }

            case 3:
            {
                system("cls");
                cout << "Enter the number of animal you want to sell:";
                int select;
                cin >> select;
                bool success = false;

                for(int i = 0; i<100; i++)
                {
                    if(animalArr[i].getAnimalNum() == select)
                    {
                        if(animalArr[i].getIsStock())
                        {
                            animalArr[i].sell();
                            success = true;
                        }

                    }
                }

                if(!success)
                {
                    cout << "The animal is not in the stock or the animal number is incorrect!"<<endl;
                }

                system("pause");
                break;
            }
            case 0:
                system("cls");
                cout << "Goodbye!"<<endl;
                system("pause");
                break;
            default:
                system("cls");
                input = -1;
                cout << "Wrong input, try again!" << endl;
                system("pause");
        }
    }while(input != 0);
    return 0;
}



