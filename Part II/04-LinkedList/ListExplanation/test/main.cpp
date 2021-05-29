#include <iostream>
#include <list>
using namespace std;
void showlist(string, list<int>&); // Declaration of the showlist function
int main()
{
 list<int> L; // List
 int x;
 cout << "Insert a positive number (Exit with 0):" << endl;
 do
 {
 cin >> x;
 if(x==0)
 break;
 L.push_back(x); // Insert at the end of the list
 }while (true);
 showlist("Initiallist:", L); // Output initial list
 L.push_front(123); // Insert 123 at the beginning of the list
 showlist("After inserting 123 at the beginning:", L);
 list<int>::iterator i = L.begin(); // Iterator, assignment to the beginning of the list
 L.insert(++i, 456); // Increase iterator by 1, so it is the second node
// Insert in second position
 showlist("After inserting 456 at the second node:", L);
 i = L.end(); // Iterator, assignment to the end of the list
 L.insert(--i, 999); // Decrease iterator by 1 so that it is the penultimate node
 showlist("After inserting 999 at the penultimate node:", L);
 i = L.begin(); // Iterator, assignment to the beginning of the list
 x = *i; // x has the value of the first node
 L.pop_front(); // Delete first node from list
 cout << "Deleted at the beginning: " << x << endl;
 showlist("After deleting the first node:", L);
 i = L.end(); // Iterator, assignment to the end of the list
 x = *--i; // x has the value of the last node (only i would be outside the list)
 L.pop_back(); // Delete the last node
 cout << "Deleted at the end: " << x << endl;
 showlist("After deleting the last node:", L);
 i = L.begin(); // Iterator, assignment to the beginning of the list
 x = *++i; // x has the value of the second node
 cout << "Delete: " << x << endl;
 L.erase(i); // Delete at the place of the iterator
 showlist("After deleting the second node:",L);
 L.clear(); // Empty list
 showlist("After deleting the entire list:",L);
 return 0;
}
void showlist(string str, list<int> &L) // Definition of the showlist function: Returns the contents of the list
{
 list<int>::iterator i;
 cout << str << endl << " ";
 for (i=L.begin(); i != L.end(); ++i)
 cout << *i << " ";
 cout << endl;
}
