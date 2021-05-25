#include <iostream>
#include <cstdlib>

using namespace std;

void outputColdWarm(string,int);
void yearAverage(int[]);
int warmestMonthOfTheYear(int[]);
void sort(string[], int[]);

int main(int argc, char** argv) {
	string month[] = {"January", "February", "March", "April", "Mai", "June", "July", "August", "September", "October", "November", "December"};
	int temperature[] = {-1, 0, 4, 8, 13, 17, 21, 24, 19, 11, 9, 5};
	int input = 1;
	int tmp = 0;
	
	while(input != 0)
	{
		system("cls");
		cout << "[1] Show temperature of a month (text input)" << endl;
		cout << "[2] Show temperature of a month (selection)" << endl;
		cout << "[3] Show average temperature" << endl;
		cout << "[4] Show warmest month" << endl;
		cout << "[5] Show temperature sorted" << endl;
		cout << "[0] Exit" << endl << endl;
		cout << "Please make a selection: ";
		
		cin >> input;
		
		switch(input)
		{
			case 1:
				{
					system("cls");
					
					string input_month;
					tmp = 0;
					
					cout << "Please enter a month: ";
					cin >> input_month;
					
					for(int i = 0; i < 12; i++)
					{
						if(input_month == month[i])
						{
							tmp = 1;
							
							outputColdWarm(month[i], temperature[i]);
							break;
						}
					}
					if(tmp != 1)
					{
						cerr << endl << "Month not found" << endl << endl;
					}
					
					system("pause");
					break;
				}
			case 2:
				{
					system("cls");
					
					for(int i = 0; i < 12; i++)
					{
						cout << "[" << i+1 << "]" << month[i] << endl;
					}
					
					cout << endl << "Please make a selection: ";
					cin >> tmp;
					
					if(tmp > 12 || tmp < 1)
					{
						cerr << endl << "Month not found" << endl << endl;
					}
					else
					{
						outputColdWarm(month[tmp-1], temperature[tmp-1]);
					}	
					system("pause");
					break;
				}
			case 3:
				{
					system("cls");
					yearAverage(temperature);
					system("pause");
					break;
				}
			case 4:
				{
					system("cls");
					tmp = warmestMonthOfTheYear(temperature);
					cout << "The warmest month of the year is " << month[tmp] << " with " << temperature[tmp] <<" degree Celsius" << endl << endl;
					system("pause");
					break;
				}
			case 5:
				{
					system("cls");
					sort(month, temperature);
					system("pause");
					break;
				}
			case 0:
				{
					cout << endl << "Good bye!" << endl;
					break;
				}
			default:
				{
					cout << endl << "Incorrect input!" << endl << endl;
					system("pause");
				}
		}	
	}
	return 0;
}

void outputColdWarm(string input_month, int temperature)
{
	cout << endl << "In " << input_month << " the average temperature was " << temperature << " degree Celsius";
	
	if(temperature > 0)
		cout << " warm";
	else if(temperature < 0)
		cout << " kalt";
		
	cout << endl << endl;
}

void yearAverage(int temp[])
{
	float summe = 0;
	for(int i = 0; i < 12; i++)
	{
		summe = summe + temp[i]; //summe += temp[i]
	}
	cout << "The average annual temperature is " << (summe / 12) << " degree Celsius" << endl << endl;
}

int warmestMonthOfTheYear(int temp[])
{
	int max = 0;
	int z = 0;
	for(int i = 0; i < 12; i++)
	{
		if(temp[i] > max)
		{
			max = temp[i];
			z = i;
		}
	}
	return z;
}

void sort(string mon[], int temp[])
{
	string tmp_monat;
	int tmp_temperatur;
	
	for(int i = 0; i < 12; i++)
	{
		for(int j = (i+1); j < 12; j++)
		{
			if(temp[i] > temp[j])
			{
					tmp_monat = mon[i]; 
	                mon[i] = mon[j];
	                mon[j] = tmp_monat;
	                
	                tmp_temperatur = temp[i]; 
	                temp[i] = temp[j];
	                temp[j] = tmp_temperatur;
			}
		}
	}
	
	int x = 0;
	do
	{
		cout << temp[x] << " Grad im Monat " << mon[x] << endl;
		x++;
	}
	while(x<12);
	
	cout << endl;
}
