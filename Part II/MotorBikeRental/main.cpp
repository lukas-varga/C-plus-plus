#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <limits>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

//TODO logic of read and write

unsigned int getCurrentYear();

class Motorbike
{
private:
    string name;
    bool isAvailable;
public:
    Motorbike() {}
    Motorbike(string name, bool isAvailable): name(name), isAvailable(isAvailable) {}

    string getName() { return name; }
    void setName(string name) { name = name; }
    bool getIsAvailable() { return isAvailable; }
    void setIsAvailable(bool aval) { isAvailable = aval; }

    friend ostream& operator<<(ostream& os, Motorbike& m);
};

ostream& operator<<(ostream& os, Motorbike& m)
{
    cout << "Motorbike: " << m.name << "\t";
    string ans = (m.isAvailable) ? "yes" : "no";
    cout << "Available: " << ans << "\t" << endl;
    return os;
}

class Customer
{
friend class ListCustomers;
private:
    string firstName;
    string lastName;
    string street;
    long postalCode;
    string city;
    unsigned int yearOfBirth;
    long phoneNumber;
    bool licenceA;

    Motorbike *bikeRented;
    Customer *successor;
public:
    Customer() { successor = 0; }
    Customer(
        string firstName,
        string lastName,
        string street,
        long postalCode,
        string city,
        unsigned int yearOfBirth,
        long phoneNumber,
        bool licenceA,
        Motorbike* bikeRented,
        Customer* successor);
    ~Customer() { delete successor; }

    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getStreet() { return street; }
    long getPostalCode() { return postalCode; }
    string getCity() { return city; }
    unsigned int getYearOfBirth() { return yearOfBirth; }
    long getPhoneNumber() { return phoneNumber; }
    bool getLicenceA() { return licenceA; }

    Motorbike* getBikeRented() { return bikeRented; }
    void setBikeRented(Motorbike* bikeRented) { this->bikeRented = bikeRented; }
    Customer* next() { return successor; }

    friend istream& operator>>(istream& is, Customer& c);
    friend ostream& operator<<(ostream& os, Customer& c);
};

Customer::Customer(
            string firstName,
            string lastName,
            string street,
            long postalCode,
            string city,
            unsigned int yearOfBirth,
            long phoneNumber,
            bool licenceA,
            Motorbike* bikeRented,
            Customer* successor )
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->street = street;
    this->postalCode = postalCode;
    this->city = city;
    this->yearOfBirth = yearOfBirth;
    this->phoneNumber = phoneNumber;
    this->licenceA = licenceA;
    this->bikeRented = bikeRented;
    this->successor = successor;
}

istream& operator>>(istream& is, Customer& c)
{
    while(true)
    {
        try
        {
            system("cls");
            cout << "--- Add the customer ---" << endl;
            cout << "First name: ";
            is >> c.firstName;
            cout <<  "Last name: ";
            is >> c.lastName;

            cout << "--- Address ---" << endl;
            cout << "Street: ";
            is >> c.street;
            cout << "Postal code: ";
            is >> c.postalCode;
            if(!is)
                throw (string) "Wrong postal code";

            cout << "City: ";
            is >> c.city,

            cout << "--- Additional Info ---" << endl;
            cout << "Year of birth: ";
            is >> c.yearOfBirth;
            // Checking if year is valid
            if(!is || c.yearOfBirth < 1900 || c.yearOfBirth > getCurrentYear())
                throw (string) "Wrong year of birth \n" + "Please provide a year between " + to_string(1900) + " and " + to_string(getCurrentYear());

            cout << "Phone number: ";
            is >> c.phoneNumber;
            if(!is)
                throw (string) "Wrong phone number";

            string answer;
            cout << "A driving licence (y/n): ";
            is >> answer;

            if(answer == "y")
                c.licenceA = true;
            else if(answer == "n")
                c.licenceA = false;
            else
                throw (string) "Wrong A driving licence input";

            c.bikeRented = 0;
            cout << endl << "Customer was successfully registered to the system" << endl;

            break;
        }
        catch (string e)
        {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << e << "!" << endl;
            system("pause");
        }
    }

    return is;
}

