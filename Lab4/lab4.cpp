/*
Course:  CS215-012
Project: Lab #4
Purpose: 
         
Author:  Seth Hammonds
*/

#include <iostream>
#include <string>
using namespace std;

void drawTri(int size)
{
    for (int n = 1, triangleLine = 0; n <= size; ++n, triangleLine = 0) {
        for (int emptySpace = 1; emptySpace <= size - n; ++emptySpace) {
            cout << " ";
        }
        while (triangleLine != 2 * n - 1) {
            cout << "*";
            ++triangleLine;
        }
        cout << endl;
    }
}
void drawTriR90(int size) {
    int triangle90 = 0;
    for (int n = 0; n < (size * 2); ++n) {
        for (int triangleCalc = 0; triangleCalc < triangle90; ++triangleCalc) {
            cout << "*";
        }
        (n < size) ? (++triangle90) : (--triangle90);
        cout << endl;
    }
}
void drawTriR180(int size) {
    for (int n = size; n >= 1; --n) {
        for (int emptySpace = 0; emptySpace < size - n; ++emptySpace) {
            cout << " ";
        }
        for (int triangleCalc = n; triangleCalc <= 2 * n - 1; ++triangleCalc) {
            cout << "*";
        }
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
        const string quit = "q", quit2 = "Q";
        string triangleInput;
        int emptySpace,triangleSize,userInput1,userInput2 = 0;

        cout << "\nEnter the size of your triangle (integer in [1, 30])" << endl;
        cout << "Type Q to quit the program: ";
        cin.clear();
        getline(cin,triangleInput);

        //subtract 48 due to ASCII code for 0
        cout << triangleInput[1] << " \n" << endl;
        userInput1 = triangleInput[0] - 48;
        userInput2 = triangleInput[1] - 48;

        if (cin.fail()) {
            cout << "\nThat is not a valid number!" << endl;
            cin.clear(); // Clear the failing state.
        }
        //if quit is inputted, end the program
        else if (triangleInput == quit || triangleInput == quit2) {
            cout << "\nThank you, have a great day! :) " << endl;
            cin.clear();
            triangleEnd = 1;
        }
        else {
            //checks if number is 2 digits
            if (userInput2 > 0){
                userInput1 = userInput1 * 10;
            }
            else if (userInput2 == 0 && userInput1 == 0) {
                userInput1 = 0;
            }
            else if (userInput1 == 1 && userInput2 == 0) {
                userInput1 = 10;
            }
            else if (userInput1 == 2 && userInput2 == 0) {
                userInput1 = 20;
            }
            else if (userInput1 == 3 && userInput2 == 0) {
                userInput1 = 30;
            }
            else {
                userInput2 = 0; //if not 2 digits, set to 0
            }
            triangleSize = userInput1 + userInput2;
            cout << triangleSize << " " << userInput1 << " " << userInput2 << endl;
            if (triangleSize >= 1 && triangleSize <= 30) {
            cout << "\nThe triangle with size " << triangleSize << " is: " << endl;
            drawTri(triangleSize);
            cout << "\nThe rotation for 90 degrees clockwise: " << endl;
            drawTriR90(triangleSize);
            cout << "\nThe rotation for 180 degrees clockwise: " << endl;
            drawTriR180(triangleSize);
            cout << endl;
            }
            else {
                cout << "\nThe size is not in the correct range!" << endl;
            }
            triangleEnd = 0;
        }
    } while (triangleEnd == 0);
    return 0;
}