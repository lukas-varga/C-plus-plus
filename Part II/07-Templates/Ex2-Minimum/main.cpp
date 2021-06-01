#include <iostream>

using namespace std;

template <class T>
inline T minimum(T &a, T &b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "Minimum!" << endl;

    int a = 5, b = 3;
    cout << minimum<int>(a,b) << endl;

    char c = 5, d = 3;
    cout << minimum<char>(c,d) << endl;

    return 0;
}
