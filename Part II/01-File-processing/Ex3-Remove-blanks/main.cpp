#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileR;
    ofstream fileW;

    fileR.open("test.txt",ios::in);
    fileW.open("new.txt",ios::out);
    string s;

    while(!fileR.eof())
    {
        getline(fileR,s);
        string newS ="";
        char last = 'a';

        for(int i=0; i<s.length(); i++)
        {
            //first occ of blank
            if(s[i] == ' ' && last == ' ')
            {
                continue;
            }

            newS += s[i];
            last = s[i];
        }

        cout << newS << endl;
        fileW << newS <<endl;
    }

    fileR.close();
    fileW.close();

    system("pause");
    return 0;
}
