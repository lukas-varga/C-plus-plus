#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
T add(T first, T second)
{
    return first + second;
}

int main()
{
    int answer;
    cout << "Addition and Linking!" << endl;
    cout << "[1] Adding integer value" << endl;
    cout << "[2] Adding floating point value" << endl;
    cout << "[3] Linking a string" << endl;
    cout << "Enter: ";
    cin  >> answer;

    system("cls");
    switch(answer)
    {
    case 1:
        {
            int first, second;
            cout << "Adding integer value" << endl;
            cout << "First: ";
            cin >> first;
            cout << "Second: ";
            cin >> second;

            int result = add<int>(first,second);
            cout << "Result: " << result << endl;
            break;
        }
    case 2:
        {
            float first, second;
            cout << "Adding floating point value" << endl;
            cout << "First: ";
            cin >> first;
            cout << "Second: ";
            cin >> second;

            float result = add<float>(first,second);
            cout << "Result: " << result << endl;
            break;
        }
    case 3:
        {
            string first, second;
            cout << "Adding floating point value" << endl;
            cout << "First: ";
            cin >> first;
            cout << "Second: ";
            cin >> second;

            string result = add<string>(first,second);
            cout << "Result: " << result << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
