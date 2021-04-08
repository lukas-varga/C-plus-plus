#include <iostream>

using namespace std;

float decimal();
float squareCalc(float);
float radius();
void circular(float);
const float constant_pi = 3.14;

int main()
{
    cout << "Hello user to the area calculating app!" << endl << endl;

    float dec = decimal();
    float square = squareCalc(dec);
    cout << "Square of number " << dec << " is " << square << endl << endl;

    float rad = radius();
    circular(rad);

    return 0;
}

float decimal()
{
    float dec = 0;
    cout << "Please enter a decimal number: ";
    cin >> dec;
    return dec;
}

float squareCalc(float number)
{
    float square = number * number;
    return square;
}

float radius()
{
    float rad = 0;
    cout << "Please enter a radius: ";
    cin >> rad;
    return rad;
}

void circular(float rad)
{
    float area = 0;
    area = squareCalc(rad) * constant_pi;
    cout << "Area of circle with radius " << rad << " is " << area << endl << endl;

}
