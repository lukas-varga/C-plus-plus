#include <iostream>

using namespace std;

// CLASSES //

class Person
{
private:
    string surname;
    string firstName;
    string street;
    unsigned int houseNum;
    unsigned int postalCode;
    string city;
public:
    Person(){};
    void enterData()
    {
        cout<<"Enter surname:"<<endl;
        cin>>surname;
        cout<<"Enter first name:"<<endl;
        cin>>firstName;
        cout<<"Enter street:"<<endl;
        cin>>street;
        cout<<"Enter house's animalCounter:"<<endl;
        cin>>houseNum;
        cout<<"Enter postal code:"<<endl;
        cin>>postalCode;
        cout<<"Enter city:"<<endl;
        cin>>city;
    };
    void showData()
    {
        cout<<"Your surname: ";
        cout<<surname<<endl;
        cout<<"Your first name: ";
        cout<<firstName<<endl;
        cout<<"Your street: ";
        cout<<street<<endl;
        cout<<"Your house's animalCounter: ";
        cout<<houseNum<<endl;
        cout<<"Your postal code: ";
        cout<<postalCode<<endl;
        cout<<"Your city: ";
        cout<<city<<endl;
    };
};

class Book
{
private:
    string title;
    string author;
public:
    Book(){};
    Book(string t,string a):title(t),author(a){};
    void showData()
    {
        cout<<"Title: "<<title<<", Author: "<<author<<endl;
    };
};

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(){};
    void enterData()
    {
        cout<<"Day: "<<endl;
        cin>>day;
        cout<<"Month: "<<endl;
        cin>>month;
        cout<<"Day: "<<endl;
        cin>>year;
    };
    void showData()
    {
        cout<<day<<"."<<month<<"."<<year<<endl;
    };
    void extendByOneMonth()
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
    };
};

class Loan
{
private:
    Person borrower;
    Book borrowerBook;
    Date returnDate;
    bool hasBook = false;
public:
    Loan(){};
    Loan(Person p, Book b, Date d):borrower(p),borrowerBook(b),returnDate(d)
    {
        hasBook = true;
    };
    void showData()
    {
        cout<<"Book details: ";
        borrowerBook.showData();
        cout<<"Return date: ";
        returnDate.showData();
    }

    Book getBorrowerBook()
    {
        return borrowerBook;
    };

    bool getHasBook()
    {
        return hasBook;
    };

    void bookReturned()
    {
        hasBook = false;
    };

    void extendLoan()
    {
        returnDate.extendByOneMonth();
    };
};

int main()
{
    cout << "Hello user and welcome at the library!" << endl;
    Person p;
    Loan l;
    Date d;
    p.enterData();

    Book books[3];
    books[0] = Book("Witcher", "Andrej Sapkowski");
    books[1] = Book("Metro", "Dmitrij Glukhovsky");
    books[2] = Book("LOTR", "JJR Tolkien");

    int input = -1;
    do
    {
        system("cls");

        cout << "1: Enter personal data" << endl;
        cout << "2: Borrow a book" << endl;
        cout << "3: Extend loan" << endl;
        cout << "4: Output all data" << endl;
        cout << "5: Return book" << endl;
        cout << "0: Exit program" << endl;

        cout << "Input: ";
        cin >> input;
        system("cls");

        switch(input)
        {
            case 1:
                {
                    p.enterData();
                    system("pause");
                    break;
                }

            case 2:
                {
                    if(l.getHasBook())
                    {
                        cout << "You need to return book first in order to borrow another one!"<<endl;
                    }
                    else
                    {
                        cout << "Select the book:"<<endl;
                        for(int i=0; i<3; i++)
                        {
                            cout << i+1 << ": ";
                            books[i].showData();
                        }
                        int bookInput = -1;
                        cin >> bookInput;
                        int bookIndex = bookInput-1;

                        system("cls");

                        cout<<"Enter return date: "<<endl;
                        d = Date();
                        d.enterData();

                        l = Loan(p,books[bookIndex],d);
                    }
                    system("pause");
                    break;
                }
            case 3:
                {
                    if(l.getHasBook())
                    {
                        l.extendLoan();
                        cout << "Loan of the book was extended, see details below!"<<endl;
                        l.showData();;
                    }
                    else
                    {
                        cout << "Person not borrowed any book!"<<endl;
                    }
                    system("pause");
                    break;
                }
            case 4:
                {
                    if(l.getHasBook())
                    {
                        cout << "Borrower:"<<endl;
                        p.showData();
                        cout << endl;
                        l.showData();
                    }
                    else
                    {
                        cout << "Person not borrowed any book!"<<endl;
                    }
                    system("pause");
                    break;
                }
            case 5:
                {
                    if(l.getHasBook())
                    {
                        cout << "Are you sure you want to return following book:"<<endl;
                        Book b = l.getBorrowerBook();
                        b.showData();

                        cout << "1: Yes"<<endl;
                        cout << "2. No"<<endl;
                        int returnInput = -1;
                        cin >> returnInput;

                        if(returnInput==1)
                        {
                            l.bookReturned();
                            cout << "Book was returned!"<<endl;
                        }
                    }
                    else
                    {
                        cout << "Person not borrowed any book!"<<endl;
                    }
                    system("pause");
                    break;
                }
            case 0:
                {
                    cout << "Goodbye!" << endl;
                    system("pause");
                    break;
                }
            default:
                {
                    system("cls");
                    cout << "Wrong input, try again!" << endl;
                    system("pause");
                }

        }
        cout << endl;
    }while(input != 0);

    return 0;
}