ostream& operator<<(ostream& os, Customer& c)
{
    const string DELIMETER = " | ";
    string answer;

    os <<  "First name: ";
    os << c.firstName << DELIMETER;
    os <<  "Last name: ";
    os << c.lastName << DELIMETER;

    os << "Street: ";
    os << c.street << DELIMETER;
    os << "PS: ";
    os << c.postalCode << DELIMETER;

    os << "City: ";
    os << c.city << DELIMETER;

    os << "Year: ";
    os << c.yearOfBirth << DELIMETER;

    os << "Phone: ";
    os << c.phoneNumber << DELIMETER;

    os << "A licence: ";
    answer = (c.licenceA) ? "yes" : "no";
    os << answer << DELIMETER;


    os << "Rented: ";
    answer = (c.bikeRented != 0) ? c.bikeRented->getName() : "any";
    os << answer << endl;

    return os;
}

class ListCustomers
{
private:
    Customer* head;
public:
    ListCustomers() { head = 0; }
    ~ListCustomers() { delete head; }

    Customer* getHead() { return head; }
    bool isEmpty(){ return head == 0; }

    void add(Customer*);
    Customer* search(string,string);
    void remove(Customer*);
    void display();
    void clear();
};

void ListCustomers::add(Customer *it)
{
    if (isEmpty())
    {
        head = it;
    }
    else
    {
        it->successor = head;
        head = it;
    }
}

Customer* ListCustomers::search(string first, string last)
{
    if(isEmpty())
    {
        return 0;
    }

    Customer *it;
    for (it = head; it != NULL; it = it->successor)
    {
        if((it->firstName == first) && (it->lastName == last))
        {
            return it;
        }
    }

    return 0;
}

void ListCustomers::remove(Customer* selected)
{
    if(head == selected)
    {
        Customer *newHead = selected->successor;
        selected->successor = 0;
        head = newHead;

        delete selected;
        return;
    }

    Customer *it = head;
    Customer *previous;
    while (it != 0)
    {
        previous = it;
        it = it->successor;

        if(it == selected)
        {
            previous->successor = selected->successor;
            selected->successor = 0;

            delete selected;
            break;
        }
    }
}

void ListCustomers::display()
{
    int i=0;
    for (Customer* it = head; it != NULL; it = it->successor)
    {
        cout << "[" << ++i <<"] ";
        cout << *it;
    }
}

void ListCustomers::clear()
{
    Customer *it;
    while(!isEmpty())
    {
        it = head->successor;
        delete head;
        head = it;
    }
}

ListCustomers cList;
const int NUM_MB = 4;
Motorbike* mb[NUM_MB];

void addCustomer();
void makeReservation();
void returnBike();
void displayMotorbikes();
void displayList();
void removeList();


const string CSV_DEL = ",";
const string FILE_NAME = "reservations.txt";
void readFromFile();
void insertOneRecord(vector<string> vect);
void saveToFile();

int main()
{
    const string ARR_MB[NUM_MB] = {"Suzuki Bandit", "Honda TransAlp", "BMW F 650 GS", "Kawasaki ZZR1400"};
    for(int i=0; i<NUM_MB; i++)
    {
        mb[i] = new Motorbike(ARR_MB[i],true);
    }

    readFromFile();
    system("pause");

    int selection = -1;
    bool keepGoing = true;
    do
    {
        system("cls");

        cout << "--- MOTORBIKE RENTAL ---" << endl;
        cout << "[1] Add a customer" << endl;
        cout << "[2] Make a reservation" << endl;
        cout << "[3] Return the motorbike (remove the record)" << endl;
        cout << "[4] Show motorbikes" << endl;
        cout << "[5] Display customers' data" << endl;
        cout << "[6] Remove all records" << endl;
        cout << "[0] Exit program" << endl;
        cout << ">Enter: ";
        cin >> selection;
        cout << endl;

        // https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
        if(!cin) // or if(cin.fail())
        {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput

            cout << "Wrong input!" << endl;
            system("pause");
            continue;
        }

        switch (selection)
        {
            case 0: // [0] Exit program
                keepGoing = false;
                break;
            case 1: // [1] Add the customer
            {
                system("cls");
                addCustomer();
                saveToFile();
                system("pause");
                break;
            }

            case 2: // [2] Make a reservation
            {
                system("cls");
                makeReservation();
                saveToFile();
                system("pause");
                break;
            }
            case 3: // [3] Return the motorbike (remove the record)
            {
                system("cls");
                returnBike();
                saveToFile();
                system("pause");
                break;
            }
            case 4: // {4] Show motorbikes
            {
                system("cls");
                cout << "--- Show motorbikes ---" << endl;
                displayMotorbikes();
                cout << endl;
                system("pause");
                break;
            }
            case 5: // [5] Display customers' data
            {
                system("cls");
                cout << "--- Display customers' data ---" << endl;
                displayList();
                cout << endl;
                system("pause");
                break;
            }

            case 6: // [6] Remove all records
            {
                system("cls");
                removeList();
                saveToFile();
                system("pause");
                break;
            }
            default: // Incorrect input
                break;
        }
    } while (keepGoing);

    //Delete all elements of the cList
    saveToFile();
    cList.clear();

    system("pause");
    return 0;
}

