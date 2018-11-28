#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "operation.h"

using namespace std;

class Operations
{
private:
    vector <Operation> allOperations;
    string getActualDataFromSystem ();
    string convertIntToString (int number);

public:
    void addNewOperation (int userId, string date, string item, float ammount);
    void showAllOperations ();
    void sortOperations ();
    void addData (int userId);

    Operations();
};
