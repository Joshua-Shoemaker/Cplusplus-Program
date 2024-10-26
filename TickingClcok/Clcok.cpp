#include "Clcok.h"
#include <iomanip>
using namespace std;
// Clock class to represent the clock

    // Constructor to initialize the clock
Clock::Clock(int h, int m, int s, bool format24)
    : hours(h), minutes(m), seconds(s), is24Hour(format24) {}

// Function to display time
void Clock::displayTime() const {
    int displayHours = hours;
    string period = "";

    // Adjust for 12-hour format
    if (!is24Hour) {
        period = (hours >= 12) ? "PM" : "AM";
        displayHours = (hours % 12 == 0) ? 12 : hours % 12;
    }

    // Display time in the desired format
    cout << setw(2) << setfill('0') << displayHours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds;

    if (!is24Hour) {
        cout << " " << period;
    }
    cout << endl;
}

// Function to add an hour
void Clock::addHour() {
    hours = (hours + 1) % 24; // Add hour. displayTime handles 12 and 24 hour clocks.
}

// Function to add a minute
void Clock::addMinute() {
    minutes = (minutes + 1) % 60;
    if (minutes == 0) addHour(); // Increment hour if minutes roll over
}

// Function to add a second
void Clock::addSecond() {
    seconds = (seconds + 1) % 60;
    if (seconds == 0) addMinute(); // Increment minute if seconds roll over
}