void addCustomer()
{
    Customer* c = new Customer();
    cin >> *c;
/*
    Customer* ptC = new Customer(
                        c.firstName,
                        c.lastName,
                        c.street,
                        c.postalCode,
                        c.city,
                        c.yearOfBirth,
                        c.phoneNumber,
                        c.licenceA,
                        c.bikeRented,
                        c.successor );
*/
    cList.add(c);
}

void makeReservation()
{
    string first, last;
    try
    {
        cout << "--- Make a reservation ---" << endl;
        cList.display();
        cout << endl;

        cout << "--- Enter the name ---" << endl;
        cout << ">First name: ";
        cin >> first;
        cout << ">Last name: ";
        cin >> last;

        system("cls");
        cout << "--- Make a reservation ---" << endl;
        Customer* res = cList.search(first, last);
        if(res == 0)
            throw (string) "Customer with given name was not found";
        if(!res->getLicenceA())
            throw (string) "Customer does not have A driving licence";
        if(res->getBikeRented() != 0)
            throw (string) "Customer already has a motorbike rented";

        //Choosing a motorbike
        system("cls");
        cout << "--- Choose a motorbike ---" << endl;
        displayMotorbikes();
        cout << ">Enter: ";

        int sel = -1;
        cin >> sel;

        system("cls");
        cout << "--- Make a reservation ---" << endl;
        if(!cin || sel < 1 || sel > NUM_MB)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw (string) "Wrong input";
        }

        Motorbike* bike = mb[sel-1];
        if(!bike->getIsAvailable())
            throw (string) "Given bike is not available right now";

        // Passed all the tests before
        res->setBikeRented(bike);
        bike->setIsAvailable(false);

        cout << "A motorbike was rented. See details:" << endl;
        cout << "[1] ";
        cout << *res;
    }
    catch(string e)
    {
        cout << "Transaction was terminated:" << endl;
        cout << e << endl;
    }
}

void returnBike()
{
    string first, last;
    try
    {
        cout << "--- Return the motorbike (remove the record) ---" << endl;
        cList.display();
        cout << endl;

        cout << "--- Enter the name ---" << endl;
        cout << ">First name: ";
        cin >> first;
        cout << ">Last name: ";
        cin >> last;

        system("cls");
        cout << "--- Return the motorbike (remove the record) ---" << endl;
        Customer* res = cList.search(first, last);
        if(res == 0)
            throw (string) "Customer with given name was not found";
        if(res->getBikeRented() == 0)
            throw (string) "Customer has no motorbike rented right now";

        Motorbike* bike;
        for(int i=0; i<NUM_MB; i++)
        {
            if(mb[i]->getName() == res->getBikeRented()->getName())
            {
                bike = mb[i];
                break;
            }
        }

        // Passed all the tests before
        res->setBikeRented(0);
        bike->setIsAvailable(true);

        cout << "A motorbike was returned. The record will be removed:" << endl;
        cout << "[1] ";
        cout << *res;

        cList.remove(res);
    }
    catch(string e)
    {
        cout << "Transaction was terminated:" << endl;
        cout << e << endl;
    }
}

