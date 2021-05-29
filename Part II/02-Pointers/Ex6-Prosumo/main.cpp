#include <iostream>
#include <time.h>

using namespace std;

void prosumo(int*,int, int*, int*);

int main()
{
    cout << "Array:" << endl;

    int arr[10], sum, prod;
    srand (time(NULL));
    for(int i=0; i<10; i++)
    {
       arr[i] = (rand() % 6) +1;
       cout << arr[i] << " ";
    }
    cout << endl;

    prosumo(&arr[0],10,&sum,&prod);
    cout << "Prod:\t" << prod << endl;
    cout << "Sum:\t" << sum << endl;

    return 0;
}

void prosumo(int* x, int size, int* sum, int* prod)
{
    *sum=0;
    *prod=1;
    for(int i=0; i<10; i++)
    {
        *sum += x[i];
        *prod *= x[i];
    }

}
