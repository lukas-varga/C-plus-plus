// Deggendorf Institute of Technology - vhb Exam
// Examination subject:     Programming in C++ / Part 1+2 (6 ECTS)
// Semester:                Summer 2021
// Examiner:                Prof. Dr. Herbert Fischer
// Score:                   90 Points
// Additional Materials:    None
// Duration:                90 Minutes

// ----- YOUR INFORMATION -----
// Street+House number:
// Surname, First name:
// Postcode + City:
// Matriculation number:
// E-Mail:
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

};

int main()
{



    return 0;
}
