#include <cstdlib>
#include <iostream>

using namespace std;


//Shopping List

//Declaration of global variables
string product[10];   //Array for ten items
float price[10];   // Array for ten corresponding prices
int counter = 0;    // Counter for the index in the array

//Function prototypes
void addItem();                                
void showItem();
void sortItem();

//Adds new item to the shopping list
void addItem()
{
     if(counter < 10)
	 {  //The array can only hold ten items
         string name;
         float value;
         cout << "Please enter the name of the item: ";
         cin >>  name;
         cout << endl;
         cout << "Please enter the price of the item: ";
         cin >> value;
         cout << endl;
         product[counter] = name;
         price[counter] = value;
         counter++;  
         cout << "The item has been added." << endl;
     }
	 else
	 {
        cout << "The list is full. You can not add any more items!" << endl;      
     }
} 

//Outputs all items and their prices
void showItem(){
	
     for(int i = 0; i < counter;i++){ 
        cout << "Name: " << product[i] << endl;
        cout << "Price: " << price[i] << endl;
        cout << endl;        
     }     
}

// Sorts all elements according to the price in an ascending order

void sortItem()
{
   for(int i = 1;i<counter;i++){ //Take an element of the array (not necessary the first one)
     for(int j = 0; j < i;j++){  //and all the items that precede this item in the list
        if(price[j] > price [i]){ //and check if all preceding elements are smaller. If one is larger than we swap them.
           float value;
           string item;  //The name of the corresponding product must also be swapped in the same way. 
           value = price[j];
           item = product[j];
           price[j] = price[i];
           product[j] = product[i];
           price[i] = value;  
           product[i] = item;  
        }
     }          
   }       
   cout << "The items have been sorted." << endl;    
}

int main(int argc, char *argv[])
{
    int choice;
    do{ //Show menu first
       cout << "**************** Shopping list ********** " << endl << endl;
       cout << "Number of items: " << counter << endl << endl;
       cout << "Add item (1) " << endl;
       cout << "Show items (2) " << endl;
       cout << "Sort items (3) " << endl;                             
       cout << "Exit (0) " << endl << endl;
       
       cout << "Selection: ";
       cin >> choice;
       cout << endl; 
       
       //Do something depending of the selection
       switch(choice){
          case 1:{
          		system("cls");
                addItem();
                break;
          }
          case 2:{
          		system("cls");
                showItem();
                break;
          }     
          case 3:{
          		system("cls");
                sortItem();
                break;
          }
       }
       if(choice != 0){ //As long as it has not been decided to terminate the program.
          system("PAUSE");
          system("cls");
       }
    }while(choice != 0); //The menu is displayed until the program is exited.
    return EXIT_SUCCESS;
}
