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

class Employee
{
private:
    string surname;
    string firstName;
    Date birth;

    int daysTaken;
    bool isCreated;
    static int counter;
public:
    Employee();
    void enterCommon();
    void showCommon();
    void deleteEmployee();

    string getSurname();
    string getFirstName();
    Date getBirth();

    bool getIsCreated();
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

bool Employee:: getIsCreated()
{
    return isCreated;
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

    cout << "Employee: hourly"<<"\t";
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

    cout << "Employee: salaried" << "\t";
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

    cout << "Employee: manager"<<"\t";
    cout << "Profit sharing " << profitSharing<<"\t";
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
                cout << "---TYPE-OF-EMPLOYEE---"<<endl;
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
                        he.enterData();
                        db[i] = he;
                        dbHE[i] = he;

                        i++;
                        break;
                    }
                case 2: //[2] Salaried employee
                    {
                        se.enterData();
                        db[i] = se;
                        dbSE[i] = se;

                        i++;
                        break;
                    }

                case 3: //[3] Manager
                    {
                        m.enterData();
                        db[i] = m;
                        dbM[i] = m;

                        i++;
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
                int num = -1;
                system("cls");
                cout << "---DELETE-AT-POSITION---"<<endl;

                //show employee to delete
                for(int j = 0; j < i; j++)
                {
                    if(db[j].getIsCreated())
                    {
                        cout << "["<<j<<"] ";
                        db[j].showCommon();
                        cout << endl;
                    }
                }
                cout << endl << "Enter: ";
                cin >> num;

                system("cls");
                if(num<0 || num>=i)
                {
                    cout << "Non-existend index was entered!"<<endl;
                }
                else if(db[num].getIsCreated())
                {
                    db[num].deleteEmployee();
                    dbHE[num].deleteEmployee();
                    dbSE[num].deleteEmployee();
                    dbM[num].deleteEmployee();

                    cout <<"Following user was deleted!"<<endl;
                    db[num].showCommon();
                    cout<<endl;
                }
                else
                {
                    cout << "No employee is assigned to this index!"<<endl;
                }

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
                for(int j = 0; j < i; j++)
                {
                    if(dbHE[j].getIsCreated())
                    {
                        dbHE[j].showData();
                        cout << endl;
                    }
                }

                //SE
                for(int j = 0; j < i; j++)
                {
                    if(dbSE[j].getIsCreated())
                    {
                        dbSE[j].showData();
                        cout << endl;
                    }
                }

                //M
                for(int j = 0; j < i; j++)
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
