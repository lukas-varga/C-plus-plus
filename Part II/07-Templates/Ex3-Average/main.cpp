#include <iostream>

using namespace std;

template <class T>
float average(T[],int);

template <class T>
float average(T arr[],int n)
{
    T sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    return (float)(sum/(float)n);
}

int main()
{
    cout << "Average!" << endl;

    int intArr[] = {1, 2, 3,4};
    float floatArr[] = {2, 3.5, 5};

    cout << "Int: " << average(intArr,4) << endl;
    cout << "Float: " << average(floatArr, 3)<< endl;

    return 0;
}
