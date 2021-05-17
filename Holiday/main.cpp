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
    void enterDate();
    void showDate();
    bool isFifthyOrMore();
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

void Date::showDate()
{
    cout << day << "." << month << "." << year;
}

bool isFifthyOrMore()
{
//Source: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    time_t t = time(0);
    tm* now = localtime(&t);
    unsigned int actYear = now->tm_year + 1900;
    short actMonth = now->tm_mon + 1;
    short actDay = now->tm_mday;

    //TODO must be finished

    cout << actDay << "." << actMonth << "." << actYear << endl;
}

//---EMPLOYEE---

enum Type { HE, SE, M };

class Employee
{
private:
    string surname;
    string firstName;
    Date birth;
    int daysTaken;
    bool isCreated;
    Type type;
    static int counter;
public:
    Employee();
    void enterCommon();
    void showCommon();
    string getSurname();
    string getFirstName();
    Date getBirth();
    bool getIsCreated();
    Type getType();
    void setType(Type);
    static int getCounter();
};

Employee::Employee()
{
    daysTaken = 0;
    isCreated = false;
    birth = Date();
}

void Employee::enterCommon()
{
    cout << "---ENTER-DATA---" << endl;
    cout << "Surname: ";
    cin >> surname;
    cout << "First name: ";
    cin >> firstName;

    cout << "---BIRTH-DATE---"<<endl;
    birth.enterDate();

    counter++;
    isCreated = true;
}

void Employee::showCommon()
{
    cout << "Surname:" << getSurname() << "\t\tFirst name: " << getFirstName() << "\t\t";
    cout << "Birth: ";
    getBirth().showDate();
    cout << "\t\t";
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

bool Employee:: getIsCreated()
{
    return isCreated;
}

Type Employee::getType()
{
    return type;
}

void Employee::setType(Type t)
{
    type = t;
}

int Employee::counter = 0;

int Employee::getCounter()
{
    return counter;
}

//---HOURLY-EPMPLOYEE---

class HourlyEmployee : public Employee
{
private:
    double hourlyWage;
    int hoursWorked;
    static int heCounter;
public:
    HourlyEmployee():Employee(){};
    void enterData();
    void showData();
    static int getHeCounter();
};

void HourlyEmployee::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Hourly wage: ";
    cin >> hourlyWage;
    cout << "Hours worked: ";
    cin >> hoursWorked;

    setType(HE);
    heCounter++;
}

void HourlyEmployee::showData()
{
    showCommon();

    cout << "Type: hourly employee"<<"\t\t";
    cout << "Hourly wage: " << hourlyWage<<"\t\t";
    cout << "Hours worked: " << hoursWorked<<"\t\t";
}

int HourlyEmployee::heCounter = 0;

int HourlyEmployee::getHeCounter()
{
    return heCounter;
}

//---SALARIED-EMPLOYEE---

class SalariedEmployee : public Employee
{
private:
    double annualSalary;
    static int seCounter;
public:
    SalariedEmployee():Employee(){};
    void enterData();
    void showData();
    static int getSeCounter();
};

void SalariedEmployee::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Annual salary: ";
    cin >> annualSalary;

    setType(SE);
    seCounter++;
}

void SalariedEmployee::showData()
{
    showCommon();

    cout << "Type: salaried employee" << "\t\t";
    cout << "Annual salary: " << annualSalary<<"\t\t";
}

int SalariedEmployee::seCounter = 0;

int SalariedEmployee::getSeCounter()
{
    return seCounter;
}

//---MANAGER---

class Manager : public Employee
{
private:
    double profitSharing;
    static int mCounter;
public:
    Manager():Employee(){};
    void showData();
    void enterData();
    static int getMCounter();
};

void Manager::enterData()
{
    enterCommon();

    cout << "---DETAILS---"<<endl;
    cout << "Profit sharing: ";
    cin >> profitSharing;

    setType(M);
    mCounter++;
}

void Manager::showData()
{
    showCommon();

    cout << "Type: manager"<<"\t\t";
    cout << "Profit sharing " << profitSharing<<"\t\t";
}

int Manager::mCounter = 0;

int Manager::getMCounter()
{
    return mCounter;
}

//---MAIN-FUNCTION---

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

    int i = Employee::getCounter();

    int iHE = HourlyEmployee::getHeCounter();

    int iSE = SalariedEmployee::getSeCounter();

    int iM = Manager::getMCounter();

    int input = -1;
    do
    {
        system("cls");
        cout << "---STAFF-HOLIDAY-MANAGEMENT---" << endl;
        cout << "[1] Create an employee" << endl;
        cout << "[2] Delete the employee" << endl;
        cout << "[3] Enter the days of a holiday" << endl;
        cout << "[4] Data of the specific employee" << endl;
        cout << "[5] Data of all employees" << endl;
        cout << "[0] Exit" << endl;
        cout << endl << "Enter: ";
        cin >> input;

        switch(input)
        {
        case 1: //[1] Create an employee
            {
                int type = -1;
                system("cls");
                cout << "Select type of the employee"<<endl;
                cout << "[1] Hourly employee" << endl;
                cout << "[2] Salaried employee" << endl;
                cout << "[3] Manager" << endl;
                cout << endl << "Enter: ";
                cin >> type;

                bool wrongInput=false;
                system("cls");

                switch(type)
                {
                case 1: //[1] Hourly employee
                    {
                        HourlyEmployee he = HourlyEmployee();
                        he.enterData();
                        db[i] = he;
                        dbHE[iHE] = he;

                        i++;
                        iHE++;
                        break;
                    }
                case 2: //[2] Salaried employee
                    {
                        SalariedEmployee se = SalariedEmployee();
                        se.enterData();
                        db[i] = se;
                        dbSE[iSE] = se;

                        i++;
                        iSE++;
                        break;
                    }

                case 3: //[3] Manager
                    {
                        Manager m = Manager();
                        m.enterData();
                        db[i] = m;
                        dbM[iM] = m;

                        i++;
                        iM++;
                        break;
                    }
                default:
                    wrongInput = true;
                }

                if(wrongInput)
                {
                    cout << "Wrong input!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }

                system("pause");
                system("cls");
                break;
            }
        case 2: //[2] Delete the employee
            {
                system("cls");

                system("pause");
                system("cls");
                break;
            }
        case 3: //[3] Enter the days of a holiday
            {
                system("cls");

                system("pause");
                system("cls");
                break;
            }
        case 4: //[4] Data of the specific employee
            {
                system("cls");

                system("pause");
                system("cls");
                break;
            }
        case 5: //[5] Data of all employees
            {
                system("cls");

                //HE
                for(int j = 0; j <= iHE; j++)
                {
                    if(dbHE[j].getIsCreated())
                    {
                        dbHE[j].showData();
                        cout << endl;
                    }
                }

                //SE
                for(int j = 0; j <= iSE; j++)
                {
                    if(dbSE[j].getIsCreated())
                    {
                        dbSE[j].showData();
                        cout << endl;
                    }
                }

                //M
                for(int j = 0; j <= iM; j++)
                {
                    if(dbM[j].getIsCreated())
                    {
                        dbM[j].showData();
                        cout << endl;
                    }
                }

                system("pause");
                system("cls");
                break;
            }
        case 0: //[0] Exit
            {
                system("cls");
                cout << "STAFF HOLIDAY MANAGEMENT SYSTEM says Farewell!" << endl;
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
