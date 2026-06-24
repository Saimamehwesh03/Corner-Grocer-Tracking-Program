#include "GroceryTracker.h"
#include <fstream>
#include <iostream>

using namespace std;

GroceryTracker::GroceryTracker() {
}

void GroceryTracker::LoadData(string fileName) {

    ifstream inputFile(fileName);

    string item;

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

void GroceryTracker::CreateBackupFile() {

    ofstream outputFile("frequency.dat");

    for (auto const& pair : itemFrequency) {
        outputFile << pair.first << " "
                   << pair.second << endl;
    }

    outputFile.close();
}

int GroceryTracker::GetItemFrequency(string item) {

    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }

    return 0;
}

void GroceryTracker::PrintAllFrequencies() {

    for (auto const& pair : itemFrequency) {
        cout << pair.first << " "
             << pair.second << endl;
    }
}

void GroceryTracker::PrintHistogram() {

    for (auto const& pair : itemFrequency) {

        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}