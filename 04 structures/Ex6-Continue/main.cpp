#include <iostream>
#include <cstdlib>

using namespace std;

void loop();

int main()
{
    cout << "Continue!" << endl;

    loop();

    system("pause");
    return 0;
}

void loop()
{
    for(int i = 1; i <= 100; i++)
    {
        if(!(i%2 == 0))
            continue;
        cout << i << ", ";
    }
    cout << endl;
}
