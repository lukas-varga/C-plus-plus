#include <iostream>
#include <string>

using namespace std;

class Animal // Class Animal
{
private:
	// Data members
	int AnimalNumber;
	string Species;
	float Weight;
	static float Revenue;
	float DailyPrice;
	bool Stock;

public:
	// Member functions
	void EnterAnimal(void);
	void ShowAnimal(void);
	void SellAnimal(void);
	
	//getter
	int get_Nr() { return AnimalNumber; }
	bool get_Stock() { return Stock; }
	
	//setter
	void set_Nr(int nr) { AnimalNumber = nr; }

};

// Function to enter an animal

void Animal::EnterAnimal(void)
{
	cout << "Please enter the species: ";
	cin >> Species;
	cout << "Please enter the weight of the animal: ";
	cin >> Weight;
	Stock = true; //Animal is in stock
} ;

// Function to display the data

void Animal::ShowAnimal(void)
{
	cout << " AnimalNumber : " << AnimalNumber ;
	cout << " Species : " << Species;
	cout << " Weight: " << Weight;
	cout << " Is animal in stock? (1 = yes, 0 = no): "<< Stock;
};

void Animal::SellAnimal(void)
{
	cout<<"Whats the daily price of the animal? "<<endl;
	cin>>DailyPrice;
	Revenue= Weight*DailyPrice;
	cout<<"Revenue: " <<Revenue<<endl;
	Stock=false;
} ;

float Animal::Revenue = 0;

int main(void)
{
int s=0, eing, nr; // declared integer s to zero is used for the menu
int i = 0;
int input;
Animal animals[100] = Animal();


cout << " Welcome to the FARM MANAGEMENT" << endl << endl
<< " Please select from the menu..." << endl << endl << endl;


// While-loop that contains menu and submenu


	while (s == 0) {
	//The menu
	cout << " Enter animal [1]" << endl;
	cout << " Show animals [2]" << endl;
	cout << " Sell animal [3]" << endl;
	cout << " Exit [0]" << endl<<endl;
	cout << "Please select: ";
	cin >> input;

	//switch query loads into the individual menu items

	switch(input) {
	
		case 1 : {
			system("cls");
			animals[i].EnterAnimal(); // Function to enter an animal
			animals[i].set_Nr(i);
			cout << "The animal has been entered: " << endl;
			i++;
			break;
		}
		
		case 2 : { //Function to show all the animals
			system("cls");
			for(int j = 0; j < i; j++)
			{
			    animals[j].ShowAnimal();
			    cout << endl;
			}
			break;
		}
		
		case 3 : { //Function to sell an animal
			system("cls");
			cout << "Please enter the animal number: " << endl;
			cin >> nr;
			bool tmp = false;
			for(int j = 0; j < i; j++)
			{
				if(animals[j].get_Nr() == nr && animals[j].get_Stock() == 1)
				{
					animals[j].SellAnimal();
					tmp = true;
					break;
				}
				else if (animals[j].get_Nr() == nr && animals[j].get_Stock() == 0)
				{
					cout << "Animal with number " << animals[j].get_Nr() << " is not in stock." << endl;
					tmp = true;
					break;
				}
			}
			if(!tmp) //if no animal was found
				cout << "Animal with number " << nr << " was not found." << endl;
				
			break;
		}
		
		/* case 0 terminates program
	because s is set to 1*/
		
		case 0:
		{
			s = 1 ;
			break;
		}
		
		/* default
		menu retains when other digits are entered*/
		
		default:
		{
			s = 0 ;
		}
	}	
	system(" pause");
};
};

