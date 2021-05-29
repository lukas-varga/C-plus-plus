#include <iostream>

using namespace std;

class Rectangle
{
private:
    float length;
    float width;
public:
    Rectangle()
    {
        cout << "Default constructor!"<< endl;
    }
    ~Rectangle()
    {
        cout << "Destructor!" << endl;
    }
    Rectangle(float length, float width)
    {
        this->length = length;
        this->width = width;
    }
    float area()
    {
        return length*width;
    }
};

int main()
{
    cout << "Rectangle Area" << endl;

    Rectangle *rec = NULL;

    float len, wid;
    while(true)
    {
        cout << "Length: ";
        cin >> len;
        if(len==0)
            break;

        cout << "Width: ";
        cin >> wid;
        if(wid == 0)
            break;

        rec = new Rectangle(len,wid);
        cout << "Area: "<< rec->area() << endl;
        delete rec;
        cout << endl;
    }

    delete rec;
    return 0;
}
