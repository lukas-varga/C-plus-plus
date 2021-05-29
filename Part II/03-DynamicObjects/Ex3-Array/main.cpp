#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "How many numbers do you want to enter: ";
    cin >> num;

    //int *arr[num];
    int *arr = new int[num];
    int input;

    for(int i=0; i<num; i++)
    {
        cout << "[" << i+1 << "] number: ";
        cin >> input;
        //arr[i] = new int(input);
        arr[i] = input;
    }

    for(int i=0; i<num; i++)
    {
        //cout << "[" << i+1 << "] " << *arr[i] << "; ";
        cout << "[" << i+1 << "] " << arr[i] << "; ";
    }

    delete [] arr;
    return 0;
}
