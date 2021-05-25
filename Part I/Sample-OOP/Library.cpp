#include <iostream>
#include <cstdlib>

using namespace std;

class Person {
private:
    string firstName;
    string surname;
    string street;
    unsigned int houseNumber;
    string city;
    unsigned int postalCode;
public:
    Person() {};
    void enterData();
    void showData();
};

void Person::enterData()
{
    cout << "--Enter Data --" << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Surname: ";
    cin >> surname;
    cout << "Street: ";
    cin >> street;
    cout << "House number: ";
    cin >> houseNumber;
    cout << "Postal code: ";
    cin >> postalCode;
    cout << "City: ";
    cin >> city;
    cout << endl << "Person has been entered." << endl;
}

void Person::showData()
{
    cout << firstName << " " << surname << endl;
    cout << street << " " << houseNumber << endl;
    cout << postalCode << " " << city << endl;
}

class Book{
private:
    string title;
    string author;
public:
    Book() {};
    Book(string t,string a) : title(t), author(a) {};
    void showData();
};

void Book::showData()
{
    cout << title << " (von " << author << ")";
}

class Date{
private:
    short day;
    short month;
    unsigned int year;
public:
    void enterDate();
    void showData();
    void incrementByOneMonth();
};

void Date::enterDate()
{
    cout << "Day: ";
    cin >> day;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
}

void Date::showData()
{
    cout << day << "." << month << "." << year << endl;
}

void Date:: incrementByOneMonth()
{
    if(month == 12)
    {
        year = year+1;
        month=(month%12)+1;
    }
    else if(day == 28 && month == 2)
    {
        day = 31;
        month+=1;
    }
    else if(day <= 28)
    {
        month+=1;
    }
    else if(day > 28 && day <= 31 && month == 1)
    {
        day = 28;
        month+=1;
    }
    else if(day==31 && month != 7)
    {
        switch (month)
        {
            case 3:
            case 5:
            case 8:
            case 10:
                {
                    day=30;
                    month+=1;
                    break;
                }
        }
    }
    else if(day==30)
    {
        switch (month)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                {
                    day=31;
                    month+=1;
                    break;
                }
        }
    }
    else
        month+=1;
}

class Loan {
private:
    Person borrower;
    Book borrowedBook;
    Date returnDate;
    bool has_book;
public:
    Loan() { has_book = false; };
    void enterData(Person,Book,Date);
    void showData();
    void extend();
    void giveBack();
    bool get_has_book();
};

void Loan::enterData(Person p, Book b, Date d)
{
    borrower = p;
    borrowedBook = b;
    returnDate = d;
    has_book = true;
}

void Loan::showData()
{
    borrower.showData();
    cout << endl << "Borrowed book: ";
    borrowedBook.showData();
    cout << endl << "Return until: ";
    returnDate.showData();
}

void Loan::extend()
{
    returnDate.incrementByOneMonth();
    cout << "The loan was extended by 1 month." << endl;
}

void Loan:: giveBack()
{
    cout << "Book ";
    borrowedBook.showData();
    cout << " was returned." << endl;
    has_book = false;
}

bool Loan::get_has_book()
{
    return has_book;
}

int main()
{
    Person p;
    int select;
    Book b[3] = {{"Title 1", "Author a"},{"Title 2", "Author b"},{"Title 3", "Author c"}};
    Loan a;
    Date d;

    p.enterData();
    system("pause");

    do
    {
        system("cls");
        cout << "--MENU--" << endl;
        cout << "[1] Enter personal data" << endl;
        cout << "[2] Borrow book" << endl;
        cout << "[3] Extend loan" << endl;
        cout << "[4] Show data" << endl;
        cout << "[5] Return book" << endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Please select: ";
        cin >> select;
        switch(select)
        {
        case 1:
            {
                system("cls");
                p.enterData();
                system("pause");
                system("cls");
                break;
            }
        case 2:
            {
                system("cls");
                if(a.get_has_book() == true)
                {
                    cout << "Loan is not possible. Person has already borrowed a book" << endl;
                }
                else
                {
                    cout << "Which book should be borrowed?" << endl;
                    for(int i=0;i<3;i++)
                    {
                        cout << "[" << i+1 << "] ";
                        b[i].showData();
                        cout << endl;
                    }
                    cout << endl << "Please select: ";
                    cin >> select;

                    system("cls");
                    cout << "Until when is the book to be returned?" << endl;
                    d.enterDate();

                    a.enterData(p,b[select-1],d);
                }

                system("pause");
                system("cls");
                break;
            }
        case 3:
            {
                system("cls");
                if(a.get_has_book() == true)
                    a.extend();
                else
                    cout << "Person has not borrowed a book yet." << endl;
                system("pause");
                system("cls");
                break;
            }
        case 4:
            {
                system("cls");
                if(a.get_has_book() == true)
                    a.showData();
                else
                    cout << "Person has not borrowed a book yet." << endl;
                system("pause");
                system("cls");
                break;
            }
        case 5:
            {
                system("cls");
                if(a.get_has_book() == true)
                    a.giveBack();
                else
                    cout << "Person has not borrowed a book yet." << endl;
                system("pause");
                system("cls");
                break;
            }
        case 0:
            {
                cout << endl << "Goodbye" << endl;
                return 0;
            }
        default:
            {
                cout << endl << "Incorrect input!" << endl;
                system("pause");
            }
        }
    }while(select!=0);

    return 0;
}