void displayMotorbikes()
{
    for(int i=0; i<NUM_MB; i++)
    {
        cout << "[" << i+1 << "] ";
        cout << *mb[i];
    }
}


void displayList()
{
    cList.display();
}

void removeList()
{
    int answer = -1;
    cout << "--- Remove all records ---" << endl;
    cout << "[1] YES" << endl;
    cout << "[2] NO" << endl;
    cout << "[0] Exit" << endl;
    cout << ">Enter: ";
    cin >> answer;
    cout << endl;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Transaction was canceled" << endl;
        return;
    }
    switch(answer)
    {
        case 1: //[1] YES
        {
            cList.clear();
            cout <<"The entire list of reservations was deleted" << endl;
            break;
        }
        case 2: //[2] NO
        case 0: //[0] Exit
        default: // Any other input
        {
            cout << "Transaction was canceled" << endl;
            break;
        }
    }
}

// https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
void readFromFile()
{
    ifstream reader;
    try
    {

        reader.open(FILE_NAME, ios::in);
        if(!reader.good())
            throw (string) "File " + FILE_NAME + " cannot be read";
        if(reader.peek() == ifstream::traits_type::eof())
            throw (string) "File " + FILE_NAME + " does not have records";

        string line;
        vector<string> vect;
        while(!reader.eof())
        {
            getline(reader,line);
            stringstream ss(line);

            for (string i; ss >> i;) {
                vect.push_back(i);
                if (ss.peek() == ',')
                    ss.ignore();
            }

            insertOneRecord(vect);
        }

        cout << vect[0] << endl;



        cout << "Reading from file " << FILE_NAME << " was successful"<< endl;
    }
    catch (string e)
    {
        cout << e << endl;
    }
    reader.close();
}

void insertOneRecord(vector<string> vect)
{
    string firstName = vect[0];
    string lastName = vect[1];
    string street = vect[2];
    long postalCode = atol(vect[3].c_str()); ;
    string city = vect[4];
    unsigned int yearOfBirth = vect[5];
    long phoneNumber = vect[6];
    string lic = vect[7];
    string bike = vect[8];

    bool licenceA = (lic == "no") ? 0 : 1;
        Customer* successor = 0;

        Motorbike* bikeRented;
        for(int i=0; i<NUM_MB; i++)
        {
            if(mb[i]->getName() == bike)
            {
                bikeRented = mb[i];
                break;
            }

        }

        Customer* c = new Customer(
                            firstName,
                            lastName,
                            street,
                            postalCode,
                            city,
                            yearOfBirth,
                            phoneNumber,
                            licenceA,
                            bikeRented,
                            successor );
        cList.add(c);
}

void saveToFile()
{
    ofstream writer;
    string lic, bike;

    try
    {
        writer.open(FILE_NAME,ios::out);
        if(!writer.good())
            throw (string) "File " + FILE_NAME + " is write-protected";

        //writer << "firstName,lastName,street,postalCode,city,yearOfBirth,phoneNumber,licenceA,bike"<< endl;

        Customer *it;
        for (it = cList.getHead(); it != NULL; it = it->next())
        {
            lic = (it->getLicenceA() == 0) ? "no" : "yes";
            bike = (it->getBikeRented() == 0) ? "any" : it->getBikeRented()->getName();

            writer <<   it->getFirstName()   << CSV_DEL <<
                        it->getLastName()    << CSV_DEL <<
                        it->getStreet()      << CSV_DEL <<
                        it->getPostalCode()  << CSV_DEL<<
                        it->getCity()        << CSV_DEL <<
                        it->getYearOfBirth() << CSV_DEL <<
                        it->getPhoneNumber() << CSV_DEL <<
                        lic                  << CSV_DEL <<
                        bike                 << endl;
        }
        cout << "Writing to file " << FILE_NAME << " was successful"<< endl;
    }
    catch (string e)
    {
        cout << e << endl;
    }
    writer.close();
}

unsigned int getCurrentYear()
{
    // Source: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    time_t t = time(0);
    tm* now = localtime(&t);
    unsigned int actYear = now->tm_year + 1900;
    //short actMonth = now->tm_mon + 1;
    //short actDay = now->tm_mday;

    return actYear;
}
