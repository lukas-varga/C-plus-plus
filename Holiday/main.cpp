#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//---DATE---

class Date{
private:
    short day;
    short month;
    unsigned int year;
public:
    Date(){};
    Date(short d,short m,unsigned int y);
    void enterDate();
    void showDate();
    bool isItRealDate();
    bool isFifthyOrMore();
    static Date getCurrentDate();
};

Date::Date(short d,short m,unsigned int y):day(d),month(m),year(y){}

void Date::enterDate()
{
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

        actualDate = isItRealDate();
        if(!actualDate)
        {
            cout<<endl<<"Please provide the real birth date!"<<endl;
            cout<<"(1.1.1900 - 31.12."<<getCurrentDate().year-1<<")"<<endl;
            system("pause");
        }
    }while(!actualDate);
}


void Date::showDate()
{
    cout << day << "." << month << "." << year;
}

bool Date::isItRealDate()
{
    unsigned int actYear = getCurrentDate().year;

    //only from previous decade to now
    if(year < 1900 || year >= actYear)
        return false;
    else if(month < 1 || month > 12)
        return false;
    else if(day < 1 || day > 31)
        return false;

    //leap year
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
    return true;

}

bool Date::isFifthyOrMore()
{
    unsigned int actYear = getCurrentDate().year;

    if(actYear-year > 50)
    {
        return true;
    }
    else if(actYear-year == 50 && month == 1 && day == 1)
    {
        return true;
    }
    return false;
}

Date Date::getCurrentDate()
{
    //Source: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    time_t t = time(0);
    tm* now = localtime(&t);
    unsigned int actYear = now->tm_year + 1900;
    short actMonth = now->tm_mon + 1;
    short actDay = now->tm_mday;

    return Date(actDay,actMonth,actYear);
}

//---EMPLOYEE---

class Employee
{
private:
    string surname;
    string firstName;
    Date birth;

    int takenHolidays;
    bool isCreated;
    static int counter;
public:
    Employee();
    void enterCommon();
    void showCommon();
    void deleteEmployee();
    bool enterHolidays();
    int getRemainingHolidays();

    string getSurname();
    string getFirstName();
    Date getBirth();
    int getTakenHolidays();
    void setTakenHolidays(int);
    bool getIsCreated();

    static int getCounter();
};

Employee::Employee()
{
    takenHolidays = 0;
    isCreated = false;
    birth = Date();
}

void Employee::enterCommon()
{
    system("cls");
    cout << "---ENTER-DATA---" << endl;
    cout << "Surname: ";
    cin >> surname;
    cout << "First name: ";
    cin >> firstName;

    birth.enterDate();

    system("cls");
    counter++;
    isCreated = true;
}

void Employee::showCommon()
{
    cout << "Surname:" << getSurname() << "\tFirst name: " << getFirstName() << "\t";
    cout << "Birth: ";
    getBirth().showDate();
    cout << "\t";
}

void Employee::deleteEmployee()
{
    isCreated = false;
}

string Employee::getSurname()
{
    return surname;
}

string Employee::getFirstName()
{
    return firstName;
}

Date Employee::getBirth()
{
    return birth;
}


int Employee::getRemainingHolidays()
{
    bool older = (getBirth().isFifthyOrMore()) ? true : false;
    int remaining = (older) ? 32-takenHolidays : 30-takenHolidays;
    return remaining;
}

bool Employee::enterHolidays()
{
    bool legitHolidays = false;
    do
    {
        int num = -1;
        system("cls");
        cout << "---ENTER-DAYS-OF-HOLIDAYS---"<<endl;
        cout << "Remaining holidays:\t"<<getRemainingHolidays()<<endl;
        cout << "[0] Exit" << endl;
        cout <<endl<< "Wished days: ";
        cin >> num;

        if(num==0)
            return false;
        int newHolidays = takenHolidays + num;
        if(num > getRemainingHolidays())
        {
            legitHolidays = false;
            cout<<endl<<"Wrong input!"<<endl;
            cout<<"You have exceeded maximum number of holidays per year."<<endl;
            cout<<"Total days of holidays including entered ones:\t"<< newHolidays<<endl;
            cout<<"Remaining days of holidays for current year:\t"<<getRemainingHolidays()<<endl;
            system("pause");
        }
        else
        {
            legitHolidays = true;

            setTakenHolidays(newHolidays);

            cout<<endl<<"New holidays added!"<<endl;
            cout<<"Total days of holidays including entered ones:\t"<< newHolidays<<endl;
            cout<<"Remaining days of holidays for current year:\t"<<getRemainingHolidays()<<endl;
            system("pause");
        }
    }while(!legitHolidays);
    return true;
}

int Employee::getTakenHolidays()
{
    return takenHolidays;
}

void Employee::setTakenHolidays(int num)
{
    takenHolidays = num;
}

bool Employee::getIsCreated()
{
    return isCreated;
}

int Employee::counter = 1;

int Employee::getCounter()
{
    return counter;
}

//---HOURLY-EPMPLOYEE---

class HourlyEmployee : public Employee
{
private:
    double hourlyWage;
    double hoursWorked;
public:
    HourlyEmployee():Employee(){};
    void enterData();
    void showData();
};

void HourlyEmployee::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Hourly wage: ";
    cin >> hourlyWage;
    cout << "Hours worked: ";
    cin >> hoursWorked;
}

void HourlyEmployee::showData()
{
    showCommon();

    cout << "Employee: Hourly"<<"\t";
    cout << "Hourly wage: " << hourlyWage<<"\t";
    cout << "Hours worked: " << hoursWorked<<"\t";
}

//---SALARIED-EMPLOYEE---

class SalariedEmployee : public Employee
{
private:
    double annualSalary;
public:
    SalariedEmployee():Employee(){};
    void enterData();
    void showData();
};

void SalariedEmployee::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Annual salary: ";
    cin >> annualSalary;
}

void SalariedEmployee::showData()
{
    showCommon();

    cout << "Employee: Salaried" << "\t";
    cout << "Annual salary: " << annualSalary<<"\t";
}

//---MANAGER---

class Manager : public Employee
{
private:
    double profitSharing;
public:
    Manager():Employee(){};
    void showData();
    void enterData();;
};

void Manager::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Profit sharing: ";
    cin >> profitSharing;
}

void Manager::showData()
{
    showCommon();

    cout << "Employee: Manager"<<"\t";
    cout << "Profit sharing " << profitSharing<<"\t";
}

//---MAIN-METHODS---

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
                        db[num].deleteEmployee();
                        dbHE[num].deleteEmployee();
                        dbSE[num].deleteEmployee();
                        dbM[num].deleteEmployee();

                        cout<<endl <<"Following user was deleted!"<<endl;
                        db[num].showCommon();
                        cout<<endl;
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
                cout << "---GROUP-BY-EMPLOYEE TYPE---"<<endl;
                //HE
                for(int j=1; j <= i; j++)
                {
                    if(dbHE[j].getIsCreated())
                    {
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

void displayEmployees(int i, Employee db[])
{
    for(int j=1; j <= i; j++)
    {
        if(db[j].getIsCreated())
        {
            cout << "["<<j<<"] ";
            db[j].showCommon();
            cout << endl;
        }
    }
    cout << "[0] Exit" << endl;
}
