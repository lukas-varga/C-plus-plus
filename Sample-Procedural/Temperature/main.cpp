#include <iostream>
#include <cstdlib>

using namespace std;

void givenMonth();
void name();
void number();
void printMonth(int number);

void allMonths();
void hottest();

void ascending();
void sort(float numbers[], string sortedMonths[], int SIZE);


const float temperatures[12] = {-1,-3,3,10,15,20,23,20,15,8,4,1};
const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


int main()
{
    cout << "Hello user and welcome at out farm!" << endl << endl;
    int input = -1;

    do
    {
        system("cls");

        cout << "1: Given month" << endl;
        cout << "2: Average of all months" << endl;
        cout << "3: Hottest month" << endl;
        cout << "4: All months (ASC)" << endl;
        cout << "0: Exit program" << endl;

        cout << "Input: ";
        cin >> input;
        system("cls");

        switch(input)
        {
            case 1:
                givenMonth();
                break;
            case 2:
                allMonths();
                system("pause");
                break;
            case 3:
                hottest();
                system("pause");
                break;
            case 4:
                ascending();
                system("pause");
                break;
            case 0:
                cout << "Goodbye!" << endl;
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


void givenMonth()
{
    int input = -1;

    do
    {
        system("cls");

        cout << "1: Text(\"August\")" << endl;
        cout << "2: Selection(\"8\")" << endl;
        cout << "0: Back" << endl;

        cout << "Input: ";
        cin >> input;
        system("cls");

        switch(input)
        {
            case 1:
            {
                name();
                system("pause");
                break;
            }

            case 2:
            {
                number();
                system("pause");
                break;
            }
            case 0:
                return;
            default:
                system("cls");
                cout << "Wrong input, try again!" << endl;
                system("pause");
        }
    }while(input!=0);
}

void name()
{
    string input = "";
    bool done = false;

    do
    {
        system("cls");

        cout << "Enter month (\"August\")" << endl;
        cout << "Input: ";
        cin >> input;
        system("cls");

        for(int i=0;i<12;i++)
        {
            if(input == months[i])
            {
                printMonth(i+1);
                done = true;
                break;
            }
        }

        if(!done)
        {
            system("cls");
            cout << "Wrong input, try again!" << endl;
            system("pause");
        }

    }while(!done);
}

void number()
{
    int input = -1;
    bool done = false;

    do
    {
        system("cls");

        cout << "1: January" << endl;
        cout << "2: February" << endl;
        cout << "3: March" << endl;
        cout << "4: April" << endl;
        cout << "5: May" << endl;
        cout << "6: June" << endl;
        cout << "7: July" << endl;
        cout << "8: August" << endl;
        cout << "9: September" << endl;
        cout << "10: October" << endl;
        cout << "11: November" << endl;
        cout << "12: December" << endl;

        cout << "Input: ";
        cin >> input;
        system("cls");

        for(int i=0;i<12;i++)
        {
            if(input-1 == i)
            {
                printMonth(i+1);
                done = true;
                break;
            }
        }

        if(!done)
        {
            system("cls");
            cout << "Wrong input, try again!" << endl;
            system("pause");
        }
    }while(!done);
}

void printMonth(int number)
{
    int index = number-1;
    cout << "In month " << months[index] << " there is average temperature of " << temperatures[index] << " Celsius" << endl;
}

void allMonths()
{
    system("cls");
    float sum = 0;

    for(int i=0;i<12;i++)
    {
        sum += temperatures[i];
    }
    float avg = sum / 12.0;

    cout << "Average temperature of all months is " << avg << " Celsius" << endl;
}

void hottest()
{
    system("cls");
    float valMax = -1.0;
    int indexMax = -1;

    for(int i=0;i<12;i++)
    {
        if(temperatures[i] > valMax)
        {
            valMax = temperatures[i];
            indexMax = i;
        }
    }

    cout << "Hottest month is " << months[indexMax] << " with average temperature of " << valMax << " Celsius" << endl;
}

void ascending()
{
    float sortedTemp[12];
    string sortedMonths[12];

    for(int i=0;i<12;i++)
    {
        float temp = temperatures[i];
        sortedTemp[i] = temp;

        string month = months[i];
        sortedMonths[i] = month;
    }
    sort(sortedTemp, sortedMonths, 12);

    cout << "Sorted month from the lowest temperature:"<< endl;

    for(int i=0;i<12;i++)
    {
        cout << sortedMonths[i] <<" [" << sortedTemp[i] << " C]" << endl;
    }
}

//bubble sort implementation
void sort(float numbers[], string sortedMonths[], int SIZE)
{
    bool swapped = false;
    int n = SIZE;

    do
    {
        swapped = false;
        for(int i=1; i<n; i++)
        {
            if(numbers[i-1] > numbers[i]){
                float temp = numbers[i-1];
                numbers[i-1] = numbers[i];
                numbers[i] = temp;

                //ADDED
                string tempString = sortedMonths[i-1];
                sortedMonths[i-1] = sortedMonths[i];
                sortedMonths[i] = tempString;
                //ADDED

                swapped = true;
            }
        }
        n--;
    }while(swapped);
}



