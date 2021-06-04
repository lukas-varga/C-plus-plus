// Importing necessary libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <limits>
#include <sstream>
#include <vector>

// We can omit std:: prefix for IO and other methods
using namespace std;

//-------------------- CLASSES --------------------

//--- MOTORBIKE ---

// The class which represents motorbike objects
class Motorbike
{
private:
    // Name of the bike
    string name;
    // Information about current availability
    bool isAvailable;
public:
    Motorbike() {}
    Motorbike(string name, bool isAvailable): name(name), isAvailable(isAvailable) {}

    //Getter and setters
    string getName() { return name; }
    void setName(string name) { name = name; }
    bool getIsAvailable() { return isAvailable; }
    void setIsAvailable(bool aval) { isAvailable = aval; }

    // Overloaded output operator for printing details about the motorbike
    friend ostream& operator<<(ostream& os, Motorbike& m);
};

// Overloaded method for printing details about the motorbike
ostream& operator<<(ostream& os, Motorbike& m)
{
    // Pushing string to ostream
    os << "Motorbike: " << m.name << "\t";
    // Boolean value about availability is transformed to string value - yes/no
    string ans = (m.isAvailable) ? "yes" : "no";
    os << "Available: " << ans << "\t" << endl;
    // Returning ostream
    return os;
}

// Auxiliary for getting current year
unsigned int getCurrentYear();

//--- CUSTOMER ---

// Class for storing general data about all employees within types
class Customer
{
// Easier access for creating ListCustomers class
friend class ListCustomers;
private:
    string firstName;
    string lastName;
    string street;
    long postalCode;
    string city;
    unsigned int yearOfBirth;
    long phoneNumber;
    // Boolean value whether or not the customer have A driving licence
    bool licenceA;

    // Pointer to bike rented. If person did not rent bike yet it is equal to NULL
    Motorbike *bikeRented;
    // Pointer to another customer for creating linked list with class ListCustomers
    Customer *successor;
public:
    // Default value for next linked list element is NULL
    Customer() { successor = 0; }
    // Extended constructor
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

    // Getters for data attributes
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getStreet() { return street; }
    long getPostalCode() { return postalCode; }
    string getCity() { return city; }
    unsigned int getYearOfBirth() { return yearOfBirth; }
    long getPhoneNumber() { return phoneNumber; }
    bool getLicenceA() { return licenceA; }

    // Getters and setters for pointer attributes
    Motorbike* getBikeRented() { return bikeRented; }
    void setBikeRented(Motorbike* bikeRented) { this->bikeRented = bikeRented; }
    Customer* next() { return successor; }

    // Overloaded input operator
    friend istream& operator>>(istream& is, Customer& c);
    // Overloaded output operator
    friend ostream& operator<<(ostream& os, Customer& c);
};

// Extended constructor
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
    // Assigning values using *this notation
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

// Overloaded input operator
istream& operator>>(istream& is, Customer& c)
{
    // Infinite loop till user enter valid info about the customer
    while(true)
    {
        // Try catch block for handling wrong inputs
        try
        {
            system("cls");
            // Adding first and last name (will be check for duplicates later)
            cout << "--- Add the customer ---" << endl;
            cout << "First name: ";
            is >> c.firstName;
            cout <<  "Last name: ";
            is >> c.lastName;

            //Info about address
            cout << "--- Address ---" << endl;
            cout << "Street: ";
            is >> c.street;
            cout << "Postal code: ";
            is >> c.postalCode;
            // If entered PS does not parse to number the customer is informed and exception is thrown
            if(!is)
                throw (string) "Wrong postal code";
            cout << "City: ";
            is >> c.city,

            // Another details about customer
            cout << "--- Additional Info ---" << endl;
            cout << "Year of birth: ";
            is >> c.yearOfBirth;
            // Checking if year a number and if it is valid 1900 - now
            if(!is || c.yearOfBirth < 1900 || c.yearOfBirth > getCurrentYear())
                throw (string) "Wrong year of birth \n" + "Please provide a year between " + to_string(1900) + " and " + to_string(getCurrentYear());
            cout << "Phone number: ";
            // Checking phone number
            is >> c.phoneNumber;
            if(!is)
                throw (string) "Wrong phone number";

            string answer;
            cout << "A driving licence (y/n): ";
            is >> answer;

            // User input y/n is transformed to boolean value otherwise exception is thrown
            if(answer == "y")
                c.licenceA = true;
            else if(answer == "n")
                c.licenceA = false;
            else
                throw (string) "Wrong A driving licence input";

            // User has not rented motorbike by default
            c.bikeRented = 0;

            // If every entered data is in correct format the input is return
            break;
        }
        catch (string e)
        {
            // Reset failbit
            is.clear();
            // Skip wrong input
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            // Print thrown error
            cout << endl << e << endl;
            system("pause");
        }
    }

    //return istream instance
    return is;
}

