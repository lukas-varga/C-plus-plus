#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort(int numbers[], int SIZE);
void showNum(int numbers[], int SIZE);

int main()
{
    srand(time(NULL));
    const int SIZE = 10;
    int numbers[SIZE];

    for(int i=0; i<SIZE; i++)
    {
        int num = 1 + rand() % (100-0);
        numbers[i] = num;
    }

    cout << "Random:\t";
    showNum(numbers,SIZE);
    cout << endl;

    sort(numbers, SIZE);

    cout << endl;
    cout << "Sorted:\t";
    showNum(numbers,SIZE);

    system("pause");
    return 0;
}

//bubble sort implementation
void sort(int numbers[], int SIZE)
{
    bool swapped = false;
    int n = SIZE;

    do
    {
        swapped = false;
        for(int i=1; i<n; i++)
        {
            if(numbers[i-1] > numbers[i]){
                int temp = numbers[i-1];
                numbers[i-1] = numbers[i];
                numbers[i] = temp;


                swapped = true;
            }
        }

        cout << "Steps:\t";
        showNum(numbers,SIZE);
        n--;
    }while(swapped);
}

void showNum(int numbers[], int SIZE)
{
    for(int i=0; i<SIZE; i++)
    {
        cout << numbers[i];
        if(i==SIZE-1){
                cout << endl;
            continue;
        }
        cout << ", ";
    }
}
