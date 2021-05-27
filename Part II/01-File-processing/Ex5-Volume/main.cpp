#include <iostream>

using namespace std;

int main()
{
    cout << "Volume of cuboid!" << endl << "Enter sizes of the sides:" << endl;
    try
    {
        float a,b,c;
        cout << "a: ";
        cin >> a;

        cout << "b: ";
        cin >> b;

        cout << "c: ";
        cin >> c;

        if(a<=0 || b<=0 || c<=0)
            throw -1;

        float res = a * b *c;
        cout << "The volume of cuboid with sides of size " << a << ", " << b << ", " << c << " is equal to " << res << endl;

    }
    catch(int e)
    {
        cout << "The size of one of the given side is either zero or negative." <<endl;
        cout << "This is not allowed! Error code: " << e <<endl;
    }

    system("pause");
    return 0;
}
