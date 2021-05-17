#include <iostream>
#include <cstdlib>

using namespace std;

string names[10];
double prices[10];

void newItem();
void showItems();
void sortItems();
void sort(double numbers[], string sortedNames[], int SIZE);

int main()
{
    for(int i=0; i<10; i++)
    {
        names[i] = "";
        prices[i] = -1.0;
    }

    cout << "Shopping list!" << endl << endl;
    int input = -1;

    do
    {
        system("cls");
        cout << "1: New item" << endl;
        cout << "2: Show items" << endl;
        cout << "3: Sort items" << endl;
        cout << "0: Exit" << endl;

        cout << "Input: ";
        cin >> input;
        switch(input)
        {
            case 1:
                system("cls");
                newItem();
                system("pause");
                break;
            case 2:
                system("cls");
                showItems();
                system("pause");
                break;
            case 3:
                system("cls");
                sortItems();
                system("pause");
                break;
            case 0:
                system("cls");
                system("pause");
                break;
            default:
                system("cls");
                cout << "Wrong input, try again!" << endl;
                system("pause");
        }
        cout << endl;
    }while(input != 0);
    return 0;
}


void newItem()
{
    string name;
    double price;

    cout << "Name: ";
    cin >> name;

    cout << "Price: ";
    cin >> price;

    for(int i=0; i<10; i++)
    {
        if(prices[i] == -1)
        {
            names[i] = name;
            prices[i] = price;
            break;
        }
    }
}

void showItems()
{
    int counter = 0;
    for(int i=0; i<10; i++)
    {
        if(prices[i] == -1)
        {
            break;
        }
        cout << names[i] << ":\t" << prices[i] << " $" << endl;
        counter++;
    }

    cout << "Number of items in the list: " << counter << endl;
}

void sortItems()
{
    double sortedPrices[10];
    string sortedNames[10];

    for(int i=0;i<10;i++)
    {
        double price = prices[i];
        sortedPrices[i] = price;

        string name = names[i];
        sortedNames[i] = name;
    }
    sort(sortedPrices, sortedNames, 10);

    cout << "Sorted list based on the price:"<< endl;

    for(int i=0;i<10;i++)
    {
        if(sortedPrices[i]==-1){
            continue;
        }
        cout << sortedNames[i] <<":\t" << sortedPrices[i] << " $" << endl;
    }
}

//bubble sort implementation
void sort(double numbers[], string sortedNames[], int SIZE)
{
    bool swapped = false;
    int n = SIZE;

    do
    {
        swapped = false;
        for(int i=1; i<n; i++)
        {
            if(numbers[i-1] > numbers[i]){
                double tempPrice = numbers[i-1];
                numbers[i-1] = numbers[i];
                numbers[i] = tempPrice;

                //ADDED
                string tempString = sortedNames[i-1];
                sortedNames[i-1] = sortedNames[i];
                sortedNames[i] = tempString;
                //ADDED

                swapped = true;
            }
        }
        n--;
    }while(swapped);
}


