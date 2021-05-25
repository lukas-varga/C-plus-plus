#include <iostream>

using namespace std;

int main()
{
    /*
    int number;                         // Whole number
    float decimal;                      // Floating point - 32 bit
    double decimal_1, decimal_2;        // Floating point - 64 bit
	bool alive;                         // Boolean type: 1 = TRUE, 0 = FALSE
    char letter;                        // Character
    string sentence;                    // String
    const float DISCOUNT;               // Constant, can't be changed afterwards

    //int 123number, number?, if;         // Not allowed

    cout << "Int: " << number << endl;
    cout << "Float: " << decimal << endl;
    cout << "Double 1: " << decimal_1 << " Double 2: " << decimal_2 << endl;
    cout << "Bool: " << alive << endl;
    cout << "Letter: " << letter << endl;
    cout << "String: " << sentence << endl;
    cout << "Constant: " << DISCOUNT << endl;

    int x;
    int y;
    x = y + 10;
    cout << x;
    */


    int x = 10;
    cout << "x = " << x++ << endl;
    cout << "x = " << x << endl;
    cout << "x = " << ++x << endl;
    cout << "x = " << x << endl;

    return 0;

}
