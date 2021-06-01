#include <iostream>

using namespace std;

class Customer
{
protected:
    float payment;
public:
    virtual void pay(float p)
    {
        payment = p;
    }
    void print()
    {
        cout << "Payment: " << payment << endl;
    }
};

class NewCustomer : public Customer
{
public:
    void pay(float p)
    {
        payment = p * (1.00 - 0.20);
    }
};

class RegularCustomer : public Customer
{
public:
    void pay(float p)
    {
        payment = p * (1.00 - 0.10);
    }
};

void makePay(Customer* cust, float amount)
{
    cust->pay(amount);
}

int main()
{
    cout << "---Customer---" << endl;

    Customer *c = new Customer();
    NewCustomer *n = new NewCustomer();
    RegularCustomer *r = new RegularCustomer();

    makePay(c,200);
    makePay(n,200);
    makePay(r,200);

    c->print();
    n->print();
    r->print();

    return 0;
}
