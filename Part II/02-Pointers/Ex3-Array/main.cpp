#include <iostream>

using namespace std;

void myFunction(int*,int*);
void print(const int*,const int*);

int main()
{
    cout << "Array!" << endl;

    int numbers[] = {10,20,30};
    int arrSize = *(&numbers + 1) - numbers;

    print(numbers,numbers+arrSize);
    //point at beginning(first el) and end of array(one after last el)
    myFunction(numbers, numbers+arrSize);

    print(numbers,numbers+arrSize);

    return 0;
}

void myFunction(int *ptrStart,int *ptrEnd)
{
    int *ptrTemp = ptrStart;
    while(ptrTemp != ptrEnd)
    {
        ++(*ptrTemp);
        ++ptrTemp;
    }
}

void print(const int *ptrStart,const int *ptrEnd)
{
    const int *curr = ptrStart;
    int i=0;
    while(curr != ptrEnd)
    {
        cout << "[" << i+1 << "]" << *curr << endl;
        ++curr;
        ++i;
    }


    cout << endl;
}
