#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream file;
    file.open("test.txt", ios::in);
    int i=0;
    string s;

    while(!file.eof())
    {
        getline(file,s);
        cout << i+1 << ": " << s <<endl;
        i++;
    }
    file.close();

    system("pause");
    return 0;
}
