#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Division calculator (a/b)!" << endl;
    ofstream writer;
    ifstream reader;

    writer.open("result.txt",ios::app);
    if(!writer.good())
    {
        writer.close();
        cout << "File \'result.txt\' is write-protected!"<< endl;
        return 0;
    }

    float a,b,res;
    string answer;
    do
    {
        cout << "Enter dividend (a): ";
        cin >> a;

        cout << "Enter divisor (b): ";
        cin >> b;

        try
        {
            if(b == 0)
                throw (string) "Division by zero is not allowed!";

            res = a/b;
            writer << a << "/" << b << "=" << res << endl;
        }
        catch(string e)
        {
            cout << "Error occurred: " << e << endl;
        }

        cout << "Do you want to continue (Yes/No): ";
        cin >> answer;

    }while(answer != "No");
    writer.close();

    cout << endl << "result.txt" << endl;
    reader.open("result.txt", ios::in);
    if(!reader.good())
    {
        reader.close();
        cout << "File \'result.txt\' cannot be read!"<< endl;
        return 0;
    }

    string line;
    while(!reader.eof())
    {
        getline(reader,line);
        cout << line << endl;
    }
    reader.close();

    return 0;
}
