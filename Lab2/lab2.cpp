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
    cin >> userInput;   //prompts user input

    cout << "Please enter three integer numbers: ";
    cin >> num1 >> num2 >> num3;   //prompts user input

    //for invalid number choice
    if (cin.fail())
    {
        cout << "Invalid choice, quitting the program...";
        cin.clear();
        return 1;
    }
    if (userInput == d || userInput == D)
    {
        if (num1 >= num2 && num1 >= num3)
        {
            cout << num1 << " ---> ";
            if (num2 >= num3)
            {
                cout << num2 << " ---> " << num3 << endl;
            }
            else
            {
                cout << num3 << " ---> " << num2 << endl;
            }
        }
        else if (num2 >= num1 && num2 >= num3)
        {
            cout << num2 << " ---> ";
            if (num1 >= num3)
            {
                cout << num1 << " ---> " << num3 << endl;
            }
            else
            {
                cout << num3 << " ---> " << num1 << endl;
            }
        }
        else
        {
            cout << num3 << " ---> ";
            if (num2 >= num1)
            {
                cout << num2 << " ---> " << num1 << endl;
            }
            else
            {
                cout << num1 << " ---> " << num2 << endl;
            }
        }


    }


    else if (userInput == i || userInput == I)
    {
        if (num1 <= num2 && num1 <= num3)
        {
            cout << num1 << " ---> ";
            if (num2 <= num3)
            {
                cout << num2 << " ---> " << num3 << endl;
            }
            else
            {
                cout << num3 << " ---> " << num2 << endl;
            }
        }
        else if (num2 <= num1 && num2 <= num3)
        {
            cout << num2 << " ---> ";
            if (num1 <= num3)
            {
                cout << num1 << " ---> " << num3 << endl;
            }
            else
            {
                cout << num3 << " ---> " << num1 << endl;
            }
        }
        else
        {
            cout << num3 << " ---> ";
            if (num2 <= num1)
            {
                cout << num2 << " ---> " << num1 << endl;
            }
            else
            {
                cout << num1 << " ---> " << num2 << endl;
            }
        }
    }




    return 0;
}