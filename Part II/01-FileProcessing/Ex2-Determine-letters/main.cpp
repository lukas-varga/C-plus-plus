#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileR;
    fileR.open("test.txt", ios::in);

    char input;
    cout << "Enter the letter for determine occurrence: ";
    cin >> input;

    int occ = 0;
    string s;

    while(!fileR.eof())
    {
        getline(fileR,s);
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == input)
            {
                occ++;
            }
        }
        cout<<endl;
    }

    cout << "Occurrence in text: " << occ << endl;
    return 0;
}
