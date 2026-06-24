#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

void DisplayMenu() {

    cout << "\nCorner Grocer Menu\n";
    cout << "------------------\n";
    cout << "1. Search Item Frequency\n";
    cout << "2. Display All Frequencies\n";
    cout << "3. Display Histogram\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

int main() {

    GroceryTracker tracker;

    tracker.LoadData("CS210_Project_Three_Input_File.txt");

    tracker.CreateBackupFile();

    int choice = 0;

    while (choice != 4) {

        DisplayMenu();

        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number: ";
            cin >> choice;
        }

        switch (choice) {

        case 1:
        {
            string item;

            cout << "Enter item name: ";
            cin >> item;

            cout << item << " was purchased "
                 << tracker.GetItemFrequency(item)
                 << " time(s).\n";

            break;
        }

        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram();
            break;

        case 4:
            cout << "Program exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }
    }

    return 0;
}