#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "operation.h"
#include "xmlOperationsFile.h"

using namespace std;

class Operations
{
private:
    vector <Operation> allOperations;
    vector <Operation> selectedOperations;
    string getActualDataFromSystem ();
    string convertIntToString (int number);
    float sumAllOpers;
    string filename;

    struct tm * beginTimeInfo;
    struct tm * endTimeInfo;
    int beginningDay, beginningMonth, beginningYear, endingDay, endingMonth, endingYear;
    time_t beginningDate, endingDate;

    void convertIntToTimeStruct (int begDayInt, int begMonthInt, int begYearInt, int endDayInt, int endMonthInt, int endYearInt);
    void separateStringDateToInts(string beginningDateByString, string endingDateByString);
    void convertTimeStructToTime_t ();
    int convertStringToInt (string number);
    void saveToXML (string filename);
    void loadFromXML (string filename);


public:
    void addNewOperation (int userId, string date, string item, float ammount);
    void showAllOperations ();
    void showSelectedOperations ();
    void sortOperations ();
    void addData (int userId);
    float getSumAllOpers (int userId);
    void selectOperationsByDateAndID (string beginingDateString, string endingDateString, int userId);
    float getSumSelectedOperations ();
    void setTypename (string name);

    Operations(string operationName);
};
