#pragma once
// Clock header.
#include <iostream>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;
    bool is24Hour; // true for 24-hour format, false for 12-hour format

public:
    // Constructor to initialize the clock
    Clock(int h = 0, int m = 0, int s = 0, bool format24 = true);

    // Function to display time
    void displayTime() const;

    // Function to add an hour
    void addHour();

    // Function to add a minute
    void addMinute();

    // Function to add a second
    void addSecond();
};
