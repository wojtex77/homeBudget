#include <vector>
#include <string>
#include "xmlOperationFile.h"
#include <map>

using namespace std;

class operations {
    vector <operation> allOperations;
    int getLastOperationID ();
    string operationType;
    void saveToFile (string filename);
    void loadFromFile (string filename, vector <operation> *allOpers);
    bool validateDate(bool leapYear, int year, int month, int day);
    bool checkLeapYear(unsigned specificYear);
public:
    void addPastOperation (int userID, int year, int month, int day, string value, string description);
    void addTodaysOperation (int userID, string value, string description);
    void showAllOperations ();
    operations (string xmlFilename);
};
