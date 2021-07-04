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

// 1. Basics                          (15 points)
//
// 1.1 Declare a class Candle with the following data members:
// Height (in cm) and color. Choose appropriate data types. Only derived classes can change these data members.
// Define for the class:
// a) Default constructor
// b) Parameterized constructor with member initialization list
// c) Member function "data_output" for outputting all data of the class. The member function "data_output" should be defined outside of the class.
//
// 1.2 Definition of member functions:
// You know from experience that a candle loses an average of 3 cm in "height" every hour.
// Define a member function "updateHeight" with a parameter "burning_hours" and a suitable data type for it.
// The task of the member function is to update the "height" of the candle based on the hours.
// If the candle has burned down after the update, the user should get a corresponding message,
// otherwise the user gets as the output the current height of the candle.
//
// 1.3 Dynamic instantiation:
// Define two dynamic objects of the class Candle. Since the values of the data members do not have to be queried (=not typed in by the user),
// they can be passed as static members.
// Call the member function "data_output" for the second instance and the member function "updateHeight" for the first instance.

#include <iostream>
using namespace std;

class Candle
{
protected:
    int height;
    string color;
public:
    Candle(){}
    Candle(int h, string c):height(h),color(c){}
    void data_output();
    void updateHeight(int burning_hours);
};

void Candle::data_output()
{
    cout << "Height: " << height << ", Color: " << color << endl;
}

void Candle::updateHeight(int burning_hours)
{
    int lostH = burning_hours * 3;
    int newH = height - lostH;
    if(newH <= 0)
    {
        cout << "Candle is gone!" << endl;
        height = 0;
    }
    else
    {
        cout << "New height of the candle is " << newH << " cm" << endl;
        height = newH;
    }
}

int main()
{
    Candle* c1 = new Candle(5,"green");
    Candle* c2 = new Candle(8,"red");

    c2->data_output();
    c1->updateHeight(1);

    return 0;
}
