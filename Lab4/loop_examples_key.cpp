/*
 * Course: CS215-00x
 * Project: Demo Loops
 * Purpose: this program contains two sub-problems:
 *			1. start with a simple example: to print one row of n stars (n is the user input positive integer)
 *			   requirement: for this sub-problem, you need to practice three Loop statements: while; for; do-while
 *
 *			2. then prints FOUR Triangle patterns decribed in lecture slides
 *             purpose: to practice nested loop structure
 *
 * Author: (your name)
 */
#include <iostream>
using namespace std;

int main()
{
    //1. to print one row of n stars (n is the user input)
    // it will handle user input validation
    int inputN;
    bool validInputN = false;

    do
    {
        cout << "Please enter a positive integer as the size : ";
        cin >> inputN;

        if (cin.fail())     //verify if cin fails
        {
            cout << "Expecting a number..." << endl;
            // Clear the failing state of input stream, so that the further extration operations can be applied
            cin.clear();  // note that clear() function will reset the status of cin back to good
            // But clear() function does not clear or wipe away the data in input stream!!!
        }
        else   // verify input is an integer 
        {
            if (inputN <= 0)   //input is not in the correct range
                cout << "Need a positive number!" << endl;
            else    // valid input has been collected
                validInputN = true;
        }
        cin.ignore(256, '\n');  //extract and ingore anything left (bad input) in the input stream
    } while (!validInputN);

    //option 1: using while statement
    cout << "Using while loop to print " << inputN << " stars!" << endl;
    int count = 0;
    while (count < inputN)
    {
        cout << "*";
        count++;
    }
    cout << endl << endl;

    //option 2: using for statement
    cout << "Using for loop to print " << inputN << " stars!" << endl;
    for (int i = 0; i < inputN; i++)
    {
        cout << "*";
    }
    cout << endl << endl;

    //option 3: using do-while statement
    cout << "Using do-while loop to print " << inputN << " stars!" << endl;
    int howmany = 0;
    do
    {
        cout << "*";
        howmany++;
    } while (howmany < inputN);
    cout << endl << endl;


    //2. prints FOUR Triangle patterns decribed in lecture slides
    //   purpose: to practice nested loops
    const int ROWS = 6;
    cout << endl;
    cout << "Pattern 1: " << endl;
    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }

    cout << endl;
    cout << "Pattern 2: " << endl;
    for (int i = ROWS; i>=1 ; i--)
    {
        for (int j = 1 ; j <= i; j++)
            cout << j;
        cout << endl;
    }

    cout << endl;
    cout << "Pattern 3: " << endl;
    for (int i = 1; i <= ROWS; i++)
    {
        for (int j = 1; j <= ROWS - i; j++)
            cout << " ";
        for (int k = i; k >= 1; k--)
            cout << k;
        cout << endl;
    }

    cout << endl;
    cout << "Pattern 4: " << endl;
    for (int i = ROWS; i >= 1; i--)
    {
        for (int j = 1; j <= ROWS - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        cout << endl;
    }

    return 0;
}