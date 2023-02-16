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
    int emptySpace,triangleEnd,triangleSize = 0;
    char triangleInput;

    do {
        cout << "\nEnter the size of your triangle (integer in [1, 30])" << endl;
        cout << "Type Q to quit the program: ";
        cin >> triangleInput;
        if (triangleInput == 'q' || triangleInput == 'Q') {
            triangleEnd = 1;
        }
        else {
            if (triangleSize >= 1 && triangleSize <= 30) {
            cout << "\nThe triangle with size " << triangleSize << "is: " << endl;
            drawTri(triangleSize);
            cout << "\nThe rotation for 90 degrees clockwise: " << endl;
            drawTriR90(triangleSize);
            cout << "\nThe rotation for 180 degrees clockwise: " << endl;
            drawTriR180(triangleSize);
            }
        }
    } 
    while (triangleEnd == 0);
    return 0;
}