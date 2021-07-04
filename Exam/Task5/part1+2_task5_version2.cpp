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
friend class ListOfEmployees;
private:
    string name;
    short birthYear;
    Employee* successor;
public:
    Employee(){};
    Employee(string n, short b): name(n), birthYear(b) {};
    void data_output()
    {
        cout << "Name: "<<name<< ", Birth year: "<<birthYear << endl;
    }
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
    void displayElements()
    {
        Employee *pointer;
        for (pointer = Head; pointer != NULL; pointer = pointer->successor)
        {
            pointer->data_output();
        }
    }
};

int main()
{
    Employee* e1 = new Employee();
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    ListOfEmployees list;
    list.insert(e1);
    list.insert(e2);
    list.insert(e3);

    list.displayElements();
    return 0;
}
