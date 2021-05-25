#include <iostream>
#include <cstdlib>

using namespace std;

class Article
{
private:
    string name;
    float price;
public:
    string getName(void); //returns the name of the article
    float getPrice(void); //returns the price of the article
    void setName(string); //sets the name of the article
    void setPrice(float); //sets the price of the article

    void Enter_data(); //set the name and price of the article using setter functions
    void Show_data(); //returns the name and the price of the article
    void Calculate_TotalPrice(float); //A quantity is passed to the function. The total price (Quantity*Price) is calculated.
};

string Article::getName()
{
    return name;
}

float Article::getPrice()
{
    return price;
}

void Article::setName(string nameInput)
{
    name = nameInput;
}

void Article::setPrice(float priceInput)
{
    price = priceInput;
}

void Article::Enter_data()
{
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter price: ";
    cin >> price;

    cout << endl;
}

void Article::Show_data()
{
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << endl;
}

void Article::Calculate_TotalPrice(float quantity)
{
    float total = quantity * price;
    cout << "Total price: " << total << endl;
    cout << endl;
}

int main()
{
    cout << "ARTICLE" << endl;
    Article a1;
    a1.Enter_data();
    a1.Show_data();

    float quantity;
    cout << "Enter quantity: ";
    cin >> quantity;
    a1.Calculate_TotalPrice(quantity);

    cout << endl << endl;

    system("pause");
    return 0;
}
