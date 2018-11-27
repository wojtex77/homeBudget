#include <iostream>
#include <vector>
#include <algorithm>
#include "operation.h"

using namespace std;

class Operations
{
private:
    vector <Operation> allOperations;
public:
    void addNewOperation (int userId, string item, string date, float ammount);
    void showAllOperations ();
    void sortOperations ();

    Operations();
};
