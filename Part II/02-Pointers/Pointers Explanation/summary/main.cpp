#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
 int x = 3;
 int *pointer = &x;
 cout << "Address which pointer points to: " << pointer << endl;
 cout << "Address of x: " << &x << endl;
 cout << "Address of pointer: " << &pointer << endl << endl;
 cout << "Value of x: " << x << endl;
 cout << "Value of pointer: " << *pointer << endl << endl;
 cout << "Enter value for x: ";
 cin >> x;
 cout << endl;
 cout << "Value of x: " << x << endl;
 cout << "Value of pointer: " << *pointer << endl << endl;
 cout << "Enter value for pointer: ";
 cin >> *pointer;
 cout << endl;
 cout << "Value of x: " << x << endl;
 cout << "Value of pointer: " << *pointer << endl << endl;
 system("pause");
 int array[5] = {1,2,3,4,5};
 cout << "Address of the first array element: " << array << endl;
 cout << "Address of the first array element: " << &array << endl;
 cout << "Address of the first array element: " << &array[0] << endl;
 cout << endl;
 cout << "Value of the first array element: " << array[0] << endl;
 cout << "Value of the first array element: " << *array << endl << endl;
 cout << endl;
 cout << "Value of the third pointer array: " << array[2] << endl;
 //cout << "Value of the third pointer array: " << *arraypointer[2]; // Does not work!
 cout << "Value of the third pointer array: " << *(array+2) << endl;
 cout << "Display address of the array: "<<endl;
 for(int i = 0; i < 5; ++i)
 {
 cout << "&array[" << i << "] = " << &array[i] << endl;
 }
 cout << endl;
 cout << "Display value of the array: "<<endl;
 for(int i = 0; i < 5; ++i)
 {
 cout << "array[" << i << "] = " << array[i] << endl;
 }
 system("pause");
 // SUMMARY:
 // &array[0] is equal to array
 // *array is equal to array[0]
 // &array[1] is equal to array+1
 // *(arraypointer+1) is equal to array[1]
}
