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

// 3. Abstract classes and polymorphism   	(20 points)
//
// 3.1  In the program, add the data members in the class "Property" that match the constructor(s).
//      The data members should only be able to be changed by derived classes. The program should then be able to run without errors.
//
// 3.2  Change the class in the program so that it becomes an abstract base class using the member function print().
//
// 3.3  What is special about abstract base classes? Explain at least three features.
//      Answer: 
//	-
//	-
//	-
//
// 3.4  Complete the program with a derived class "House" of the abstract class "Property".
//      This derived class should contain the data member floors, which is of the data type int, and the data member furnished, which is of the data type bool.
//      Create a default constructor and a constructor with member initialization list.
//      Which member function(s) still have to be implemented so that the program can run? Implement this member function(s).

#include <iostream>
using namespace std;

class Property
{
public:
    Property(){count++;};
    Property(float a, string l, string s): area(a), location(l), street(s) {count++;};
    void print(); //Output of the data
};

int Property::count = 0;

int main()
{



    return 0;
}
