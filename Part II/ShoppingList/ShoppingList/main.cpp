#include <iostream>
#include <cstdlib>
#include <fstream>
#include <strstream>

using namespace std;

class Item
{
friend class ListItems;
private:
    string description;
    float price;
    int quantity;
    Item *successor;
public:
    Item(string des = "", int pr = 0, float q = 0): description(des), price(pr), quantity(q), successor(0){}

    ~Item()
    {
        delete successor;
    }

    string getDescription()
    {
        return description;
    }

    void setDescription(string description)
    {
        this->description = description;
    }

    float getPrice()
    {
        return price;
    }

    void setPrice(float price)
    {
        this->price = price;
    }

    int getQuantity()
    {
        return quantity;
    }

    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }

    void increaseQuantity()
    {
        ++quantity;
    }

    float getTotalPrice()
    {
        return price * quantity;
    }

    Item* next()
    {
        return successor;
    }

    void print()
    {
        cout << "Description: " << description << "\t Price: " << price << "\t Quantity: " << quantity << "\t Total Price: " << getTotalPrice() << endl;
    }
};

class ListItems
{
private:
    Item* head;
public:
    ListItems()
    {
        head = 0;
    }

    ~ListItems()
    {
        delete head;
    }

    void add(Item *it)
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

    Item* search(string des)
    {
        if(isEmpty())
        {
            return 0;
        }

        Item *it;
        for (it = head; it != NULL; it = it->successor)
        {
            if(it->getDescription() == des)
            {
                return it;
            }
        }

        return 0;
    }

    Item* elementAt(int index)
    {
        if(isEmpty() || index <= 0 || index > numberOfItems())
        {
            return 0;
        }

        Item *it = head;
        int i = 1;
        while (i < index)
        {
            it = it->successor;
            i++;
        }
        return it;
    }

    void remove(Item* selected)
    {
        if(head == selected)
        {
            Item *newHead = selected->successor;
            selected->successor = 0;
            head = newHead;

            cout << "Following item was removed:" << endl;
            selected->print();

            delete selected;
            return;
        }

        Item *it = head;
        Item *previous;
        while (it != 0)
        {
            previous = it;
            it = it->successor;

            if(it == selected)
            {
                previous->successor = selected->successor;
                selected->successor = 0;

                cout << "Following item was removed:" << endl;
                selected->print();

                delete selected;
                break;
            }
        }
    }

    void displayAll()
    {
        Item *it;
        int i=0;
        for (it = head; it != NULL; it = it->successor)
        {
            cout << "[" << ++i <<"] ";
            it->print();
        }
    }

    void clearAll()
    {
        Item *it;
        while(!isEmpty())
        {
            it = head->successor;
            delete head;
            head = it;
        }
    }

    Item* getHead()
    {
        return head;
    }

    bool isEmpty()
    {
        return head == 0;
    }

    int numberOfItems()
    {
        if(isEmpty())
        {
            return 0;
        }

        int i = 0;
        for (Item *it = head; it != NULL; it = it->successor)
        {
            i++;
        }
        return i;
    }

    float priceOfAll()
    {
        float sum = 0;
        for (Item *it = head; it != NULL; it = it->successor)
        {
            sum += it->getTotalPrice();
        }
        return sum;
    }

};

ListItems list;

void addItem();
void modifyItem();
void changeProperty(Item*);
void deleteItem();
void displayList();
void removeList();


const string FILE_NAME = "data.txt";

void readFromFile();
void saveToFile();

int main()
{
    readFromFile();
    system("pause");
    int selection = -1;
    do
    {
        system("cls");

        cout << "---- SHOPPING LIST ----" << endl;
        cout << "[1] Add item" << endl;
        cout << "[2] Modify item" << endl;
        cout << "[3] Delete item" << endl;
        cout << "[4] Display shopping list" << endl;
        cout << "[5] Remove shopping list" << endl;
        cout << "[0] Exit program" << endl;
        cout << ">Enter: ";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
            case 0: // End
                break;
            case 1: // Add item
            {
                system("cls");
                addItem();
                system("pause");
                break;
            }

            case 2: // Modify item
            {
                system("cls");
                modifyItem();
                system("pause");
                break;
            }
            case 3: // Delete item
            {
                system("cls");
                deleteItem();
                system("pause");
                break;
            }
            case 4: // Display shopping list
            {
                system("cls");
                displayList();
                system("pause");
                break;
            }
            case 5: // Remove shopping list
            {
                system("cls");
                removeList();
                system("pause");
                break;
            }
            default: // Incorrect input
                break;
        }
    } while (selection != 0);

    //Delete all elements of the list
    saveToFile();
    list.clearAll();

    system("pause");
    return 0;
}

