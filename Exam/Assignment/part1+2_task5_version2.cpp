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

// 5.   Linked lists                (20 points)
//
// 5.1  Add the data members in the class Employee, which are required for a linked list (suitable for the class ListOfEmployees).
//
// 5.2  Add the following to the class Employee:
//      a) Default constructor
//      b) Parameterized constructor with member initialization list
//      c) Member function "data_output" for outputting all employee data
//
// 5.3  In the main function, 3 employee objects have to be added to the list.
//      Output the employee data from the list using a for loop.
//      Extend the program by the member functions, which are required for this.

#include <iostream>
using namespace std;

class Employee 
{


};

class ListOfEmployees{
private:
    Employee *Head;
public:
    ListOfEmployees():Head(0){};
    void insert (Employee *t) {
        string empname;
        short year;
        cout << "Employee name: ";
        cin >> empname;
        cout << endl << "Year of birth: ";
        cin >> year;
        t->name = empname;
        t->birthYear = year;
        t->successor = Head;
        Head = t;
    }

};

int main()
{



    return 0;
}
