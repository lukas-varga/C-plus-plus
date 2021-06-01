#include <iostream>
#include <cstdlib>

using namespace std;

//Abstract class
class Polygon
{
protected:
    float length;
    float width;
public:
    virtual float area() = 0;

    float getLength(){return length;}
    void setLength(float len){length = len;}
    float getWidth(){return width;}
    void setWidth(float wid){width = wid;}
};

class Rectangle : public Polygon
{
public:
    Rectangle(){}
    Rectangle(float len, float wid)
    {
        length = len;
        width = wid;
    }
    float area()
    {
        return length*width;
    }
};

class Triangle : public Polygon
{
public:
    Triangle(){}
    Triangle(float len, float wid)
    {
        length = len;
        width = wid;
    }
    float area()
    {
        return (length*width)/2;
    }
};

int main()
{
    cout << "--- Polygon ---" << endl;

    Rectangle r;
    r.setLength(10);
    r.setWidth(20);

    Triangle t;
    t.setLength(10);
    t.setWidth(20);

    Polygon *poly1 = &r;
    Polygon *poly2 = &t;

    cout << "First area: " << poly1->area() << endl;
    cout << "Second area: " << poly2->area() << endl;

    system("pause");
    return 0;
}
