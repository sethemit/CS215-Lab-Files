/*
Course:  CS215-012
Project: Lab #4
Purpose: 
         
Author:  Seth Hammonds
*/

#include <iostream>
#include <string>
using namespace std;

//draws triangle right side up
void drawTri(int size)
{
    for (int n = 1, triangleLine = 0; n <= size; ++n, triangleLine = 0) {   
        //prints spaces
        for (int emptySpace = 1; emptySpace <= size - n; ++emptySpace) {
            cout << " ";
        }
        //prints stars
        while (triangleLine != 2 * n - 1) { 
            cout << "*";
            ++triangleLine; //increments triangleLine
        }
        cout << endl;
    }
}
//draws triangle right side up
void drawTriR90(int size) {
    int triangle90 = 0;
    for (int n = 0; n < (size * 2); ++n) {
        for (int triangleCalc = 0; triangleCalc < triangle90; ++triangleCalc) {     //prints stars
            cout << "*";
        }
        (n < size) ? (++triangle90) : (--triangle90);   
        cout << endl;
    }
}
//draws triangle upside down
void drawTriR180(int size) {    
    for (int n = size; n >= 1; --n) {   
        //prints spaces
        for (int emptySpace = 0; emptySpace < size - n; ++emptySpace) { 
            cout << " ";
        }
        //prints stars
        for (int triangleCalc = n; triangleCalc <= 2 * n - 1; ++triangleCalc) {
            cout << "*";
        }
        //prints stars
        for (int triangleCalc = 0; triangleCalc < n - 1; ++triangleCalc) {  
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int triangleEnd = 0;    
    do {
        string triangleInput;
        const string quit = "q", quit2 = "Q";
        int emptySpace,triangleSize,userInput1,userInput2 = 0;

        //prompts user for triangle size
        cout << "\nEnter the size of your triangle (integer in [1, 30])" << endl;
        cout << "Type Q to quit the program: ";     
        cin.clear();
        getline(cin,triangleInput); //gets user input

        //subtract 48 due to ASCII code for 0
        userInput1 = triangleInput[0] - 48;
        userInput2 = triangleInput[1] - 48;

        //if quit is inputted, end the program
        if (triangleInput == quit || triangleInput == quit2) {     
            cout << "\nThank you, have a great day! :) " << endl; 
            cin.clear();    
            triangleEnd = 1;    //ends the program
        }
        else {
            //checks if number is 2 digits
            if (userInput2 > 0){
                userInput1 = userInput1 * 10;   //if 2 digits, multiply first digit by 10
            }
            //if user inputs 0, set to 0
            else if (userInput2 == 0 && userInput1 == 0) {
                userInput1 = 0;
            }
            //if user inputs 1 & 0, set to 10
            else if (userInput1 == 1 && userInput2 == 0) {
                userInput1 = 10;
            }
            //if user inputs 2 & 0, set to 20
            else if (userInput1 == 2 && userInput2 == 0) {
                userInput1 = 20;
            }
            //if user inputs 3 & 0, set to 30
            else if (userInput1 == 3 && userInput2 == 0) {
                userInput1 = 30;
            }
            else {
                userInput2 = 0; //if not 2 digits, set to 0
            }
            triangleSize = userInput1 + userInput2; //adds the 2 digits together

            if (triangleSize >= 1 && triangleSize <= 30) {  //checks if number is in range [1,30]
                cout << "\nThe triangle with size " << triangleSize << " is: " << endl;
                drawTri(triangleSize); //draws the triangle
                cout << "\nThe rotation for 90 degrees clockwise: " << endl;
                drawTriR90(triangleSize); //draws the triangle rotated 90 degrees
                cout << "\nThe rotation for 180 degrees clockwise: " << endl;
                drawTriR180(triangleSize); //draws the triangle rotated 180 degrees
                cout << endl;
            }
            else {
                cout << "\nThe size is not in the correct range!" << endl;  //if not in range, error message
            }
            triangleEnd = 0; //resets the end of program
        }
    } while (triangleEnd == 0); //loops until user inputs q or Q
    return 0;
}