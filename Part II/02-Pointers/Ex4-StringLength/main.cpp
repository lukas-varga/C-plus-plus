#include <iostream>

using namespace std;

int stringlength(char arr[])
{
    int res = 0;
    char *pointer = &arr[0];
    while (*pointer != '\0')
    {
        ++pointer;
        ++res;
    }

    return res;
}

int main()
{
    char arr[50];
    cout << "Enter string: " << endl;
    cin >> arr;

    int res = stringlength(arr);
    cout << "Length of given string: " << res;

    return 0;
}