// Overloaded output operator
ostream& operator<<(ostream& os, Customer& c)
{
    // Delimiter is chosen so all data will fit to even smaller screen
    const string DELIMITER = " | ";
    string answer;

    // Printing first and last name
    os <<  "First name: ";
    os << c.firstName << DELIMITER;
    os <<  "Last name: ";
    os << c.lastName << DELIMITER;

    // Printing address info
    os << "Street: ";
    os << c.street << DELIMITER;
    os << "PS: ";
    os << c.postalCode << DELIMITER;
    os << "City: ";
    os << c.city << DELIMITER;

    // Printing additional info
    os << "Year: ";
    os << c.yearOfBirth << DELIMITER;
    os << "Phone: ";
    os << c.phoneNumber << DELIMITER;
    os << "A licence: ";
    // A driving licence boolean value is replaced by (0/1)
    answer = (c.licenceA) ? "yes" : "no";
    os << answer << DELIMITER;

    os << "Rented: ";
    // Printing a rented motorbike name otherwise word "any" for user who does not have a motorbike rented yett
    answer = (c.bikeRented != 0) ? c.bikeRented->getName() : "any";
    os << answer << endl;

    // Returning ostream instance
    return os;
}

// Auxiliary for getting current year
// Source: https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
unsigned int getCurrentYear()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    unsigned int actYear = now->tm_year + 1900;
    //short actMonth = now->tm_mon + 1;
    //short actDay = now->tm_mday;

    // Returning value of current year
    return actYear;
}

//--- LIST OF CUSTOMERS ---

// Class for storing customer records in linked list
class ListCustomers
{
private:
    // Head of linked list
    Customer* head;
public:
    // At beginning the head is set to NULL
    ListCustomers() { head = 0; }
    // When the list use destructor the head is released from memory
    ~ListCustomers() { delete head; }

    // Getters for head
    Customer* getHead() { return head; }
    bool isEmpty(){ return head == 0; }

    // Add new customer to linked list
    void add(Customer*);
    // Find and return customer by first and last name
    Customer* search(string,string);
    // Removing a customer from linked list
    void remove(Customer*);
    // Displaying the whole linked list
    void display();
    // Clearing the list from memory
    void clear();
};

// Add new customer to linked list
void ListCustomers::add(Customer *it)
{
    // If linked list is empty the head is set to given customer
    if (isEmpty())
    {
        head = it;
    }
    // Otherwise the given customer is pushed to linked list (LIFO) and become the head
    else
    {
        it->successor = head;
        head = it;
    }
}

// Find and return customer by first and last name
Customer* ListCustomers::search(string first, string last)
{
    // If list is empty no customer can be found by definition so program return NULL pointer
    if(isEmpty())
    {
        return 0;
    }

    // Iterating linked list till the pointer is NULL by accessing successors
    for (Customer* it = head; it != NULL; it = it->successor)
    {
        // If current element has the same first and last name as given return pointer to it
        if((it->firstName == first) && (it->lastName == last))
        {
            return it;
        }
    }

    // If no customer was found return NULL pointer
    return 0;
}

