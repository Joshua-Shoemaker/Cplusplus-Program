/* CS 210 Project 1 Clocks.
   Prepared by Joshua Shoemaker. */
#include "Clcok.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <conio.h>
#include <chrono>
#include <mutex>
#include <tuple>

using namespace std;

mutex mtx;
bool running = true;
string errorMessage;

static void displayMenu(Clock& clock12, Clock& clock24) {
    while (running) {
        // Wait to update clocks.
        this_thread::sleep_for(chrono::seconds(1));

        clock12.addSecond(); // Update clocks.
        clock24.addSecond(); // Update clocks.
        lock_guard<mutex> guard(mtx); // Lock for thread safety.
        system("cls"); // Clear screen.

        // Display both clocks
        cout << "12-Hour Clock: ";
        clock12.displayTime();
        cout << "24-Hour Clock: ";
        clock24.displayTime();
        cout << endl;

        // Display menu
        cout << "Menu:" << endl;
        cout << "1 - Add One Hour" << endl;
        cout << "2 - Add One Minute" << endl;
        cout << "3 - Add One Second" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";

        if (!errorMessage.empty()) {
            cout << errorMessage << endl;
        }
    }
}

// Function to display the menu and handle user input
static void handleInput(Clock& clock12, Clock& clock24) {
    char choice;

    while (running) {
        

        choice = _getch();

        lock_guard<mutex> guard(mtx); // Lock for thread safety.

        // Perform actions based on the user's choice
        switch (choice) {
        case '1':
            clock12.addHour();
            clock24.addHour();
            errorMessage.clear();
            break;
        case '2':
            clock12.addMinute();
            clock24.addMinute();
            errorMessage.clear();
            break;
        case '3':
            clock12.addSecond();
            clock24.addSecond();
            errorMessage.clear();
            break;
        case '4':
            errorMessage.clear();
            cout << "Exiting program." << endl;
            running = false;
            return;
        default:
            errorMessage = "\nError: Improper selection. Please pick a menu item.";
        }

    }
}

tuple<Clock, Clock> createClocks(int h, int m, int s) {
    char tod; // Hold Time of day (am or pm).

    // Account for 12 hour input format.
    if (h <= 12) {
        cout << "Enter 1 for morning 'AM' or 2 for afternoon 'PM' ";
        cin >> tod;
        cout << endl;
        while (tod != '1' && tod != '2') { // Validate time of day.
            cout << "Invalid selection. Please enter 1 for morning or 2 for afternoon: ";
            cin >> tod;
        }

        if (tod == '1') { // Initialize morning clocks.
            Clock clock24 = Clock(h, m % 60, s % 60, true);
            Clock clock12 = Clock(h, m % 60, s % 60, false);
            return make_tuple(clock12, clock24);
        }
        else if (tod == '2') { // Initialize afternoon clocks.
            h += 12;
            Clock clock24 = Clock(h, m % 60, s % 60, true);
            Clock clock12 = Clock(h, m % 60, s % 60, false);
            return make_tuple(clock12, clock24);
        }
    }
    else {
        // Initialize for 24 hour format.
        Clock clock24 = Clock(h % 24, m % 60, s % 60, true);
        Clock clock12 = Clock(h % 24, m % 60, s % 60, false);
        return make_tuple(clock12, clock24);
    }
}

int main() {
    int hour;
    int minute;
    int second;
    Clock clock12;
    Clock clock24;

    cout << "Start the clock." << endl;
    cout << "Enter your Hour - ";
    cin >> hour;
    cout << "Enter your Minute - ";
    cin >> minute;
    cout << "Enter your Second - ";
    cin >> second;

    // Create clocks.
    tie(clock12, clock24) = createClocks(hour, minute, second);

    thread clockThread(displayMenu, ref(clock12), ref(clock24));

    handleInput(clock12, clock24);

    clockThread.join();

    return 0;
}
