/*
Course:  CS215-012
Project: Lab #2
Purpose: Asks user if they would like 3 numbers sorted in increasing or decreasing order. Program then asks user to input
        
         

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

	cout << "Your wish is my command!" << endl;
    cout << "I will sort three numbers under your wish:" << endl;
    cout << "Enter I for increasing ordering, D for decreasing order (I or D): ";
    //
    cin >> userInput;

    //increasing IF statement
    if (userInput == i or userInput == I) {
        cout << "Please enter three integer nuumbers: ";
        cin >> num1 >> num2 >> num3;

        if (num1 > num2 && num2 > num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num1 < num2 && num2 < num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 > num1 && num1 > num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 < num1 && num1 < num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        //leniently increasing orders
        else if (num1 == num2 && num2 == num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in leniently increasing order!" << endl;
        }
        else if (num1 >= num2 && num2 > num3) {
            //
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in leniently increasing order!" << endl;
        }
        else if (num1 <= num2 && num2 < num3) {
            //
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 >= num1 && num1 > num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 <= num1 && num1 < num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num1 > num2 && num2 >= num3) {
            //
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in leniently increasing order!" << endl;
        }
        else if (num1 < num2 && num2 <= num3) {
            //
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 > num1 && num1 >= num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
        else if (num2 < num1 && num1 <= num3) {
            cout << "Numbers are sorted in increasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in strictly increasing order!" << endl;
        }
    }

    //decreasing IF statement
    else if (userInput == d or userInput == D) {
        cout << "Please enter three integer nuumbers: ";
        cin >> num1 >> num2 >> num3;

        //
        if (num1 > num2 && num2 > num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in strictly decreasing order!" << endl;
        }
        else if (num1 < num2 && num2 < num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in strictly decreasing order!" << endl;
        }
        else if (num2 > num1 && num1 > num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in strictly decreasing order!" << endl;
        }
        else if (num2 < num1 && num1 < num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in strictly decreasing order!" << endl;
        }
        //leniently increasing orders
        else if (num1 == num2 && num2 == num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num1 >= num2 && num2 > num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num1 <= num2 && num2 < num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num2 >= num1 && num1 > num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num2 <= num1 && num1 < num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num1 > num2 && num2 >= num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num1 << " --> " << num2 << " --> " << num3 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num1 < num2 && num2 <= num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num2 << " --> " << num1 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num2 > num1 && num1 >= num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num2 << " --> " << num1 << " --> " << num3 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
        else if (num2 < num1 && num1 <= num3) {
            cout << "Numbers are sorted in decreasing order:" << endl;
            cout << num3 << " --> " << num1 << " --> " << num2 << endl;
            cout << "Numbers are in leniently decreasing order!" << endl;
        }
    }
    //else statement for invalid choice
    else {
        cout << "Invalid choice, quitting the program..." << endl;
    }
	return 0;
}