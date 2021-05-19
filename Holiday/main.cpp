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

// Main method where the program starts
int main()
{
    // Welcome screen
    cout << "---STAFF-HOLIDAY-MANAGEMENT---" << endl;
    cout << "by Lukas Varga"<<endl;
    system("pause");

    /*  Creating array of size 500 for general employees.
        First idea was create only one array of class 'Employee',
        but I was not able to manage accessing methods of child classes.
        Simple type conversion and casting like in Java was not possible.
        Thats why I decided to created mirrored arrays for each sub-class. */
    const int DB_SIZE = 500;
    Employee db[DB_SIZE] = Employee();
    // Creating mirror arrays of size 500 for all types of employees (sub-classes)
    HourlyEmployee dbHE[DB_SIZE] = HourlyEmployee();
    SalariedEmployee dbSE[DB_SIZE] = SalariedEmployee();
    Manager dbM[DB_SIZE] = Manager();

    // Creating auxiliary instances
    HourlyEmployee he = HourlyEmployee();
    SalariedEmployee se = SalariedEmployee();
    Manager m = Manager();

    // Initialization of main indexer used for all arrays (super and sub classes)
    int i = Employee::getCounter();

    // User input variable for main screen
    int input = -1;
    // Stay in loop till user enter value 0
    do
    {
        // Printing main menu
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

        // Deciding which action from menu will be executed
        switch(input)
        {
        //[1] Create an employee
        case 1:
            {
                // Using infinite loop with inner menu
                bool correctInput=false;
                do
                {
                    // Displaying menu for which type of employee will be entered and storing input in variable
                    int type = -1;
                    system("cls");
                    cout << "---TYPE-OF-EMPLOYEE---"<<endl;
                    cout << "[1] Hourly employee" << endl;
                    cout << "[2] Salaried employee" << endl;
                    cout << "[3] Manager" << endl;
                    cout << "[0] Exit" << endl;
                    cout << endl << "Enter: ";
                    cin >> type;

                    /*  Deciding which employee type will be created.
                        When the type is correctly chosen the value
                        of temporary boolean variable is changed to true. */
                    switch(type)
                    {
                    //[1] Hourly employee
                    case 1:
                        {
                            /*  Entering data by user and storing object to super-class array
                                and also to according sub-class array of hourly employee. */
                            he.enterData();
                            db[i] = he;
                            dbHE[i] = he;
                            correctInput = true;

                            // Incrementing array indexer (common for all arrays)
                            i++;
                            break;
                        }
                    //[2] Salaried employee
                    case 2:
                        {
                            /*  Entering data by user and storing object to super-class array
                                and also to according sub-class array of salaried employee. */
                            se.enterData();
                            db[i] = se;
                            dbSE[i] = se;
                            correctInput = true;

                            // Incrementing array indexer (common for all arrays)
                            i++;
                            break;
                        }
                    //[3] Manager
                    case 3:
                        {
                            /*  Entering data by user and storing object to super-class array
                                and also to according sub-class array of manager. */
                            m.enterData();
                            db[i] = m;
                            dbM[i] = m;
                            correctInput = true;

                            // Incrementing array indexer (common for all arrays)
                            i++;
                            break;
                        }
                    // [0] Exit
                    case 0:
                        // Typing 0 will terminated infinite loop without adding new employee
                        correctInput=true;
                        break;
                    // Notifying user about wrong input, loop starts again after pressing button
                    default:
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                // Terminating of loop when a new employee was entered or user cancel the transaction
                }while(!correctInput);
                break;
            }
        //[2] Delete the employee
        case 2:
            {
                // Using infinite loop with inner menu
                bool correctInput=false;
                do
                {
                    // Initializing input variable
                    int num = -1;
                    system("cls");
                    cout << "---DELETE-AT-POSITION---"<<endl;

                    /*  Displaying of rough information (without details) about users
                        Records are counted with according indexes user can choose from. */
                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;

                    // Terminating if user input is 0
                    if(num==0)
                        correctInput=true;
                    // Notifying user about wrong input when index is out of possible range of existing employees in array
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    // Correct input (employee is created and thus can be deleted)
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        // Informing user about details of deleted employee
                        cout<<endl <<"Following user was deleted!"<<endl;
                        db[num].showCommon();
                        cout<<endl;

                        /*  Deleting employee in main and mirrored arrays
                            Assigning new empty instance will automatically remove all previously entered data
                            and also set 'isCreated' instance attribute to false (default). */
                        db[num] = Employee();
                        dbHE[num] = HourlyEmployee();
                        dbSE[num] = SalariedEmployee();
                        dbM[num] = Manager();

                        system("pause");
                    }
                    // If user enter something else what is not correct
                    else
                    {
                        // Loop continue and user needs to enter new input
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                // Terminating of infinite loop
                }while(!correctInput);
                break;
            }
        //[3] Enter the days of a holiday
        case 3:
            {
                // Using infinite loop with inner menu
                bool correctInput=false;
                do
                {
                    // Printing title and initializing input variable
                    int num = -1;
                    system("cls");
                    cout << "---ENTER-HOLIDAYS-AT-POSITION---"<<endl;

                    // Displaying the employee we can choose from for entering holidays
                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;

                    // Terminating condition without entering value
                    if(num==0)
                        correctInput=true;
                    // Index is out of valid boundaries
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    // Correct index entered
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        /*  Calling method of entering holidays.
                            It can either return true which indicates that object in main array
                            has new valid value for attribute 'takenHolidays and thus
                            we will distribute this new value to mirror arrays.
                            Otherwise when there is returned false, no change with given attribute was made. */
                        bool success = db[num].enterHolidays();
                        if (success)
                        {
                            // Setting new values in case of success
                            int newHolidays = db[num].getTakenHolidays();
                            dbHE[num].setTakenHolidays(newHolidays);
                            dbSE[num].setTakenHolidays(newHolidays);
                            dbM[num].setTakenHolidays(newHolidays);
                        }
                    }
                    // Index is not valid
                    else
                    {
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                // Terminating of the loop
                }while(!correctInput);
                break;
            }
        //[4] Data of the specific employee
        case 4:
            {
                // Using infinite loop with inner menu
                bool correctInput=false;
                do
                {
                    // Printing title and initializing input variable
                    int num = -1;
                    system("cls");
                    cout << "---EMPLOYEE-DETAILS-AT-POSITION---"<<endl;

                    // Displaying the employee we can choose from
                    displayEmployees(i,db);
                    cout << endl << "Enter: ";
                    cin >> num;

                    // Terminating condition without entering value
                    if(num==0)
                        correctInput=true;
                    // Index is out of valid boundaries
                    else if(num<0 || num>i)
                    {
                        correctInput = false;
                        cout << endl<<"Non-nonexistent index was entered!"<<endl;
                        system("pause");
                    }
                    // Correct input
                    else if(db[num].getIsCreated())
                    {
                        correctInput = true;

                        /*  Displaying user details depending on the sub-class he is part of
                            Employee is only allowed to be just one type and that's why
                            only one records will be display at any circumstances. */
                        cout<<endl;
                        if(dbHE[num].getIsCreated())
                        {
                            // Details data about hourly employee
                            dbHE[num].showData();
                        }
                        else if(dbSE[num].getIsCreated())
                        {
                            // Details data about salaried employee
                            dbSE[num].showData();
                        }
                        else if(dbM[num].getIsCreated())
                        {
                            // Details data about manager
                            dbM[num].showData();
                        }

                        // Printing additional info about taken holidays
                        int taken = db[num].getTakenHolidays();
                        cout<<endl<<"Taken days of holidays:\t\t";
                        cout<<taken<<endl;

                        // Printing additional info about remaining holidays
                        int remaining = db[num].getRemainingHolidays();
                        cout<<"Remaining days of holidays:\t";
                        cout<<remaining<<endl;
                        system("pause");
                    }
                    // Any other input which was not catch earlier
                    else
                    {
                        // Telling user that input was incorrect and loop will start over
                        correctInput=false;
                        cout << endl<<"Wrong input!"<<endl;
                        system("pause");
                    }
                // Terminating of the loop
                }while(!correctInput);
                break;
            }
        //[5] Data of all employees
        case 5:
            {
                // Printing title
                system("cls");
                cout << "---DATA-OF-ALL-EMPLOYEES---"<<endl;
                cout << "---GROUP-BY-EMPLOYEE-TYPE---"<<endl;
                /*  Incrementing variable for making easy to read records
                    by putting number in front of every row */
                int indexer = 1;

                // Displaying all stored info about hourly employees
                for(int j=1; j <= i; j++)
                {
                    // Displaying only existing employees
                    if(dbHE[j].getIsCreated())
                    {
                        // Printing number of row
                        cout << "("<< indexer++ <<") ";
                        // Printing detailed data
                        dbHE[j].showData();
                        //Adding info about taken/remaining holidays
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbHE[j].getTakenHolidays()<<"/"<<dbHE[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                // Displaying all stored info about salaried employees
                for(int j=1; j <= i; j++)
                {
                    // Displaying only existing employees
                    if(dbSE[j].getIsCreated())
                    {
                        // Printing number of row
                        cout << "("<< indexer++ <<") ";
                        // Printing detailed data
                        dbSE[j].showData();
                        //Adding info about taken/remaining holidays
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbSE[j].getTakenHolidays()<<"/"<<dbSE[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                // Displaying all stored info about managers
                for(int j=1; j <= i; j++)
                {
                    // Displaying only existing employees
                    if(dbM[j].getIsCreated())
                    {
                        // Printing number of row
                        cout << "("<< indexer++ <<") ";
                        // Printing detailed data
                        dbM[j].showData();
                        //Adding info about taken/remaining holidays
                        cout<<"Taken/remaining holidays:\t";
                        cout<<dbM[j].getTakenHolidays()<<"/"<<dbM[j].getRemainingHolidays();
                        cout << endl;
                    }
                }

                // Stopping program so user can read output
                system("pause");
                system("cls");
                break;
            }
        //[6] Reset holidays (a new calendar year)
        case 6:
            {
                // Input variable and printing menu
                int answer = -1;
                system("cls");
                cout << "---DO-YOU-WANT-TO-RESET-HOLIDAYS?---"<<endl;
                cout << "[1] YES" << endl;
                cout << "[2] NO" << endl;
                cout << "[0] Exit" << endl;
                cout << endl << "Enter: ";
                cin >> answer;

                /*  If answer is YES, holidays are reseted to 0 for all employees (for example when a new calendar year comes).
                    For all other responses the task terminates and no changes are made .*/
                switch(answer)
                {
                //[1] YES
                case 1:
                    {
                        // Reseting holidays in employee array
                        for(int j=1; j <= i; j++)
                        {
                            db[j].setTakenHolidays(0);
                        }

                        // Reseting holidays in hourly employee array
                        for(int j=1; j <= i; j++)
                        {
                            dbHE[j].setTakenHolidays(0);
                        }

                        // Reseting holidays in salaried employee array
                        for(int j=1; j <= i; j++)
                        {
                            dbSE[j].setTakenHolidays(0);
                        }

                        // Reseting holidays in manager array
                        for(int j=1; j <= i; j++)
                        {
                            dbM[j].setTakenHolidays(0);
                        }

                        cout<<endl<<"Holidays were succesfuly reset!"<<endl;
                        system("pause");
                        break;
                    }
                //[2] NO
                case 2:
                //[0] Exit
                case 0:
                // Any other input
                default:
                    {
                        // For all of those values, which are different from YES, the task terminates
                        cout<<endl<<"Holidays were NOT reset!"<<endl;
                        system("pause");
                        break;
                    }
                }
                break;
            }
        //[0] Exit
        case 0:
            {
                // Goodbye message while closing the whole program is displayed
                system("cls");
                cout << "---STAFF-HOLIDAY-MANAGEMENT---" << endl;
                cout << "Farewell!"<<endl;
                system("pause");
                break;
            }
        // For any other input different from defined the notification about wrong input is displayed to user
        default:
            {
                input = -1;
                cout << endl << "Wrong input!" << endl;
                system("pause");
            }
        }
    // Terminating of the main menu loop
    }while(input!=0);

    // Returning from main method means that the whole program is terminated
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
