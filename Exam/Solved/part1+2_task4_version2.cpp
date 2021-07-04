// Deggendorf Institute of Technology - vhb Exam
// Examination subject:     Programming in C++ / Part 1+2 (6 ECTS)
// Semester:                Summer 2021
// Examiner:                Prof. Dr. Herbert Fischer
// Score:                   90 Points
// Additional Materials:    None
// Duration:                90 Minutes

// ----- YOUR INFORMATION -----
// Street+House number: Weiherweg 6/1.OG Zimmer Nr. 3.112
// Surname, First name: Varga Lukas
// Postcode + City: 93051 Regensburg
// Matriculation number: 3277900
// E-Mail: lukas.varga@st.oth-regensburg.de
// ----------------------------

// 4.   Operator overloading            (25 points)
//
// 4.1  Extend the program by an external function, which examines 2 objects for equality.
//      If both objects are the same, i.e. the two numbers are equal, the user should get the output "objects are equal".
//      If the objects are not equal, then the user should get the output "objects are not equal".
//
// 4.2  Extend the program by overloading the opperators istream >> and ostream <<.
//      With istream, the query should be made for number1 and number2.
//      With ostream, both numbers should be printed on the screen.
//
// 4.3  Create two objects of the class Numbers dynamically.
//      The data should be entered by the user (via istream from 4.2).
//      Output the numbers you entered (via ostream from 4.2).
//      Compare the two objects using the external function from 4.1.

#include <iostream>
using namespace std;

class Numbers {
private:
    int number1, number2;
public:
    Numbers(int n1, int n2): number1(n1), number2(n2) {};

    friend bool operator==(Numbers &a, Numbers &b);
    friend istream& operator>>(istream& is, Numbers& p);
    friend ostream& operator<<(ostream& os, Numbers& p);
};

bool operator==(Numbers &a, Numbers &b)
{
    if((a.number1 == b.number1) && (a.number2 == b.number2))
    {
        cout << "objects are equal" << endl;
        return true;
    }
    else
    {
        cout << "objects are not equal" << endl;
        return false;
    }
}

istream& operator>>(istream& is, Numbers& p)
{
    cout << "INPUT" << endl;
    cout << "number1: ";
    is >> p.number1;

    cout << "number2: ";
    is >> p.number2;

    cout << endl;
}

ostream& operator<<(ostream& os, Numbers& p)
{
    cout << "OUTPUT" << endl;
    os  << "number1: " <<p.number1 << endl
        << "number2: " << p.number1 << endl << endl;
}

int main()
{
    Numbers* n1 = new Numbers(2,6);
    Numbers* n2 = new Numbers(2,6);

    cin >> *n1;
    cin >> *n2;

    cout << *n1;
    cout << *n2;

    bool eq = (*n1 == *n2);
//    cout << "Boolean: " << eq << endl;

    return 0;
}
