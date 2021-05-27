#include <iostream>

using namespace std;

void swap(int&,int&);
void swap(int*,int*);

int main()
{
    cout << "Swap!" << endl;

    int a = 1;
    int b = 3;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    int *ptrA = &a;
    int *ptrB = &b;
    swap(ptrA,ptrB);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    swap(&a,&b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}

void swap(int &x,int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
