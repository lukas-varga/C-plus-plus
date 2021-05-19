// Importing necessary libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// We can omit std:: prefix for IO and other methods
using namespace std;

//--------------------CLASSES--------------------

//---DATE---

// The class for  storing and handling dates
class Date{
private:
    short day;
    short month;
    unsigned int year;
public:
    // Default constructor which only generates empty date
    Date(){};
    Date(short d,short m,unsigned int y);
    void enterDate();
    void showDate();
    bool isItRealDate();
    bool isFifthyOrMore();
    static Date getCurrentDate();
};

// Overloaded constructor for creating date without entering by user
Date::Date(short d,short m,unsigned int y):day(d),month(m),year(y){}

// Initial method for retreiving birth day from user
void Date::enterDate()
{
    // It will ask user as long as valid date is entered
    bool actualDate = false;
    do
    {
        system("cls");
        cout << "---BIRTH-DATE---"<<endl;
        cout << "Day: ";
        cin >> day;
        cout << "Month: ";
        cin >> month;
        cout << "Year: ";
        cin >> year;

        // When date is not real it will give user some hints and repeat entering
        actualDate = isItRealDate();
        if(!actualDate)
        {
            cout<<endl<<"Please provide the real birth date!"<<endl;
            cout<<"(1.1.1900 - 31.12."<<getCurrentDate().year-1<<")"<<endl;
            system("pause");
        }
    }while(!actualDate);
}

// Method that print formated date to screen
void Date::showDate()
{
    cout << day << "." << month << "." << year;
}

