#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void sort(string names[],int size);

int main(int argc, char *argv[])
{
	string names[5];
	cout << "Please enter 5 names:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Name " << i+1 << ": ";
		cin >> names[i];
	}
    cout << endl << "Sorted names:" << endl;

	sort(names,5);

    system("PAUSE");
    return 0;
}

//implemented insert sort
void sort(string names[],int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            //if (names[i] > names[j])
            if(names[i].compare(names[j]) > 0)
            {
                string temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }


	int i = 0;
	do
    {
        cout << "Name " << i+1 << ": ";
        cout << names[i] << endl;
        i++;
    }while(i<5);
}
