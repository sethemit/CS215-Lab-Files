/*
Course:  CS215-012
Project: Lab #3
Purpose: Program prompts user to input credit card number. It then checks if the number is valid. 
         If not, it tells the user what the check digit should be.
         Program will exit the loop when -1 is entered.
         
Author:  Seth Hammonds
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userInput;
    bool programQuit,finalCheck = false;
    int userNum1,userNum2,userNum3,userNum4,userNum5,userNum6,userNum7,userNum8,stepOne,stepTwo,finalStep = 0;

    //main loop that quits if -1 is entered
    do {
        cout << "Please enter the 8-digit credit card number (enter -1 to quit): ";
        getline(cin,userInput);
        //subtract 48 due to ASCII code for 0 
        userNum1 = userInput[0] - 48;
        userNum2 = userInput[1] - 48;
        if (userNum1 != -3 && userNum2 != 1){   //-3 & 1 equals '-1' after subtracting 48 from each character code
            userNum3 = userInput[2] - 48;
            userNum4 = userInput[3] - 48;
            userNum5 = userInput[4] - 48;
            userNum6 = userInput[5] - 48;
            userNum7 = userInput[6] - 48;
            userNum8 = userInput[7]- 48;
        }
        else if (userNum1 == -3 && userNum2 == 1){
            break;
        }

        if (cin.fail()) {
            cout << "\nThat is not a valid number!" << endl;
            cin.clear(); // Clear the failing state.
        } 
        //checks if number is negative
        else if (userNum1 < -1 || userNum2 < -1 || userNum3 < -1 || userNum4 < -1 || 
                 userNum5 < -1 || userNum6 < -1 || userNum7 < -1 || userNum8 < -1) {
            cout << "\nThat is not a valid number!" << endl;
            cin.clear();
        }
        else {
            finalCheck = true; //allows program to continue
        }

        if(finalCheck){
            //step one calculations
            stepOne = userNum8 + userNum6 + userNum4 + userNum2;
            //step two calculations
            stepTwo = ((2*userNum7)%10) + ((2*userNum7)/10) + ((2*userNum5)%10) + ((2*userNum5)/10) + 
                      ((2*userNum3)%10) + ((2*userNum3)/10) + ((2*userNum1)%10) + ((2*userNum1)/10);
            //final step calculations
            finalStep = (stepOne + stepTwo) % 10;
            //checks if the last digit is 0 & if not, finds the correct check number
            if (finalStep != 0) {
                    for (int checkDigit = 0; checkDigit < 10; checkDigit++){
                        int calculation;
                        calculation = ((checkDigit + userNum6 + userNum4 + userNum2) + stepTwo);
                        finalStep = calculation % 10;
                        if (finalStep == 0) {
                            cout << "Number is invalid." << endl;
                            cout << "Check digit should have been " << checkDigit << endl;
                            break;
                        }
                    }
            }
            else {
                cout << "Number is valid." << endl;
            }
        }
    } while(!programQuit);
    cout << "\nThank you for using Credit Card Validation!\n" << endl; 
    return 0;
}