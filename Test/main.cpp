#include <iostream>
using namespace std;
int main() {
   int number;{
   cout << "Please enter a number :";
   cin >> number;
     if(number < 100)
     { cout << "The number is smaller than hundred." << endl;}
     if(number == 100)
     {cout << "The number is equal to hundred." << endl;}
     if(number > 100)
     {cout << "The number is greater than hundred." << endl;}
     return 0;
   }
}
