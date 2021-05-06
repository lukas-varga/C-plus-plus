#include <iostream>
#include <cstdlib>

using namespace std;

void printTableFor();
void printTableWhile();
void printTableDoWhile();

int main()
{
    printTableFor();
    printTableWhile();
    printTableWhile();

    system("pause");
}

void printTableFor()
{
    cout << "For Table:" << endl;
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++){
            int res = i * j;
            cout << res << "\t";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void printTableWhile()
{
    cout << "While Table:" << endl;
    int i=1;
    while(i<=10)
    {
        int j=1;
        while(j<=10){
            int res = i * j;
            cout << res << "\t";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << endl << endl;
}

void printTableDoWhile()
{
    cout << "DoWhile Table:" << endl;
    int i=1;
    do
    {
        int j=1;
        do
        {
            int res = i * j;
            cout << res << "\t";
            j++;
        }
        while(j<=10);
        cout << endl;
        i++;
    }
    while(i<=10);
    cout << endl << endl;
}
