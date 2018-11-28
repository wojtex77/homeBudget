#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>

using namespace std;

class Operation {
private:

    int operationId;
    int userId;
    int dayInt, monthInt, yearInt;
    string date, item;
    float ammount;

    time_t rawtime, actualDate;
    struct tm * timeinfo;

    string operationIdByString;
    string userIdByString;
    string ammountByString;

    string convertIntToString (int number);
    string convertFloatToString (float number);
    int convertStringToInt (string number);


public:
    //setters
    void setOperationId (int idOfOperation);
    void setUserId (int idOfUser);
    void setDate (string inputDate);
    void setItem (string inputItem);
    void setAmmount (float inputAmmount);
    //getters
    int getOperationId ();
    int getUserId ();
    string getDate ();
    string getItem ();
    float getAmmount ();
    int getDayInt ();
    int getMonthInt ();
    int getYearInt ();
    time_t getTime ();


    void convertIntToTimeStruct (int dayInt, int monthInt, int yearInt);
    void separateStringDateToInts(string date);
    void convertTimeStructToTime_t ();
    float convertStringToFloat (string number);

};