// Method returns true if the date is real, otherwise it returns false
bool Date::isItRealDate()
{
    unsigned int actYear = getCurrentDate().year;

    // Only date from previous decade to last year
    if(year < 1900 || year >= actYear)
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

// Method returns true if person with current date is 50 or more years old
bool Date::isFifthyOrMore()
{
    // Getting current year
    unsigned int actYear = getCurrentDate().year;

    // Person is definitely older than 50 years old
    if(actYear-year > 50)
    {
        return true;
    }
    /*  Person was born on the 1.1. of current year
        and it counts to according to assignment */
    else if(actYear-year == 50 && month == 1 && day == 1)
    {
        return true;
    }
    // When person is younger than 50 years old
    return false;
}

// Static getter method for returning current date in format 'Date'
Date Date::getCurrentDate()
{
    // Source: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    time_t t = time(0);
    tm* now = localtime(&t);
    unsigned int actYear = now->tm_year + 1900;
    short actMonth = now->tm_mon + 1;
    short actDay = now->tm_mday;

    // Creating Date object which is immediately returned
    return Date(actDay,actMonth,actYear);
}

//----------PARENT-CLASS----------

//---EMPLOYEE---

// Class for storing general data about all employees within types
class Employee
{
private:
    string surname;
    string firstName;
    Date birth;

    // Store taken days of a holiday
    int takenHolidays;
    /*  When the person is entered it will change this value to true,
        otherwise the person is not active (even though the object is created)*/
    bool isCreated;
    /*  Counter which store information about how many employees were created
        It is always one more than real number because of '[0] Exit' operator */
    static int counter;
public:
    Employee();
    void enterCommon();
    void showCommon();
    bool enterHolidays();

    string getSurname();
    string getFirstName();
    Date getBirth();
    int getTakenHolidays();
    void setTakenHolidays(int);
    int getRemainingHolidays();
    bool getIsCreated();

    static int getCounter();
};

/*  Default constructor for general employee class.
    All the instances of 500 employees are created while initializing array */
Employee::Employee()
{
    // Taken holidays 0 are by default
    takenHolidays = 0;
    // Instance/object is created but person is not active/visible
    isCreated = false;
    // Creating empty instance for birth date without any values for now
    birth = Date();
}

// Default method for retrieving general employee data from user
void Employee::enterCommon()
{
    system("cls");
    cout << "---ENTER-DATA---" << endl;
    cout << "Surname: ";
    cin >> surname;
    cout << "First name: ";
    cin >> firstName;

    // User is asked about birth date
    birth.enterDate();

    system("cls");
    // Number of employees raised by 1
    counter++;
    // Person is created and visible to system
    isCreated = true;
}

// Printing general data about employees
void Employee::showCommon()
{
    cout << "Surname:" << getSurname() << "\tFirst name: " << getFirstName() << "\t";
    cout << "Birth: ";
    getBirth().showDate();
    cout << "\t";
}

// Getter returning string value surname
string Employee::getSurname()
{
    return surname;
}

// Getter returning string value of first name
string Employee::getFirstName()
{
    return firstName;
}

// Getter returning birth date of type 'Date'
Date Employee::getBirth()
{
    return birth;
}

/*  Boolean method that let user enter desired number of days for holiday.
    It also informs user about success or wrong input and it gives him hints.*/
bool Employee::enterHolidays()
{
    // Method keeps asking user for valid date (according to his free number of days of holidays)
    bool legitHolidays = false;
    do
    {
        int num = -1;
        system("cls");
        cout << "---ENTER-DAYS-OF-HOLIDAYS---"<<endl;
        // Displaying how many of days is allowed to enter
        cout << "Remaining holidays:\t"<<getRemainingHolidays()<<endl;
        cout << "[0] Exit" << endl;
        cout <<endl<< "Desired number of days: ";
        cin >> num;

        //If user does not want to answer and want to go back, he can just enter value 0
        if(num==0)
            return false;
        // Temp variable that stores sum of already taken holidays and entered holidays
        int newHolidays = takenHolidays + num;

        // Entered desired holidays exceed allowed holiday limit
        if(num > getRemainingHolidays())
        {
            legitHolidays = false;
            cout<<endl<<"Wrong input!"<<endl;
            cout<<"You have exceeded maximum number of holidays per year."<<endl;
            cout<<"Total days of holidays including entered ones:\t"<< newHolidays<<endl;
            cout<<"Remaining days of holidays for current year:\t"<<getRemainingHolidays()<<endl;
            system("pause");
        }
        // Desired holidays are valid and are added to employee informations and methods terminates
        else
        {
            legitHolidays = true;

            // Setting new value for taken holidays
            setTakenHolidays(newHolidays);

            cout<<endl<<"New holidays added!"<<endl;
            cout<<"Total days of holidays including entered ones:\t"<< newHolidays<<endl;
            cout<<"Remaining days of holidays for current year:\t"<<getRemainingHolidays()<<endl;
            system("pause");
        }
    }while(!legitHolidays);

    // Method also return true if user entered valid number of days of holidays
    return true;
}

// Getter returning currently taken days of holidays
int Employee::getTakenHolidays()
{
    return takenHolidays;
}

// Setter that set int value to attribute 'takenHolidays'
void Employee::setTakenHolidays(int num)
{
    takenHolidays = num;
}

// Method compute how many holidays remaining for this instance
int Employee::getRemainingHolidays()
{
    // Check employee's age
    bool older = (getBirth().isFifthyOrMore()) ? true : false;
    // According to employee's age/birthday it considers either 30 or 32 days of holiday
    int remaining = (older) ? 32-takenHolidays : 30-takenHolidays;
    return remaining;
}

// Getter returning true if employee is created otherwise false
bool Employee::getIsCreated()
{
    return isCreated;
}

/*  Static counter of number of employees.
    It starts indexing from 1 so it is always one more
    than actual number of employees because of '[0] Exit' operator */
int Employee::counter = 1;

// Getter for static counter of employees
int Employee::getCounter()
{
    return counter;
}

//----------CHILD-CLASSES----------

//---HOURLY-EPMPLOYEE---

/*  Class for storing additional information about employee of type hourly employee.
    It is derived from the class 'Employee' */
class HourlyEmployee : public Employee
{
private:
    // Storing hourly wage
    double hourlyWage;
    // Storing hours worked (could be for example 0.5 hours)
    double hoursWorked;
public:
    // Empty default constructor
    HourlyEmployee():Employee(){};
    void enterData();
    void showData();
};

// Method for asking user firstly about common and then additional data about hourly employee.
void HourlyEmployee::enterData()
{
    // Calling of parent method of class 'Employee' to retrieve general data
    enterCommon();

    // Asking about additional data
    cout << "---DETAILS---"<<endl;
    cout << "Hourly wage: ";
    cin >> hourlyWage;
    cout << "Hours worked: ";
    cin >> hoursWorked;
}

// Method for printing general and additional data about hourly employee
void HourlyEmployee::showData()
{
    // Calling parent method
    showCommon();

    cout << "Employee: Hourly"<<"\t";
    cout << "Hourly wage: " << hourlyWage<<"\t";
    cout << "Hours worked: " << hoursWorked<<"\t";
}

//---SALARIED-EMPLOYEE---

/*  Class for storing additional information about employee of type salaried employee.
    It is derived from the class 'Employee' */
class SalariedEmployee : public Employee
{
private:
    // Storing annual salary
    double annualSalary;
public:
    // Empty default constructor
    SalariedEmployee():Employee(){};
    void enterData();
    void showData();
};

// Method for asking user firstly about common and then additional data about salaried employee.
void SalariedEmployee::enterData()
{
    // Calling of parent method of class 'Employee' to retrieve general data
    enterCommon();

    // Asking about additional data
    cout << "---DETAILS---"<<endl;
    cout << "Annual salary: ";
    cin >> annualSalary;
}

// Method for printing general and additional data about salaried employee
void SalariedEmployee::showData()
{
    // Calling parent method
    showCommon();

    cout << "Employee: Salaried" << "\t";
    cout << "Annual salary: " << annualSalary<<"\t";
}

//---MANAGER---

/*  Class for storing additional information about employee of type manager employee.
    It is derived from the class 'Employee' */
class Manager : public Employee
{
private:
    // Storing profit sharing
    double profitSharing;
public:
    // Empty default constructor
    Manager():Employee(){};
    void showData();
    void enterData();;
};

// Method for asking user firstly about common and then additional data about manager employee.
void Manager::enterData()
{
    // Calling of parent method of class 'Employee' to retrieve general data
    enterCommon();

    // Asking about additional data
    cout << "---DETAILS---"<<endl;
    cout << "Profit sharing: ";
    cin >> profitSharing;
}

// Method for printing general and additional data about manager employee
void Manager::showData()
{
     // Calling parent method
    showCommon();

    cout << "Employee: Manager"<<"\t";
    cout << "Profit sharing " << profitSharing<<"\t";
}

//--------------------MAIN--------------------

/*  Auxiliary method for printing only general information about employees
    It takes number of existing employees as first parameter
    and array of object of type 'Employee' as second one. */
void displayEmployees(int, Employee[]);

int main()
{
    //TODO COMMENTS !!!!!!!!!!!!!!!!!!!!!!!!!!

    cout << "Welcome in STAFF HOLIDAY MANAGEMENT SYSTEM!" << endl;
    system("pause");

    const int DB_SIZE = 500;
    Employee db[DB_SIZE] = Employee();
    HourlyEmployee dbHE[DB_SIZE] = HourlyEmployee();
    SalariedEmployee dbSE[DB_SIZE] = SalariedEmployee();
    Manager dbM[DB_SIZE] = Manager();

    HourlyEmployee he = HourlyEmployee();
    SalariedEmployee se = SalariedEmployee();
    Manager m = Manager();

    int i = Employee::getCounter();

    int input = -1;
    do
    {
        system("cls");
        cout << "---STAFF-HOLIDAY-MANAGEMENT---" << endl;
        cout << "[1] Create an employee" << endl;
        cout << "[2] Delete the employee" << endl;
        cout << "[3] Enter the days of a holiday" << endl;
        cout << "[4] Details of the given employee" << endl;
        cout << "[5] Show data of all employees" << endl;
        cout << "[6] Reset holidays (a new calendar year)"<<endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Enter: ";
        cin >> input;

        switch(input)
        {
        case 1: //[1] Create an employee
            {
                bool correctInput=false;
                do
                {
                    int type = -1;
                    system("cls");
                    cout << "---TYPE-OF-EMPLOYEE---"<<endl;
                    cout << "[1] Hourly employee" << endl;
                    cout << "[2] Salaried employee" << endl;
                    cout << "[3] Manager" << endl;
                    cout << "[0] Exit" << endl;
                    cout << endl << "Enter: ";
                    cin >> type;

                    switch(type)
                    {
                    case 1: //[1] Hourly employee
                        {
                            he.enterData();
                            db[i] = he;
                            dbHE[i] = he;
                            correctInput = true;

                            i++;
                            break;
                        }
                    case 2: //[2] Salaried employee
                        {
                            se.enterData();
                            db[i] = se;
                            dbSE[i] = se;
                            correctInput = true;

                            i++;
                            break;
                        }

                    case 3: //[3] Manager
                        {
                            m.enterData();
                            db[i] = m;
                            dbM[i] = m;
                            correctInput = true;

                            i++;
                            break;
                        }
                    case 0:
                        correctInput=true;
                        break;
                    default:
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                }while(!correctInput);
                break;
            }
        case 2: //[2] Delete the employee
            {
                bool correctInput=false;
                do
                {
                    int num = -1;
                    system("cls");
                    cout << "---DELETE-AT-POSITION---"<<endl;

                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;

                    if(num==0)
                        correctInput=true;
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        cout<<endl <<"Following user was deleted!"<<endl;
                        db[num].showCommon();
                        cout<<endl;

                        db[num] = Employee();
                        dbHE[num] = HourlyEmployee();
                        dbSE[num] = SalariedEmployee();
                        dbM[num] = Manager();

                        system("pause");
                    }
                    else
                    {
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                }while(!correctInput);
                break;
            }
        case 3: //[3] Enter the days of a holiday
            {
                bool correctInput=false;
                do
                {
                    int num = -1;
                    system("cls");
                    cout << "---ENTER-HOLIDAYS-AT-POSITION---"<<endl;

                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;


                    if(num==0)
                        correctInput=true;
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        bool success = db[num].enterHolidays();
                        if (success)
                        {
                            int newHolidays = db[num].getTakenHolidays();
                            dbHE[num].setTakenHolidays(newHolidays);
                            dbSE[num].setTakenHolidays(newHolidays);
                            dbM[num].setTakenHolidays(newHolidays);
                        }
                    }
                    else
                    {
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                }while(!correctInput);
                break;
            }
        case 4: //[4] Data of the specific employee
            {
                bool correctInput=false;
                do
                {
                    int num = -1;
                    system("cls");
                    cout << "---EMPLOYEE-DETAILS-AT-POSITION---"<<endl;

                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;

                    if(num==0)
                        correctInput=true;
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        cout<<endl;
                        if(dbHE[num].getIsCreated())
                        {
                            dbHE[num].showData();
                        }
                        else if(dbSE[num].getIsCreated())
                        {
                            dbSE[num].showData();
                        }
                        else if(dbM[num].getIsCreated())
                        {
                            dbM[num].showData();
                        }

                        int taken = db[num].getTakenHolidays();
                        cout<<endl<<"Taken days of holidays:\t";
                        cout<<taken<<endl;

                        int remaining = db[num].getRemainingHolidays();
                        cout<<"Remaining days of holidays:\t";
                        cout<<remaining<<endl;
                        system("pause");
                    }
                    else
                    {
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                }while(!correctInput);
                break;
            }
        case 5: //[5] Data of all employees
            {
                system("cls");
                cout << "---DATA-OF-ALL-EMPLOYEES---"<<endl;
                cout << "---GROUP-BY-EMPLOYEE-TYPE---"<<endl;
                int indexer = 1;

                //HE
                for(int j=1; j <= i; j++)
                {
                    if(dbHE[j].getIsCreated())
                    {
                        cout << "("<< indexer++ <<") ";
                        dbHE[j].showData();
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbHE[j].getTakenHolidays()<<"/"<<dbHE[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                //SE
                for(int j=1; j <= i; j++)
                {
                    if(dbSE[j].getIsCreated())
                    {
                        cout << "("<< indexer++ <<") ";
                        dbSE[j].showData();
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbSE[j].getTakenHolidays()<<"/"<<dbSE[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                //M
                for(int j=1; j <= i; j++)
                {
                    if(dbM[j].getIsCreated())
                    {
                        cout << "("<< indexer++ <<") ";
                        dbM[j].showData();
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbM[j].getTakenHolidays()<<"/"<<dbM[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                system("pause");
                system("cls");
                break;
            }
        case 6: //[6] Reset holidays (a new calendar year)
            {
                int answer = -1;
                system("cls");
                cout << "---DO-YOU-WANT-TO-RESET-HOLIDAYS?---"<<endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
                cout << "[0] Exit" << endl;
                cout << endl << "Enter: ";
                cin >> answer;

                switch(answer)
                {
                case 1: //[1] YES
                    {
                        //EMPLOYEE
                        for(int j=1; j <= i; j++)
                        {
                            db[j].setTakenHolidays(0);
                        }

                        //HE
                        for(int j=1; j <= i; j++)
                        {
                            dbHE[j].setTakenHolidays(0);
                        }

                        //SE
                        for(int j=1; j <= i; j++)
                        {
                            dbSE[j].setTakenHolidays(0);
                        }

                        //M
                        for(int j=1; j <= i; j++)
                        {
                            dbM[j].setTakenHolidays(0);
                        }

                        cout<<endl<<"Holidays were succesfuly reset!"<<endl;
                        system("pause");
                        break;
                    }
                case 2: //[2] NO
                case 0: //[0] Exit
                default:
                    {
                        cout<<endl<<"Holidays were NOT reset!"<<endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
        case 0: //[0] Exit
            {
                system("cls");
                cout << "STAFF HOLIDAY MANAGEMENT SYSTEM says farewell!" << endl;
                system("pause");
                break;
            }
        default: //Wrong input
            {
                input = -1;
                cout << endl << "Wrong input!" << endl;
                system("pause");
            }
        }
    }while(input!=0);

    return 0;
}

/*  Auxiliary method for printing only general information about employees
    It takes number of existing employees as first parameter
    and array of object of type 'Employee' as second one. */
void displayEmployees(int i, Employee db[])
{
    // Iterating all employees up to the newest one
    for(int j=1; j <= i; j++)
    {
        // When employee exists (is created) we show him to user
        if(db[j].getIsCreated())
        {
            // Displayed indexing can skip deleted employees so it is not necessary 1..2..3 seqential
            cout << "["<<j<<"] ";
            // Show general data about employee
            db[j].showCommon();
            cout << endl;
        }
    }
    // Displaying  Exit operator
    cout << "[0] Exit" << endl;
}
