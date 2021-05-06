#include <iostream>

using namespace std;

void table(int fahr, int step, int maxTemp);
void feelTemp(double cels);

int main()
{
    int fahr = -1;
    int step = -1;
    int maxTemp = -1;

    do
	{
        cout << "Min Fahrenheit: ";
        cin >> fahr;
	}while(fahr<=0);

    cout << "Step: ";
    cin >> step;

    cout << "Max Fahrenheit: ";
    cin >> maxTemp;

    table(fahr, step, maxTemp);

    system("pause");
}

void table(int fahr, int step, int maxTemp)
{
    const int CONV_CONST = 32;
    double cels = -1;
    double x_fahr = fahr;

    while(x_fahr <= maxTemp)
    {
        cels = ((x_fahr - CONV_CONST)*5)/9;
        cout << "Fahrenheit: " << x_fahr << "\t| ";
        cout << "Celsius: " << cels << " -> ";
        feelTemp(cels);

        cout << endl;
        x_fahr += step;
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
        cout << "it is getting";
    }
}
