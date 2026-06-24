#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency;

public:
    GroceryTracker();

    void LoadData(string fileName);
    void CreateBackupFile();
    int GetItemFrequency(string item);
    void PrintAllFrequencies();
    void PrintHistogram();
};

#endif