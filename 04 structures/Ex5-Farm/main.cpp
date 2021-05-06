#include <iostream>
#include <cstdlib>

using namespace std;

string species;
int animalNumber;
int weight;
bool isStock;

float totalRev = 0;

void addAnimal();
void displayAnimal();
void sellAnimal();

int main()
{
    cout << "Hello user and welcome at out farm!" << endl << endl;
    int input = -1;

    do
    {
        system("cls");
        cout << "1: Add animal" << endl;
        cout << "2: Display animal" << endl;
        cout << "3: Sell animal" << endl;
        cout << "0: Exit program" << endl;

        cout << "Input: ";
        cin >> input;
        switch(input)
        {
            case 1:
                system("cls");
                addAnimal();
                system("pause");
                break;
            case 2:
                system("cls");
                displayAnimal();
                system("pause");
                break;
            case 3:
                system("cls");
                sellAnimal();
                system("pause");
                break;
            case 0:
                system("cls");
                system("pause");
                return 0;
            default:
                system("cls");
                cout << "Wrong input, try again!" << endl;
                system("pause");
        }
        cout << endl;
    }while(input != 0);
}


void addAnimal()
{
    cout << "Enter species: ";
    cin >> species;

    cout << "Enter animal number: ";
    cin >> animalNumber;

    cout << "Enter weight: ";
    cin >> weight;

    isStock = true;
}

void displayAnimal()
{
    cout << "Species: " << species << endl;
    cout << "Animal number: " << animalNumber << endl;
    cout << "Weight: " << weight << endl;

    string answerStock = (isStock) ? "yes" : "no";
    cout << "Is in stock: " << answerStock << endl;
}

void sellAnimal()
{
    int selectedAnim;
    if(!isStock){
        cout << "There isn't any animal in stock!" << endl;
    }
    else
    {
        cout << "Enter animal number to sell: ";
        cin >> selectedAnim;
        if(selectedAnim != animalNumber){
            cout << "Entered number doesn't correspond to animal in stock!" << endl;
        }
        else
        {
            float dailyPrize;
            cout << "Enter the daily prize of " << species << ": ";
            cin >> dailyPrize;

            float revenue = weight * dailyPrize;
            cout << "Revenue is: " << revenue << endl;

            totalRev += revenue;
            cout << "Total revenue is: " << totalRev << endl;

            isStock = false;
        }
    }
}



