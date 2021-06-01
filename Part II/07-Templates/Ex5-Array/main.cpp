#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class T>
void display(T[],int);

template <class T>
void sort(T[],int);

template <class T>
void swap(T*,T*);

int main()
{
    int num;
    cout << "Array!" << endl;
    cout << "How many numbers you want to sort: ";
    cin >> num;

    int intArr[num];
    srand(time(NULL));

    for(int i=0; i<num; i++)
    {
        intArr[i] = rand() % 6 + 1;
    }

    string strArr[4] = {"Anna", "Jan", "Cecil" ,"Bob"};

    display(intArr,num);
    sort(intArr,num);
    display(intArr,num);

    cout << endl;

    display(strArr,4);
    sort(strArr,4);
    display(strArr,4);

    system("pause");
    return 0;
}

template <class T>
void display(T arr[],int size)
{
    cout << "Output: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

template <class T>
void sort(T arr[],int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i] > arr[j])
            {
                swap<T>(&arr[i], &arr[j]);

            }
        }
    }
}

template <class T>
void swap(T* a,T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
