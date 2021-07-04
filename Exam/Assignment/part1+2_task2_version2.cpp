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

// 2. References                          (10 points)
//
// In the program below, there are two arrays defined, in which the expenditure over 12 months of two years are stored.
// Swap the values of the arrays by doing the following:
//
// 2.1 Create a for-loop to output the stored data expenditures1 and expenditures2.
//
// 2.2 Call the function "swapNums" inside of this loop and pass the values of the array expenditure1 and expenditure2.
//
// 2.3 Output the stored data of expenditures1 and expenditures2 after calling the function. 
//     Why are the values not being swapped?
//     Answer: 
//
// 2.4 Correct the function swapNums so that it's referencing and swapping the actual values of the arrays.

#include <iostream>
using namespace std;

void swapNums(int x, int y) {
  int z = x;
  x = y;
  y = z;
}

int main()
{
    int expenditure1[12] = {10,15,20,36,15,45,20,35,24,64,52,12};
    int expenditure2[12] = {100,150,200,360,150,450,200,350,240,640,520,120};



    return 0;
}