// Removing a customer from linked list
void ListCustomers::remove(Customer* selected)
{
    // If the head will be removed proceed here
    if(head == selected)
    {
        // New head is set to successor of current head
        Customer *newHead = selected->successor;
        // Pointer to successor of current head is set to NULL
        selected->successor = 0;
        // New head is set
        head = newHead;

        // Releasing data of old head
        delete selected;
        // Returning from function
        return;
    }

    // Otherwise if some other node will be removed
    // Pointer points to head
    Customer *it = head;
    Customer *previous;
    // Till pointer is not NULL
    while (it != 0)
    {
        // Storing predecessor
        previous = it;
        // Accessing successor
        it = it->successor;

        // If pointer is equal to the element we want to remove
        if(it == selected)
        {
            // Rewire pointer previous and successor
            previous->successor = selected->successor;
            // Set value removed pointer to NULL
            selected->successor = 0;

            // Releasing data of removed customer from memory
            delete selected;
            // We can return from function
            break;
        }
    }
}

// Displaying the whole linked list
void ListCustomers::display()
{
    int i=0;
    // Iterate the whole list
    for (Customer* it = head; it != NULL; it = it->successor)
    {
        // Printing index and all data of customer using overloaded operator <<
        cout << "[" << ++i <<"] ";
        cout << *it;
    }
}

// Clearing the list from memory
void ListCustomers::clear()
{
    // Setting head to pointer and the iterate the whole list until it is empty
    Customer *it = head;
    while(!isEmpty())
    {
        // Removing actual head and setting new one
        it = head->successor;
        delete head;
        head = it;
    }
}

//-------------------- METHODS AND FUCTIONS --------------------

//--- CONSTANTS AND REFFERENCES ---

// Number of available motorbikes
const int NUM_MB = 4;
// Array with motorbikes name
const string ARR_MB[NUM_MB] = {"Suzuki Bandit", "Honda TransAlp", "BMW F 650 GS", "Kawasaki ZZR1400"};
// Array of pointers holding bikes
Motorbike* mb[NUM_MB];
// Linked list to store customers
ListCustomers cList;

// Relative address of text file (CSV format used)
const string FILE_NAME = "reservations.txt";
// Delimiter for R/W is comma
const string CSV_DEL = ",";

//--- METHODS ---

// Initializing motorbikes array and customer list
void initialize();
// Adding customer to the system
void addCustomer();
// Making reservation (Motorbike is rented by customer)
void makeReservation();
// Returning the bike from customer and removing customer from list
void returnBike();
// Displaying motorbikes with info about availability
void displayMotorbikes();
// Displaying all info about customer even with rented bikes
void displayList();
// Removing whole list of reservations including all customers (Motorbikes are available again)
void removeList();

// Reading data about customers and reservations from CSV file
void readFromFile();
// Putting retrieved record into customer object and storing into list
void insertRecord(vector<string> vect);
// Saving current list of reservations to file on hard drive
void saveToFile();

