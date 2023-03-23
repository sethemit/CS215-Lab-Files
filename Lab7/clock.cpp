#include <iostream>
#include <string>
#include "Clock.h"

using namespace std;

//default constructor
Clock::Clock() {
  hours = 0;
  minutes = 0;
  seconds = 0;
}

//checks if the values passed for hours,minutes and seconds are valid and set the member variables.
Clock::Clock(int hh, int mm, int ss) 
{
    if (hh >= 0 && hh < 24 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60) {
        hours = hh;
        minutes = mm;
        seconds = ss;
    } 
    else {
        cout << "Invalid time!" << endl;
    }
}

// checks if the values passed for hours,minutes and seconds are valid and set the member variables.
void Clock::setClock(int hh, int mm, int ss)
{
    if (hh >= 0 && hh < 24 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60){
        hours = hh;
        minutes = mm;
        seconds = ss;
    } 
    else {
        cout << "Invalid time!" << endl;
    }
}

// increase time by given seconds.
void Clock::incrementSeconds(int sec) {
    int totalValueOfSeconds = (hours * 3600) + (minutes * 60) + seconds + sec;
    hours = totalValueOfSeconds / 3600 % 24;
    minutes = totalValueOfSeconds / 60 % 60;
    seconds = totalValueOfSeconds % 60;
}

// increase the time by given minutes.
void Clock::incrementMinutes(int min) {
    int totalMinutes = (hours * 60) + minutes + min;
    hours = totalMinutes / 60 % 24;
    minutes = totalMinutes % 60;
}

// increment the hours by given hours, if hours reach 24 it will reset to 0.
void Clock::incrementHours(int hh) {
    hours = (hours + hh) % 24;
}

// adds C into the clock
void Clock::addTime(Clock C) {
    int totalSeconds = (hours * 3600) + (minutes * 60) + seconds + (C.hours * 3600) + (C.minutes * 60) + C.seconds;
    hours = totalSeconds / 3600 % 24;
    minutes = totalSeconds / 60 % 60;
    seconds = totalSeconds % 60;
}

// prints time in given format.
void Clock::printTime() const {
    //int display_hours = (hours == 0 || hours == 12) ? 12 : hours % 12;
    cout << "Clock C1: " << hours << " : " << minutes << " : " << seconds << endl;
}

int Clock::compareTime(Clock C) const 
{
    int totalSeconds1 = (hours * 3600) + (minutes * 60) + seconds;
    int totalSeconds2 = (C.hours * 3600) + (C.minutes * 60) + C.seconds;

    // compare the total seconds of both clocks
    if (totalSeconds1 < totalSeconds2)
        return -1; 
    else if (totalSeconds1 == totalSeconds2)
        return 0;
    else
    return 1;
}
