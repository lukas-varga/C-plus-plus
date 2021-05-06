#include <iostream>

using namespace std;

int main()
{
    double x,y;
    char oper;

    cout << "Welcome to Calculator program!" << endl;
    cout << "Enter two operands and operator e.g.'5*3': " << endl;
    cin >> x >> oper >> y;

    cout<< "= ";
    switch(oper)
    {
        case '+':
            cout << (x+y);
            break;
        case '-':
            cout << (x-y);
            break;
        case '*':
            cout << (x*y);
            break;
        case '/':{
            if(y==0)
            {
                cout << "Division by 0 is not allowed!";
            }
            else
            {
                cout << (x/y);
            }
            break;
        }
        default:
            cout << "Incorrect operator is entered!";
    }
    cout << endl;

    return 0;
}
