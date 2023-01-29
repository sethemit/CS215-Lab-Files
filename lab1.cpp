/*
Course:  CS215-012
Project: Lab #1
Purpose: This program says hello & introduces myself to Ms. Snider, Mr. Karki, & Dr. Pike.
         Program then takes an amount due & amount received, then displays change 
         in dollars, quarters, dimes, nickels, & pennies.

Author:  Seth Hammonds
*/

#include <iostream>
using namespace std;
int main()
{
    //displays text introducing myself & showing a smiling face
	cout << "Hello Kennedy Snider, Bikram Karki, & Dr. Pike!" <<	endl;
	cout << "My name is Seth. Nice to meet you!" << endl;
	cout << "   @@@@@@@@@  " << endl;
	cout << " |           |" << endl;
	cout << " |  ~~  ~~   |" << endl;
	cout << "{{___*___*___}}" << endl;
	cout << " |           |" << endl;
	cout << " |___________|" << endl;

    //declares variables w/ a starting value of 0
	double amountDue = 0.0;
	double amountReceived = 0.0;
	int amountOwed = 0;
	int dollar = 0;
	int quarter = 0;
	int dime = 0;
	int nickel = 0;
	int pennie = 0;
	int amountLeft = 0;
    //value used to help convert amount to change
	int convertChange = 100;
    //used to help round off during calculation 
	float round = 0.5;

    //prompts user to enter the amount due & received
	cout << "Enter the amount due : $ ";
	cin >> amountDue;
	cout << "Enter the amount received : $ ";
	cin >> amountReceived;

    //calculates the amount owed by subtracting amount due from amount received, then converts the amount to change & rounds it
	amountOwed = (amountReceived - amountDue) * convertChange + round;

    //takes the amount owed, finds how many dollars & stores it, then finds the remainder & repeats for every coin
	dollar = amountOwed / 100;
	amountLeft = amountOwed % 100;
	quarter = amountLeft / 25;
	amountLeft = amountLeft % 25;
	dime = amountLeft / 10;
	amountLeft = amountLeft % 10;
	nickel = amountLeft / 5;
	amountLeft = amountLeft % 5;
	pennie = amountLeft;

    //displays the final amount of change
	cout << "The change is: " << endl;
	cout << "Dollars:\t" << dollar << endl;
	cout << "Quarter:\t" << quarter << endl;
	cout << "Dimes:\t\t" << dime << endl;
	cout << "Nickels:\t" << nickel << endl;
	cout << "Pennies:\t" << pennie << endl;
	
	return 0;
}