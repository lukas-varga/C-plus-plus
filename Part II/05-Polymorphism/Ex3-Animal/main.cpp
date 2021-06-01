#include <iostream>
#include <cstdlib>

using namespace std;

//Abstract class
class Animal
{
protected:
    string name;
    Animal(string n): name(n){}
public:
    virtual void makeSound() = 0;
};

class Cow : public Animal
{
public:
    Cow(string n): Animal(n){}
    void makeSound()
    {
        cout << name <<": \"Moo\"" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string n): Animal(n){}
    void makeSound()
    {
        cout << name <<": \"Woof\"" << endl;
    }
};

int main()
{
    cout << "--- Animal ---" << endl;

    Animal *an;
    Cow *c = new Cow("Pablo");
    Dog *d = new Dog("Chuan");

    c->makeSound();
    d->makeSound();

    an = c;
    an->makeSound();
    an = d;
    an->makeSound();

    system("pause");
    return 0;
}
