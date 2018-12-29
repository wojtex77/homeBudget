#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "operation.h"
#include "xmlOperationsFile.h"
#include "inputDataCheck.h"
#include "programMessages.h"

using namespace std;

class Operations
{
private:
    vector <Operation> allOperations;
    vector <Operation> selectedOperations;
    string getActualDataFromSystem ();
    string convertIntToString (int number);
    float sumAllOpers, sumSelectedOpers;
    string filename;

    struct tm * beginTimeInfo;
    struct tm * endTimeInfo;
    int beginningDay, beginningMonth, beginningYear, endingDay, endingMonth, endingYear;
    time_t beginningDate, endingDate;

    void convertIntToTime_t (int begDayInt, int begMonthInt, int begYearInt, int endDayInt, int endMonthInt, int endYearInt);
    void separateStringDateToInts(string beginningDateByString, string endingDateByString);
    int convertStringToInt (string number);
    void saveToXML (string filename);
    void loadFromXML (string filename);


public:
    void addNewOperation (int userId, string date, string item, float ammount);
    void showAllOperationsByUser (int loggedUserID);
    void showSelectedOperations ();
    void sortOperations ();
    void sortSelectedOperations ();
    void addData (int userId);
    float getSumAllOpers (int userId);
    void selectOperationsByDateAndID (string beginingDateString, string endingDateString, int userId);
    float getSumSelectedOperations (int userID);
    void setTypename (string name);

    Operations(string operationName);
};
