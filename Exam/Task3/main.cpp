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

// 3. Abstract classes and polymorphism   	(20 points)
//
// 3.1  In the program, add the data members in the class "Property" that match the constructor(s).
//      The data members should only be able to be changed by derived classes. The program should then be able to run without errors.
//
// 3.2  Change the class in the program so that it becomes an abstract base class using the member function print().
//
// 3.3  What is special about abstract base classes? Explain at least three features.
//      Answer:
//	- We cannot create an object/instance of an abstract class.
//	- If we do not override the pure virtual function in derived class, derived class also becomes an abstract class.
//	- We still can point at abstract class using pointers. That means we can substitute derived class by its base class
//        by creating base class pointer and point on derived class object. This process is also know as polymorphism.
//
// 3.4  Complete the program with a derived class "House" of the abstract class "Property".
//      This derived class should contain the data member floors, which is of the data type int, and the data member furnished, which is of the data type bool.
//      Create a default constructor and a constructor with member initialization list.
//      Which member function(s) still have to be implemented so that the program can run? Implement this member function(s).
//      Answer: We need to still implement pure virtual function print().

#include <iostream>
using namespace std;

class Property
{
protected:
    float area;
    string location, street;
    static int count;
public:
    Property(){count++;};
    Property(float a, string l, string s): area(a), location(l), street(s) {count++;};
    virtual void print() = 0; //Output of the data
};

class House : public Property
{
private:
    int floors;
    bool furnished;
public:
    House(){};
    House(float a, string l, string s, int fl, bool fr): Property(a,l,s), floors(fl), furnished(fr){};
    void print()
    {
        cout << "Area: " << area << ", Location: " << location << ", Street: " << street << ", Floors:" << floors << ", Furnished: " << furnished << endl;
    }
};

int Property::count = 0;

int main()
{
    House* h1 = new House(5,"NY", "Evenue", 2, true);
    h1->print();
    return 0;
}
