#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
 int x=10, y=10, *xptr, **ptrptr; // Declaration of variables x and y, of pointer xptr, and of the pointer to a pointer ptrptr

 cout << "x = " << x << endl; // Output of x as value

 xptr = &x; // Pointer xptr is assigned the address of x as value
 *xptr = 20; // The variable which xptr points to is assigned value 20
 cout << "x = " << x << " and *xptr = " << *xptr <<endl;

 ptrptr = &xptr; // Pointer ptrptr is assigned the address of pointer xptr
 **ptrptr = 30; // Variable x is assigned value 30 via pointer **ptrptr
 cout << "x = " << x << " *xptr = "<< *xptr << " and **ptrptr = " << **ptrptr << endl;

 *ptrptr = &y; // The pointer now points to y
 **ptrptr = 40; // Variable y is assigned value 40, since ptrptr points to ptr and ptr is now set to y
 cout << "x = " << x << ", y= " << y << ", *xptr = " << *xptr << " and **ptrptr = " << **ptrptr << endl;
 system("pause");
}
