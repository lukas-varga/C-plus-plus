#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//---DATE---

// The class for  storing and handling dates
class Date{
private:
    short day;
    short month;
    unsigned int year;
public:
    // Default constructor which only generates empty date
    Date(): Date(1,1,1900) {}
    Date(short d,short m,unsigned int y):day(d),month(m),year(y) {}

    friend istream& operator>>(istream& is, Date& date);
    friend ostream& operator<<(ostream& os, Date& date);
    bool isItRealDate();
};


// Initial method for retreiving birth day from user
istream& operator>>(istream& is, Date& d)
{
    // It will ask user as long as valid date is entered
    bool actualDate = false;
    do
    {
        system("cls");
        cout << "---DATE---"<<endl;
        cout << "Day: ";
        is >> d.day;
        cout << "Month: ";
        is >> d.month;
        cout << "Year: ";
        is >> d.year;

        // When date is not real it will give user some hints and repeat entering
        actualDate = d.isItRealDate();
        if(!actualDate)
        {
            cout<<endl<<"Please provide the real date!"<<endl;
            system("pause");
        }
    }while(!actualDate);
}

// Method that print formated date to screen
ostream& operator<<(ostream& os, Date& d)
{
    os << d.day << "." << d.month << "." << d.year;
    return os;
}

// Method returns true if the date is real, otherwise it returns false
bool Date::isItRealDate()
{
    // Not negative year
    if(year < 0)
        return false;

    // Checking if entered day and month is within rough boundaries
    else if(month < 1 || month > 12)
        return false;
    else if(day < 1 || day > 31)
        return false;

    // Will take care of the leap year
    else if(day == 29 && month == 2)
    {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    return true;
                else
                    return false;
            }
            else{
                return true;
            }
        }
        else
            return false;
    }

    // Checking if the 31 day is i correct month
    else if(day==31)
    {
        switch (month)
        {
            case 2:
            case 4:
            case 6:
            case 9:
            case 11:
                return false;
        }
    }

    //returning true if it passed all the test before
    return true;
}

int main()
{
    cout << "Date!" << endl;

    Date date;
    cin >> date;
    cout << date;

    return 0;
}
