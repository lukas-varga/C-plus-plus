#include <iostream>
#include <cstdlib>

using namespace std;

class Animal
{
protected:
    float number;
public:
    Animal(){};
    Animal(float n):number(n)
    {
        cout << "Animal created, ";
    };
};

class SlaughterCattle : public Animal
{
private:
    float weight;
public:
    SlaughterCattle(float n, float w):Animal(n),weight(w)
    {
        cout << "it is a slaughter cattle"<<endl;
    };
    void displaydata()
	{
		cout <<"There are "<<number << " slaughter cattles with " <<weight <<" kg each available"<<endl;
	}
};

class DairyCattle : public Animal
{
private:
    float milkyield;
public:
    DairyCattle(float n, float m):Animal(n),milkyield(m)
    {
        cout << "it is a dairy cattle"<<endl;
    };
    void displaydata()
	{
		cout <<"There are "<<number << " dairy cattles with " <<milkyield <<" milk yield available"<<endl;
	}
};

int main()
{
	SlaughterCattle pig = SlaughterCattle(40,60);
	DairyCattle cow = DairyCattle(20,25.5);

	pig.displaydata();
	cow.displaydata();

	system("PAUSE");
	return 0;
};