void addItem()
{
    string description;
    float price;
    int quantity;

    try
    {
        cout << "Please fill following data" << endl;
        cout << "Description: ";
        cin >> description;

        cout << "Price: ";
        cin >> price;
        if(price <= 0)
            throw (string) "Price is negative or null";

        cout << "Quantity: ";
        cin >> quantity;
        if(quantity <= 0)
            throw (string) "Quantity is negative or null";

        //data passed
        Item *found = list.search(description);
        if(found != 0)
            found->increaseQuantity();
        else
            list.add(new Item(description, price, quantity));
    }
    catch(string e)
    {
        cout << e << endl;
        cout << "Transaction is cancelled" << endl;
    }
}

void modifyItem()
{
    int selected = -1;
    cout << "Which item do you want to modify" << endl;
    list.displayAll();
    cout << ">Enter: ";
    cin >> selected;

    Item *it;
    try
    {
        if (selected <= 0)
            throw (string) "Selected number cannot be negative or zero";
        else if (selected > list.numberOfItems())
            throw (string) "Selected number exceed the number of items in list";
        it = list.elementAt(selected);
        it->print();
        changeProperty(it);
    }
    catch (string e)
    {
        cout << e << endl;
        cout << "Transaction is cancelled" << endl;
    }
}

void changeProperty(Item *it)
{
    int selected = -1;
    cout << "What property to be changed" << endl;
    cout << "[1] Description" << endl;
    cout << "[2] Price" << endl;
    cout << "[3] Quantity" << endl;
    cout << ">Enter: ";
    cin >> selected;

    string description;
    float price;
    int quantity;
    try
    {
        system("cls");
        cout << "Please fill following data" << endl;

        switch(selected)
        {
            case 1:
            {
                cout << "Description: ";
                cin >> description;
                it->setDescription(description);
                cout << "Description changed to: " << it->getDescription() << endl;
                break;
            }
            case 2:
            {
                cout << "Price: ";
                cin >> price;
                if(price <= 0)
                    throw (string) "Price is negative or null";
                it->setPrice(price);
                cout << "Price changed to: " << it->getPrice() << endl;
                break;
            }
            case 3:
            {
                cout << "Quantity: ";
                cin >> quantity;
                if(quantity <= 0)
                    throw (string) "Quantity is negative or null";
                it->setQuantity(quantity);
                cout << "Quantity changed to: " << it->getQuantity() << endl;
                break;;
            }
            default:
                throw (string) "Wrong input";
        }
    }
    catch(string e)
    {
        cout << e << endl;
        cout << "Transaction is cancelled" << endl;
    }
}

void deleteItem()
{
    int selected = -1;
    cout << "Which item do you want to remove" << endl;
    list.displayAll();
    cout << ">Enter: ";
    cin >> selected;

    Item *it;
    try
    {
        if (selected <= 0)
            throw (string) "Selected number cannot be negative or zero";
        else if (selected > list.numberOfItems())
            throw (string) "Selected number exceed the number of items in list";
        it = list.elementAt(selected);
        list.remove(it);
    }
    catch (string e)
    {
        cout << e << endl;
        cout << "Transaction is cancelled" << endl;
    }
}

void displayList()
{
    cout << "Shopping list" << endl;
    list.displayAll();
    if(list.numberOfItems() > 1)
    {
        float sum = list.priceOfAll();
        cout << "Total sum of all items: " << sum << endl;
    }
}

void removeList()
{
    list.clearAll();
    cout << "The entire shopping list was deleted" << endl;
}

void readFromFile()
{
    ifstream reader;
    reader.open(FILE_NAME, ios::in);

    string description;
    float price;
    int quantity;

    if(!reader.good())
    {
        reader.close();
        cout << "File "<<FILE_NAME<<" cannot be read!"<< endl;
        return;
    }

    //reading in opposite direction

    while (reader >> description >> price >> quantity)
    {
        list.add(new Item(description, price, quantity));
    }

    reader.close();
    cout << "Reading from file " << FILE_NAME << " was successful!"<< endl;
}

void saveToFile()
{
    ofstream writer;
    writer.open(FILE_NAME,ios::out);
    if(!writer.good())
    {
        writer.close();
        cout << "File " << FILE_NAME << " is write-protected!"<< endl;
        return;
    }

    Item *it;
    for (it = list.getHead(); it != NULL; it = it->next())
    {
        writer  << it->getDescription() << " "
                << it->getPrice() << " "
                << it->getQuantity()
                << endl;
    }
    writer.close();
    cout << "Writing to " << FILE_NAME << " was successful!"<< endl;
}
