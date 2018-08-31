#include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>

using namespace std;

class operation {
    int operationID, userID, year, month, day;
    string item, ammountByString;
    float ammount;
    void changeCommasToPoints(string number);
public:
    void setOperationID (int operID);
    void setUserID (int usID);
    void setItem (string description);
    void setAmmount (string value);
    void setYear (int yearDate);
    void setMonth (int monthDate);
    void setDay (int dayDate);
    int getOperationID ();
    int getUserID ();
    string getItem ();
    float getAmmount ();
    int getYear ();
    int getMonth ();
    int getDay ();
    //operation ();
    //~operation ();


};
