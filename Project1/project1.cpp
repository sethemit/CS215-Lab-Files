/*Course: CS215-012
 *Project: Project #1
 *Purpose: Asks user which year they want to go to and displays the Super Bowl in Roman Numeral Representation
 *         The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum)
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
void printOutput();

int main()
{
    const int START_SUPERBOWL = 1967;                               // The first Super Bowl was hold in 1967 (at Los Angeles Memorial Coliseum) 
    // define the correct range for Roman Numerals: [MIN_ROMAN, MAX_ROMAN]
    const int MIN_ROMAN = 1;
    const int MAX_ROMAN = 3999;
    // The last Super Bowl which can be represented by Roman Numerals would be: START_SUPERBOWL + MAX_ROMAN - 1;
    const int GROUP = 10;                                           // Layout the years in a group of 10

    string userChoice;                                              // User's choice of year
    int userYear;                                                   // User's choice of year converted to int
    bool endLoop = false;                                           // Flag to end the loop

    do
    {
        printOutput();                                              // Display the output & prompt the user
   	    cin.clear();
        getline(cin,userChoice);                                    // Gets user input
   	    userYear = atoi(userChoice.c_str());                        // Convert user input to int

        // Check if user wants to quit
   	    if(userChoice == "q" || userChoice == "Q")
   	    {   
            cout << "Back to 2023, and have a great day!" << endl;  // Display exit message
            endLoop = true;                                         // Set endLoop to true
   		    break;                                                  // Exit the loop
	    }
	    cout << "\n";

        // Check if user input is in range
	    if(userYear >= START_SUPERBOWL && userYear <= START_SUPERBOWL + MAX_ROMAN - MIN_ROMAN)                  // Check if user input is between 1967 & 5965
	    {
            cout << "The time machine will bring you to the year of " << userYear << ":" << endl;
            cout << "It is Super Bowl " << roman_numeral(userYear - START_SUPERBOWL + MIN_ROMAN ) << endl;      // Display the Roman Numeral
            cout << "We will help you find out the result and other interesting information...next time:)\n\n" << endl;
        }
        // Check if user input is less than 1967
        else if (userYear < START_SUPERBOWL && userYear != 0) {                                                
            cout << "The time machine will bring you to the year of " << userYear << ":" << endl;
            cout << "Wait!!! The year you enter is TOO EARLIER than the first Super Bowl!\n\n" << endl;
        }
        // Check if user input is greater than 5965
        else if (userYear > START_SUPERBOWL + MAX_ROMAN - MIN_ROMAN && userYear != 0) {                         
            cout << "The time machine will bring you to the year of " << userYear << ":" << endl;
            cout << "Hold on!!! The year you enter is TOO BIG for Roman Numerals!\n\n" << endl;
        }
        else
        {
    	    cout << "Please use four-digit number to represent a year (1967-5965)!\n\n";  // Display error message
	    }
    } while(!endLoop);  // Loop until user wants to quit
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
      int numCalc = n / digitNum[index];      //Calculating which numeral to use
      n = n % digitNum[index];                //Getting the remainder
      while(numCalc--)                        //Looping through the number of times the numeral is used
      {
        returnString += romanNum[index];      //Adding the numeral to the string
      }
      index--;                                //Moving to the next roman numeral
    }
    return returnString;           
}

//prints the output & prompts the user for input
void printOutput()
{
	cout << "*****************************************************************\n";
	cout << "*     The Super Bowl is the annual final playoff game\t\t*\n";
	cout << "*        of the NFL to determine the league champion\t\t*\n";
	cout << "* The first Super Bowl took place on January 15, 1967\t\t*\n";
	cout << "* Super Bowl I (Los Angeles Memorial Coliseum) -->1967\t\t*\n";
	cout << "* This Roman Numerals Convertor is written by Seth Hammonds\t*\n";
	cout << "* If you had a time machine, which year of Super Bowl\t\t*\n";
	cout << "* you want to attend (1967-5965)\t\t\t\t*\n"; 
	cout << "*********************************************************\n";
	cout << "Please enter the year you want to attend (click Q or q to quit):\n"; 
}