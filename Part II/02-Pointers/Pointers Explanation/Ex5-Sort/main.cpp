#include <iostream>
#include <cstdlib>

using namespace std ;

void sort (int*,int);
void sortI (int*,int);
void print (const int *ptrStart,const int *ptrEnd);

int main ( void )
{
    int a [10], i;

    cout << "Unsorted Array : " << endl;
    for ( i =0; i <10; i ++)
    {
        a [i]= rand()%100;
        cout << a [i] << " ";
    }

    cout << endl << endl;
    sortI(a, 10);
    cout << endl;

    cout << "Sorted Array : " << endl;
    for ( i =0; i <10; i ++)
        cout << a [i] << " ";

    cout << endl;

    system("pause");
    return 0;
}

void sort(int *x, int size)
{
    int *start = x + 1;
    int *end = x + size;

    bool swapped = false;
    do
    {
        swapped = false;
        start = x + 1;
        while(start != end)
        {
            if(*(start-1) > *start){
                int temp = *(start-1);
                *(start-1) = *start;
                *start = temp;


                swapped = true;
            }
            ++start;
        }

        print(x,x + size);

        end--;
    }while(swapped);
}

void sortI(int *x, int size)
{
    int n = size;

    bool swapped = false;
    do
    {
        swapped = false;
        for(int i=1; i<n; i++)
        {
            if(x[i-1] > x[i]){
                int temp = x[i-1];
                x[i-1] = x[i];
                x[i] = temp;

                swapped = true;
            }
        }

        print(x,x + size);

        n--;
    }while(swapped);
}

void print(const int *ptrStart,const int *ptrEnd)
{
    const int *curr = ptrStart;
    while(curr != ptrEnd)
    {
        cout << *curr << " ";
        ++curr;
    }

    cout << endl;
}
