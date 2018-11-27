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
    void addNewOperation ();
    void showAllOperations ();
    void sortOperations ();

    Operations();
};
