#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Euro
{
private:
    int eur;
    int cent;
public:
    Euro(): Euro(0) {}
    Euro(int e): Euro(e,0) {}
    Euro(int e, int c): eur(e), cent(c) {}
    /*
    Euro(double doubleVal)
    {
        if(doubleVal<0)
        {
            eur = (int) doubleVal;
            cent = (int) round((doubleVal - eur)*100);
        }
        else
        {
            eur = (int) doubleVal;
            cent = (int) round((doubleVal - eur)*100);
        }
    }
    */

    void output()
    {
        cout << "Cash: " << eur << "E " << cent << "c" << endl;
    }

    friend Euro operator+(Euro &a, Euro &b);
    friend Euro operator-(Euro &a, Euro &b);
    Euro operator*(double rate);
};

Euro operator+(Euro &a, Euro &b)
{
    Euro cash;
    cash.eur = a.eur + b.eur;
    cash.cent = a.cent + b.cent;

    if(cash.cent < 0)
    {
        cash.eur--;
        cash.cent = 100 + cash.cent;
    }
    if(cash.cent > 99)
    {
        cash.eur++;
        cash.cent = cash.cent - 100;
    }

    return cash;
}

Euro operator-(Euro &a, Euro &b)
{
    Euro cash;
    cash.eur = a.eur - b.eur;
    cash.cent = a.cent - b.cent;

    if(cash.cent < 0)
    {
        cash.eur--;
        cash.cent = 100 + cash.cent;
    }
    if(cash.cent > 99)
    {
        cash.eur++;
        cash.cent = cash.cent - 100;
    }

    return cash;
}

Euro Euro::operator*(double rate)
{
    Euro cash;
    cash.eur = this->eur * rate;
    cash.cent = this->cent * rate;

    if(cash.cent < 0)
    {
        cash.eur--;
        cash.cent = 100 + cash.cent;
    }
    if(cash.cent > 99)
    {
        cash.eur++;
        cash.cent = cash.cent - 100;
    }

    return cash;
}

int main()
{
	Euro myMoney(100,80), yourMoney(45,30), fine(25,80), ourMoney;
	double interestrate = 3.5;

	ourMoney = myMoney + yourMoney;
	ourMoney.output();
	ourMoney = ourMoney - fine;
	ourMoney.output();
	ourMoney = ourMoney.operator*(interestrate);
	ourMoney.output();


    system("pause");
    return 0;
}
