#include <iostream>

using namespace std;

class Element
{
public:
    int value;
    Element *next;
};

int main()
{
    cout << "Enter values till 0 is entered!" << endl;

    Element *list = NULL;

    int input = -1;
    do
    {
        cout << "Enter: ";
        cin >> input;

        Element *newEl = new Element;
        newEl->value = input;

        newEl->next = list;
        list = newEl;
    }while(input != 0);

    cout << endl << "List: ";
    Element *pointer = list;
    while(pointer != NULL)
    {
        cout << pointer->value << " ";
        pointer = pointer->next;
    }

    cout << endl;
    system("pause");
    return 0;
}
