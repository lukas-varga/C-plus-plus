#include <iostream>

using namespace std;

void table(float fahr, int STEP, int SIZE);
void feelTemp(double cels);

int main()
{
    int fahr = -1;
    int const STEP = 10;
    int const SIZE = 10;

    do
	{
        cout << "Min Fahrenheit: ";
        cin >> fahr;
	}while(fahr<=0);

    table(fahr, STEP, SIZE);

    system("pause");
}

void table(float fahr, int STEP, int SIZE)
{
    const int CONV_CONST = 32;
    double cels = -1;
    float x_fahr = -1;
    float celsArr[SIZE];

	for(int i=0; i<SIZE; i++)
    {
        x_fahr = fahr + (i * STEP);
        cels = ((x_fahr - CONV_CONST)*5)/9;
        celsArr[i] = cels;
    }

    int i=0;
    while(i<SIZE)
    {
        x_fahr = fahr + (i * STEP);

        cout << "[" << i << "]\t";
        cout << "Fahrenheit: " << x_fahr << "\t| ";
        cout << "Celsius: " << celsArr[i] << " -> ";
        feelTemp(cels);

        cout << endl;
        i++;
    }

    cout << endl;
}

void feelTemp(double cels)
{
    if(cels <= 10)
    {
        cout << "it is cold";
    }
    else if(cels <= 20)
    {
        cout << "it is pleasantly warm";
    }
    else
    {
        cout << "it is getting hot";
    }
}
