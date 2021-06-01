#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Item
{
// friend Declaration
friend class Shoppinglist;

private:
	string name;
	float price;
	int quantity;
	Item *successor;
public:
	Item(string n, float p, int q) : name(n), price(p), quantity(q)
	{
		successor = 0;
	}
	string get_name () { return name; }
	float get_price () { return price; }
	int get_quantity () { return quantity; }
	int set_quantity () { quantity = quantity + 1; }
	void set_name (string n) { name = n; }
	void set_price (float p) { price = p; }
	void set_quantity (int q) { quantity = q; }
	void displayData()
	{
		cout << get_name() << "\t" << get_price() << "\t" << get_quantity();
	};
	Item *next () { return successor; }
};

class Shoppinglist
{
private:
	Item *beginning;
public:
	Shoppinglist ()
	{
		beginning = 0;
	}
	Item *begin () { return beginning; }

	insert(Item *k)
	{
		k->successor = beginning;
		beginning = k;
	}
	Item* find(string dataset)
	{
		Item *kp;
		for (kp = begin(); kp != 0; kp = kp->next())
			if (kp->get_name() == dataset)
				break;
		return kp;
	}
	void remove(string dataset)
	{
		if(beginning!=NULL)
		{
			if(beginning->get_name() == dataset) //check if the beginning is our dataset, as we may not have a successor

			{
				beginning = beginning->next(); //falls ja, dann ist unser neuer Anfang der Nachfolger
			}
			else if(beginning->get_name() != dataset && beginning->next() == NULL) //check if start is not equal to dataset and if next dataset is NULL
			{
				return;
			}
			else
			{
				Item *kp;
				for (kp = begin(); kp != 0; kp = kp->next())
				{
					if(kp->next()->get_name() != dataset && kp->next()->next() == NULL) //check if the successor dataset is not equal to my dataset and if the successor of the successor is equal to NUL
						break;														  //is needed if we are at the second to last dataset & last data is not equal, because last does not provide any data
					else if (kp->next()->get_name() == dataset) //check if successor is our dataset
					{
						kp->successor = kp->next()->next(); //If yes, then our new successor is the successor of the successor of the current object.
						break;
					}
				}
			}
		}
	}

	bool empty() { return beginning == 0; }
	Item *clear()
	{
    // Remove a node from the beginning of the list
        Item * kp = beginning;
        if (kp != 0)
        {
        	cout << kp->get_name() << " deleted." << endl;
            beginning = kp->successor;
            kp->successor = 0;
        }
        return kp;
	}
};

Shoppinglist list;

void list_initialize(); // Fills the list with the values from the file
void add(); // Add item
void modify(); // Modify item
void display(); // Displays all items and price
void remove(); // Delete item
void empty(); // Empty shopping list

int main()
{
	string insert;
	int selection = 1;
	Item *tmpObject = NULL;
	ofstream fileWriter;

	list_initialize();

	do
    {
    	system("cls");
        cout << "---- Shoppinglist ----" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Modify item" << endl;
        cout << "3. Delete item" << endl;
        cout << "4. Display shopping list" << endl;
        cout << "5. Empty shopping list." << endl;
        cout << "0. Exit program" << endl;
        cout << "Your selection: ";
        cin >> selection;
        cout << endl;

        try
        {
	        switch (selection)
	        {
	            case 0: // End
	            	fileWriter.open("shoppinglist.txt");
	            	if(fileWriter.good())
	            	{
						for (tmpObject=list.begin(); tmpObject != 0; tmpObject = tmpObject->next())
						{
							fileWriter << tmpObject->get_name() << "\t" << tmpObject->get_price() << "\t" << tmpObject->get_quantity() << endl;
						}
						if(list.begin()!=0)
							cout << "List saved to file shoppinglist.txt!" << endl;
					}
					else
						cout << "Datei shoppinglist.txt cannot be opened. Old list remains." << endl;

	            	cout << "Goodbye!" << endl;
	                break;
	            case 1: // Add item
	            	system("cls");
					add();
					system("pause");
	                break;
	            case 2: // Modify quantity of item
	            	if(list.begin()!=0)
	            	{
	            		system("cls");
	            		modify();
					}
					else
						cout << "List is empty." << endl;
	        		system("pause");
	                break;
	            case 3: // Delete selected item
                    if(list.begin()!=0)
	            	{
	            		system("cls");
	            		remove();
					}
					else
						cout << "List is empty." << endl;
					    system("pause");
					break;
				case 4: // Display item with price, quantity and total price
	            	if(list.begin()!=0)
	            	{
	            		display();
					}
					else
						cout << "List is empty." << endl;
					system("pause");
					break;
					case 5: // Empty shopping list
	            	if(list.begin()!=0)
	            	{
	            		system("cls");
	            		empty();
					}
					else
						cout << "List is empty." << endl;
					system("pause");
					break;
	            default: // Incorrect input
	            	cerr << "Incorrect input" << endl;
	            	system("pause");
	                break;
	        }
    	}
        catch(string msg)
		{
			cout << msg << " cannot be negative or null!" << endl << "Transaction canceled." << endl;
			system("pause");
		}
    } while (selection != 0);

	system("pause");
	return 0;
}

