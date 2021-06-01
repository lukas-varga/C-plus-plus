#include <cstdlib>
#include <iostream>
using namespace std;
class Numbers {
 private:
 float number1, number2;
 public:
 Numbers(): number1(0), number2(0) {}
 Numbers(float n1, float n2): number1(n1), number2(n2) {}

 //member functions
 const Numbers operator += (const Numbers& a);
 const void operator -= (const Numbers& a);

 friend ostream& operator<< (ostream& os, const Numbers& b);
 friend Numbers operator+ (const Numbers& left, const Numbers& right);
 friend void operator- (Numbers& left, const Numbers& right);
};
const Numbers Numbers::operator += (const Numbers& a) {
 number1 += a.number1;
 number2 += a.number2;
 return *this;
}
const void Numbers::operator -= (const Numbers& a) {
 number1 -= a.number1;
 number2 -= a.number2;
}
// Output
ostream& operator<< (ostream& os, const Numbers& a) {
 os << "Number1; " << a.number1 << " Number2: " << a.number2 << endl;
 return os;
}
// external function
Numbers operator+ (const Numbers& left, const Numbers& right) {
 Numbers z;
 z.number1 = left.number1 + right.number1;
 z.number2 = left.number2 + right.number2;
 return z;
}
// Note “left” must not be declared as const!
void operator- (Numbers& left, const Numbers& right) {
 left.number1 -= right.number1;
 left.number2 -= right.number2;
}
int main()
{
 Numbers x(5,6), y(9,18), z;
 x += y;
 x -= y;
 z = x + y;
 cout << z;
 x - y;
 cout << x;
 system("pause");
 return 0;
}
