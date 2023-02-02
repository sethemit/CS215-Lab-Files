/*
Course:  CS215-012
Project: Lab #2
Purpose: Asks user if they would like 3 numbers sorted in increasing or decreasing order. Program then asks user to input
         3 numbers, & puts them in the order requested.

Author:  Seth Hammonds
*/

#include <iostream>
using namespace std;

int main()
{
    string userInput;
    
    const string i = "i";
    const string I = "I";
    const string d = "d";
    const string D = "D";

    int num1, num2, num3;

    bool validInput = false;    //bool used for while statement 

	cout << "Your wish is my command!" << endl;
    cout << "I will sort three numbers under your wish:" << endl;
    cout << "Enter I for increasing ordering, D for decreasing order (I or D): ";
    userInput = cin.get();   //prompts user input
    cin.ignore(256,' ');

    //for invalid number choice:
    if (cin.fail())
    {
        cout << "Invalid choice, quitting the program...";
        cin.clear();
        return 1;
    }

    cout << "Please enter three integer nuumbers: ";
    num1 = cin.get();   //prompts user input
    num2 = cin.get();   //prompts user input
    num3 = cin.get();   //prompts user input
    //for invalid number choice
    if (cin.fail())
    {
        cout << "Invalid choice, quitting the program...";
        cin.clear();
        return 2;
    }
    return 0;
}