// Main method of the program
int main()
{
    // Creating empty list of customer and  filled array of bikes (dynamically)
    initialize();

    // Reading data from file
    cout << "--- MOTORBIKE RENTAL ---" << endl;
    readFromFile();
    system("pause");

    // Infinite loop until user enter 0
    int selection = -1;
    bool keepGoing = true;
    do
    {
        system("cls");

        // Showing the main menu of program
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

        // Checking whether the input by user is number
        // https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
        if(!cin) // Or if(cin.fail())
        {
            // User didn't input a number
            // Reset failbit
            cin.clear();
            // Skip bad input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Next, request user reinput

            cout << "Wrong input!" << endl;
            system("pause");
            // Skip following and display menu again
            continue;
        }

        // Retreiving input from user
        switch (selection)
        {
            case 0: // [0] Exit program
                // Program exit the infinite while loop
                keepGoing = false;
                break;
            case 1: // [1] Add the customer
            {
                system("cls");
                // Adding new customer
                addCustomer();
                // Saving changes to file. If action was canceled the file will be overwritten with last valid data
                saveToFile();
                system("pause");
                break;
            }

            case 2: // [2] Make a reservation
            {
                system("cls");
                // Making reservation
                makeReservation();
                // Saving changes to file. If action was canceled the file will be overwritten with last valid data
                saveToFile();
                system("pause");
                break;
            }
            case 3: // [3] Return the motorbike (remove the record)
            {
                system("cls");
                // Returning bike from customer
                returnBike();
                // Saving changes to file. If action was canceled the file will be overwritten with last valid data
                saveToFile();
                system("pause");
                break;
            }
            case 4: // {4] Show motorbikes
            {
                system("cls");
                // Displaying all motorbikes
                cout << "--- Show motorbikes ---" << endl;
                displayMotorbikes();
                cout << endl;
                system("pause");
                break;
            }
            case 5: // [5] Display customers' data
            {
                system("cls");
                // Displaying all customers' data
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
                // Saving empty list to file
                saveToFile();
                system("pause");
                break;
            }
            default: // Incorrect input
                break;
        }
    // Menu reappear until the boolean value of keepGoing is true
    } while (keepGoing);

    // Saving all made changes to file at the end of the program
    saveToFile();
    // Delete all elements of the linked list and releasing used memory
    cList.clear();

    system("pause");
    // Exiting program
    return 0;
}

// Initializing motorbikes array and customer list
void initialize()
{
    // Create an empty instance of linked list
    cList = ListCustomers();
    // Filling the array of motorbikes
    for(int i=0; i<NUM_MB; i++)
    {
        // All the motorbikes are available at the beginning
        mb[i] = new Motorbike(ARR_MB[i],true);
    }
}

// Making reservation (Motorbike is rented by customer)
void addCustomer()
{
    Customer* c = new Customer();
    // Input data for customer using overloaded operator >>
    cin >> *c;
    // If user with the same name is already in the linked list throw and error
    if(cList.search(c->getFirstName(),c->getLastName()))
        cout << endl << "Transaction terminated: This person already exists in system" << endl;
    //Otherwise add customer to the linked list nad inform user about success
    else
    {
        cList.add(c);
        cout << endl << "Customer was successfully registered to the system" << endl;
    }
}

// Returning the bike from customer and removing customer from list
void makeReservation()
{
    string first, last;
    try
    {
        // Displaying all users with rented motorbikes
        cout << "--- Make a reservation ---" << endl;
        cList.display();
        cout << endl;

        // Input first and last name
        cout << "--- Enter the name ---" << endl;
        cout << ">First name: ";
        cin >> first;
        cout << ">Last name: ";
        cin >> last;

        // Checking whether the reservation is valid
        system("cls");
        cout << "--- Make a reservation ---" << endl;
        Customer* res = cList.search(first, last);
        if(res == 0)
            throw (string) "Customer with given name was not found";
        if(!res->getLicenceA())
            throw (string) "Customer does not have an A driving licence";
        if(res->getBikeRented() != 0)
            throw (string) "Customer already has a motorbike rented";

        // Displaying all motorbikes
        system("cls");
        cout << "--- Choose a motorbike ---" << endl;
        displayMotorbikes();
        cout << ">Enter [i]: ";

        // Choosing a motorbike
        int sel = -1;
        cin >> sel;
        system("cls");
        cout << "--- Make a reservation ---" << endl;
        // Wrong user input or entering non existing index (exception thrown)
        if(!cin || sel < 1 || sel > NUM_MB)
        {
            // Clearing fail bit
            cin.clear();
            // Ignore remaining input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw (string) "Wrong input";
        }

        // Point to selected motorbike
        Motorbike* bike = mb[sel-1];
        // Check whether the bike is available
        if(!bike->getIsAvailable())
            throw (string) "Given bike is not available right now";

        // Passed all the tests before
        // Setting up motorbikes pointers and info about availibility
        res->setBikeRented(bike);
        bike->setIsAvailable(false);

        // Inform user about new records made using overloaded operator<<
        cout << "A motorbike was rented. See details:" << endl;
        cout << "[1] ";
        cout << *res;
    }
    catch(string e)
    {
        // Catching and displaying error message to user
        cout << "Transaction terminated: ";
        cout << e << endl;
    }
}

