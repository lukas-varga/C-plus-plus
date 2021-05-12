#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    cout << "Hello user and welcome at out farm!" << endl << endl;

    const int SIZE = 50;
    int animals[SIZE];

    for(int i=0; i<SIZE; i++)
    {
        animals[i] = i+1;
    }

    for(int i=0; i<SIZE; i++)
    {
        cout << "Pos: " << i << "\t | Animal number:\t" << animals[i] << endl;
    }
}



