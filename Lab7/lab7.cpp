/* File:   lab7.cpp
 * Course: CS215-012
 * Project: Lab 7
 * Purpose: Provide the delcaration of the class named Clock
 *			Note that it represents a 24-hour clock (or you can call it military time)
 * Author:  Seth Hammonds
 */
#include <iostream>
#include "Clock.h"

using namespace std;

int main()
{
    Clock C1(3,-5,16);  //set C1 with h:m:s = 3:-5:16
    C1.setClock(0,0,5); // set C1 with h:m:s 0:0:0
    Clock C2(12,35,59); // create second Clock object C2 with h:m:s=12:35:59
    C1.printTime();     // print C1
    C2.printTime();     // print C2

    //compare C1 with C2
    int comparisonResult = C1.compareTime(C2); // compare C1 with C2

    //prints result of the comparison
    if (comparisonResult == -1) {
        cout << "C1 is earlier than C2" << endl;
    } 
    else if (comparisonResult == 0) {
        cout << "C1 is the same as C2" << endl;
    } 
    else if (comparisonResult == 1) {
        cout << "C1 is later than C2" << endl;
    }

    C1.addTime(C2); //add C2 into C1
    C1.printTime(); //print C1
    C2.printTime(); //print C2

    //compare C2 with C1
    comparisonResult = C2.compareTime(C1);

    //prints result of the comparison
    if (comparisonResult == -1) {
        cout << "C1 is later than C2" << endl;
    } 
    else if (comparisonResult == 0) {
        cout << "C2 is the same as C1" << endl;
    } 
    else if (comparisonResult == 1) {
        cout << "C2 is later than C1" << endl;
    }

    C1.incrementSeconds(55);     //increase clock C1 by 55 seconds
    C1.printTime();             //print C1
    C1.incrementMinutes(119);   //increase clock C1 by 119 minutes
    C1.printTime();             //print C1
    C1.incrementHours(22);      //increase clock C1 by 22 hours
    C1.printTime();             //print C1
    C2.printTime();             //print C2
    comparisonResult = C2.compareTime(C1);//compare C2 with C1

    //prints result of the comparison
    if (comparisonResult == -1) 
    {
        cout << "C2 is earlier than C1" << endl;
    } 
    else if (comparisonResult == 0) 
    {
        cout << "C2 is the same as C1" << endl;
    } 
    else if (comparisonResult == 1) 
    {
        cout << "C2 is later than C1" << endl;
    }
    return 0;
}