// Returning the bike from customer and removing customer from list
void returnBike()
{
    string first, last;
    try
    {
        // Displaying list of customer with reservation info (bike/any)
        cout << "--- Return the motorbike (remove the record) ---" << endl;
        cList.display();
        cout << endl;

        // Entering first and last name
        cout << "--- Enter the name ---" << endl;
        cout << ">First name: ";
        cin >> first;
        cout << ">Last name: ";
        cin >> last;

        // Checking the input
        system("cls");
        cout << "--- Return the motorbike (remove the record) ---" << endl;
        // Pointer to found user
        Customer* res = cList.search(first, last);
        if(res == 0)
            throw (string) "Customer with given name was not found";
        if(res->getBikeRented() == 0)
            throw (string) "Customer has no motorbike rented right now";

        // Passed all the tests before
        // Find a pointer to motorbike by searching for bike name
        Motorbike* bike;
        for(int i=0; i<NUM_MB; i++)
        {
            // If name of rented bike is equal to some bike from array
            if(mb[i]->getName() == res->getBikeRented()->getName())
            {
                bike = mb[i];
                break;
            }
        }

        // Customer's returned bike (no data in his rentBike pointer)
        res->setBikeRented(0);
        // Bike can be rented again for others
        bike->setIsAvailable(true);

        // User is informed about success with details about removed customer
        cout << "A motorbike was returned. The record will be removed:" << endl;
        cout << "[1] ";
        cout << *res;

        // Removing customer from list
        cList.remove(res);
    }
    catch(string e)
    {
        // Printing errors
        cout << "Transaction terminated: ";
        cout << e << endl;
    }
}

// Displaying motorbikes with info about availability
void displayMotorbikes()
{
    // Iterating the whole array and displaying bikes by overloaded operator <<
    for(int i=0; i<NUM_MB; i++)
    {
        cout << "[" << i+1 << "] ";
        cout << *mb[i];
    }
}

// Displaying all info about customer even with rented bikes
void displayList()
{
    // Calling display method of customer list
    cList.display();
}

// Removing whole list of reservations including all customers (Motorbikes are available again)
void removeList()
{
    // Double checking before clearing all reservations
    int answer = -1;
    cout << "--- Remove all records ---" << endl;
    cout << "[1] YES" << endl;
    cout << "[2] NO" << endl;
    cout << "[0] Exit" << endl;
    cout << ">Enter: ";
    cin >> answer;
    cout << endl;

    // Handling incorrect input (not number)
    if(cin.fail())
    {
        // Clearing fail bit
        cin.clear();
        // Clearing rest of the input and return from method
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Transaction was canceled" << endl;
        return;
    }
    switch(answer)
    {
        case 1: //[1] YES
        {
            // Clearing the list
            cList.clear();
            // Initializing new clear one
            initialize();
            cout <<"The entire list of reservations was deleted" << endl;
            break;
        }
        case 2: //[2] NO
        case 0: //[0] Exit
        default: // Any other input
        {
            // Canceling transaction back to main menu
            cout << "Transaction was canceled" << endl;
            break;
        }
    }
}

