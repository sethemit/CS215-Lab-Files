/*Course: CS215-012
 *Project: Lab #5 (As part of Project 1)
 *Purpose: Display the Super Bowl in Roman Numeral Representation
 *         The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
 *         This program displays the Super Bowls in a centenary, from year 2000 to year 2099.
 *Author:  Seth Hammonds
 */
#include <iostream>
#include <string>

using namespace std;

//you should declare the function signature here,
//then define the function later...
//Returns a string form of a Roman Numeral.
//(n must be between 1 and 3999)
string roman_numeral(int n);

int main()
{
    const int START_SUPERBOWL = 1967;       // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    const int START = 2000;                 // This program displays Super Bowl starting in year 2000
    const int END = 2099;                   // This program displays Super Bowl ending in year 2099
    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    // The last Super Bowl which can be represented by Roman Numerals would be: START_SUPERBOWL + MAX_ROMAN - 1;
    const int GROUP = 10;                   // Layout the years in a group of 10

    // display the first 100 years of Super Bowl, starting at 1967
    cout << endl << "\t\t\tSuper Bowl Records" << endl;
    cout << "The first Super Bowl was hold at Los Angeles Memorial Coliseum on January 15, " << START_SUPERBOWL << endl;
    cout << "\tYear\t\tSuper Bowl" << endl;

    for (int i = START; i <= END; i++)
    {
        int year = i - START_SUPERBOWL + 1; 
        if (i % GROUP == 0)             
            cout << endl << "************************************" << endl << endl;
        cout << "\t" << i << "\t--->\t" << roman_numeral(year) << endl;
    }

    return 0;
}



/*
   Returns a string form of a Roman numeral.
   n must be between 1 and 3999
   @param n the number to convert into Roman Numeral
   @return string representing the corresponding Roman Numeral for n
*/
string roman_numeral(int n)
{
    //Arrays of numbers & their equivalent roman numerals
    const string romanNum[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    const int digitNum[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

    //Declaring the index & string to return
    int index = 12;                           //Index of the arrays
    string returnString;                      //String to return

    //Looping through the arrays
    while(n)                                  //While n is not 0
    {
      int numCalc = n / digitNum[index];       //Calculating which numeral to use
      n = n % digitNum[index];                 //Getting the remainder
      while(numCalc--)
      {
        returnString += romanNum[index];      //Adding the numeral to the string
      }
      index--;                                //Moving to the next roman numeral
    }
    return returnString;
}