void list_initialize()
{
	string name;
	float price;
	int quantity;
	Item *it;

	ifstream fileReader("shoppinglist.txt", ios::out);

	if(fileReader.good())
    {
		while(fileReader >> name >> price >> quantity)
    	{
			it = new Item(name,price,quantity);
        	list.insert(it);
     	}
    }

    fileReader.close();
}

void add()
{
	string name;
	float price;
	int quantity;

	cout << "Name: ";
	cin >> name;

	Item *tmpItem = NULL;

	tmpItem = list.find(name);

	if (tmpItem == 0)
	{
		cout << "Price: ";
		cin >> price;
		if(price <=0)
			throw (string)"Price";
		cout << "Quantity: ";
		cin >> quantity;
		if(quantity <=0)
			throw (string)"Quantity";
		Item *object = new Item(name,price, quantity); //Create new object with newly assigned address
		list.insert(object);
		cout << "Item added." << endl;
	}
	else
	{
		cout << "Item " << name << " already exits. The quantity has been increased by one." << endl;
		tmpItem->set_quantity();
	}
}

void modify()
{
	string name;
	float price;
	int quantity, no = 1, selection;
	Item *object;

	cout << "Number\tName.\tPrice\tQantity" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		cout << "[" << no << "]\t";
		object-> displayData();
		cout << endl;
		no++;
	}

	cout << "Which item should be altered?" << endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= no);

	no = 1;
	for (object=list.begin(); object != 0; object = object->next())
	{
		if(selection==no)
			break;
		no++;
	}

	system("cls");

	cout << "Which item should be altered?" << endl << "[1] Name: " << object->get_name() << endl << "[2] Price: " << object->get_price() << endl << "[3] Quantity: " << object->get_quantity() << endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= 4);

	if(selection==1)
	{
		cout << "New name: ";
		cin >> name;
		object->set_name(name);
	}
	else if(selection ==2)
	{
		cout << "New price: ";
		cin >> price;
		if(price<=0)
			throw (string)"Price";
		object->set_price(price);
	}
	else if(selection ==3)
	{
		cout << "New quantity: ";
		cin >> quantity;
		if(quantity<=0)
			throw (string)"Quantity";
		object->set_quantity(quantity);
	}

	cout << "Item has been changed." << endl;
}

void display()
{
	float totalprice = 0;
	Item *object;
	int listentries = 0;
	cout << "Item.\tPrice\tQuantity\tTotal price" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		object->displayData();
		cout << "\t\t" << object->get_quantity()*object->get_price() << " Euro" << endl;
		totalprice += object->get_quantity()*object->get_price();
		listentries++;
	}
	if(listentries>=2)
	{
		cout << "-----------------------------------" << endl;
		cout << "\t\t\t\t" << totalprice << " Euro" << endl;
	}
}

void remove()
{
	string name;
	int no=1, selection;
	Item *object;

	cout << "Number\tName\tPrice\tQuantity" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		cout << "[" << no << "]\t";
		object->displayData();
		cout << endl;
		no++;
	}

	cout << "Which item should be deleted?" << endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= no);

	no = 1;
	for (object=list.begin(); object != 0; object = object->next())
	{
		if(selection==no)
			break;
		no++;
	}
	list.remove(object->get_name());
	cout << "Item has been deleted." << endl;
}

void empty()
{
	while(!list.empty())
		list.clear();
	cout << endl << "Shopping list is empty!" << endl;
}
