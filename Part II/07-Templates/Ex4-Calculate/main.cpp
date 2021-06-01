#include <iostream>

using namespace std;

template <class T>
class Calc
{
private:
    T one;
    T two;
public:
    Calc(T o, T t): one(o), two(t) {};
    T add();
    T multiply();
};

template <class T>
T Calc<T>::add()
{
    return one + two;
}

template <class T>
T Calc<T>::multiply()
{
    return one * two;
}

template <>
string Calc<string>::add()
{
    return one + " " + two;
}

int main()
{
    cout << "Calculate!" << endl;

    Calc<int> i(1,2);
    Calc<string> s("Audi", "BMW");

    cout << "Add int: " << i.add() << endl;
    cout << "Multiply int: " << i.multiply() << endl;
    cout << "Add string: " << s.add() << endl;

    return 0;
}
