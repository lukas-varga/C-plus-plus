#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));   //random number generator

    int randomNum = 1 + rand() % (100-0);   //number 1-100
    int guessNum = -1;
    do
    {
        cout << "Enter a guess: ";
        cin >> guessNum;

        if(guessNum > randomNum)
            cout << "Too large" << endl << endl;
        else if(guessNum < randomNum)
            cout << "Too small" << endl << endl;
    }while(randomNum != guessNum);

    cout << "Congratulations you have won" << endl;
    cout << "The generated number was " << randomNum << endl;
    return 0;
}
