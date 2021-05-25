#include <iostream>
#include <cstdlib>

using namespace std;

class Person
{
private:
    string lastName, firstName;
    int age;
public:
    void insertData()
    {
        cout << "Last name: ";
        cin >> lastName;

        cout << "First name: ";
        cin >> firstName;

        cout << "Age: ";
        cin >> age;
    }

    string toString()
    {
        return "Person " + lastName + " " + firstName + " [" + to_string(age) + "]";
    }

    void compare(Person p)
    {
        int diff = age - p.age;
        if(diff > 0)
        {
            cout << toString() << " is older than " << p.toString();
        }
        else if(diff < 0)
        {
            cout << toString() << " is younger than " << p.toString();
        }
        else
        {
            cout << toString() << " has the same age as " << p.toString();
        }
    }
};

int main()
{
    cout << "PERSON" << endl;

    Person p1, p2;

    p1.insertData();
    cout << endl;
    p2.insertData();
    cout << endl;

    p1.compare(p2);
    cout << endl << endl;

    system("pause");
    return 0;
}
