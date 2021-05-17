#include <iostream>

using namespace std;

int main()
{
    //Conditional structure: if and else

    int a;

    cout << "Value for a: ";
    cin >> a;

    if(a == 42)
        cout << "Variable has the value 42" << endl;

    // Relational Operators            Example:
    // >     greater than              5 > 4 is TRUE
    // <     less than                 4 < 5 is TRUE
    // >=    greater than or equal     4 >= 4 is TRUE
    // <=    less than or equal        3 <= 4 is TRUE
    // ==    equal to                  5 == 5 is TRUE
    // !=    not equal to              5 != 4 is TRUE

    // Logical Operators
    // &&    Logical AND               Returns TRUE if both its operands are true
    // ||    Logical OR                Returns TRUE if either (or both) of its operands are true
    // !     Logical NOT               Returns TRUE if its operand is false

	//Switch Case Statement

    cout << "Value for a: ";
    cin >> a;

    switch(a)
    {
        case 10:
        {
            cout << "Value is 10" << endl;
            break;
        }
        case 15:
        {
            cout << "A prime number..." << endl;
        }
        case 21:
        {
            cout << "Another prime number!" << endl;
        }
        default:
        {
            cout << "Ups!" << endl;
        }
    }

    //Loops

    int b=1, c=1;

    //For loop
    for(int a=1;a<=5;a++)
    {
        cout << "Value of a: " << a << endl;
    }

    cout << endl;
    //While loop

    while(b<5)
    {
        cout << "Value of b: " << b << endl;
        b = b + 1;
    }

    cout << endl;
    //Do While loop

    do
    {
        cout << "Value of c: " << c << endl;
        c++;
    }while(c<5);

    return 0;
}