// Reading data about customers and reservations from CSV file
// Source: https://www.tutorialspoint.com/parsing-a-comma-delimited-std-string-in-cplusplus
void readFromFile()
{
    // Instance of input file stream
    ifstream reader;

    try
    {
        // Open file in reading mode
        reader.open(FILE_NAME, ios::in);
        // Checking if file exist
        if(!reader.good())
            throw (string) "No data found! File '" + FILE_NAME + "' will be created";
        // Checking if file is empty
        if(reader.peek() == ifstream::traits_type::eof())
            throw (string) "File '" + FILE_NAME + "' does not have any records";

        // Passed all tests before

        string line;
        int counter = 0;
        // Read all lines till nothing's left
        while(!reader.eof())
        {
            // Read one line
            getline(reader,line);
            // Creating buffer vector
            vector<string> result;
            // String stream from line
            stringstream s_stream(line);
            // Get substrings till there are some
            while(s_stream.good()) {
                string substr;
                // Use comma as delimiter
                getline(s_stream, substr, ',');
                // Push each cell to vector
                result.push_back(substr);
            }

            // Double checking if vector is not empty
            if(result.at(0)=="")
                continue;

            // Inserting one line to list of customers (access by vector of strings)
            insertRecord(result);
            // Incrementing counter of added records
            counter++;
        }
        // Inform user about successful reading with number of records found
        cout << "Reading from file '" << FILE_NAME << "' was successful (" << counter << " records found)"<< endl;
    }
    catch (string e)
    {
        // Printing infos/errors
        cout << e << endl;
    }
    // Closing reader after using
    reader.close();
}

// Putting retrieved record into customer object and storing into list
void insertRecord(vector<string> result)
{
    try
    {
        // Convert data from strings to valid data types
        string firstName = result.at(0);
        string lastName = result.at(1);
        string street = result.at(2);
        // Using conversion for numbers
        long postalCode = atoll(result.at(3).c_str()); ;
        string city = result.at(4);
        // Using conversion for numbers
        unsigned int yearOfBirth = atoll(result.at(5).c_str());
        // Using conversion for numbers
        long phoneNumber = atoll(result.at(6).c_str());
        string lic = result.at(7);
        string bike = result.at(8);

        // Setting successor to NULL by default (will be wired correctly)
        Customer* successor = 0;
        // Custom conversion for boolean
        bool licenceA = (lic == "no") ? 0 : 1;

        // Custom conversion from bike name to bike refference
        Motorbike* bikeRented = 0;
        for(int i=0; i<NUM_MB; i++)
        {
            // If given name is found in bike array
            if(mb[i]->getName() == bike)
            {
                // Assign reference to pointer
                bikeRented = mb[i];
                // Updated info about bike availability
                bikeRented->setIsAvailable(false);
                break;
            }
        }

        // Creating dynamic instance from retrieved data using extended constructor
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
        // Adding customer to list
        cList.add(c);
    }
    catch (...)
    {
        // Any additional error that can happen while parsing and clearing the list so program will at least run without daata
        cList.clear();
        cout << "Unexpected error while reading from file '" << FILE_NAME << "'"<< endl;
    }
}

// Saving current list of reservations to file on hard drive
void saveToFile()
{
    // Instance of output file stream
    ofstream writer;
    string lic, bike;

    try
    {
        // Opening file with overwritten mode
        writer.open(FILE_NAME,ios::out);
        // Checking if file is accessible
        if(!writer.good())
            throw (string) "File " + FILE_NAME + " is write-protected";

        // Iterating the whole list in order to write it to file one line per record with comma as value separator
        for (Customer* it = cList.getHead(); it != NULL; it = it->next())
        {
            // Handling data conversion for boolean (yes/no)
            lic = (it->getLicenceA() == 0) ? "no" : "yes";
            // Handling data conversion for Motorbike instance
            // Name of rented bike is saved otherwise word 'any' is used
            bike = (it->getBikeRented() == 0) ? "any" : it->getBikeRented()->getName();

            // Writing a record to file with comma as separator
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

        // Informing user that writing was successful and file is safely saved
        cout << "File '" << FILE_NAME << "' saved"<< endl;
    }
    catch (string e)
    {
        // Handling infos/errors
        cout << e << endl;
    }
    // Closing writer after saving file
    writer.close();
}


