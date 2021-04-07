#include <iostream>

using namespace std;


int main()
{
    double fahr = 0;
    double cels = 0;
    const int CONV_CONST = 32;
    cout << "Welcome to temperature conversion program (Fahr -> Cels)!" << endl;
    cout << "Please enter the temperature in Fahrenheit: " << endl;
    cin >> fahr;

    cels = ((fahr -  CONV_CONST)*5)/9;
    cout << "The temperature in Celsius is: " << endl;
    cout << cels << endl;

    system("PAUSE");
    return 0;
}
