#include "operations.h"


int operations::getLastOperationID (){
    int highestID=0;

    if (allOperations.empty()==true){
        highestID=0;
    }
    else {
        for (int i=0; i<allOperations.size(); i++){
            if (allOperations[i].getOperationID()>highestID){
                highestID=allOperations[i].getOperationID ();
            }
        }
    }
    return highestID;
}

void operations::addPastOperation (int userID, int year, int month, int day, string value, string description)
{

    if(validateDate(checkLeapYear(year), year, month, day)==true)
    {
        operation tempOperation;
        int operationID=getLastOperationID();
        tempOperation.setUserID(userID);
        tempOperation.setOperationID(operationID+1);
        tempOperation.setYear(year);
        tempOperation.setMonth(month);
        tempOperation.setDay(day);
        tempOperation.setAmmount(value);
        tempOperation.setItem(description);
        allOperations.push_back(tempOperation);
        saveToFile(operationType);
    }
    else {
        cout << "Data niepoprawna"<< endl;
    }
}

void operations::addTodaysOperation (int userID, string value, string description){
    double year, month, day;
    time_t today;
    time (&today);
    struct tm *todayStructural;
    todayStructural = localtime (&today);
    operation tempOperation;
    year=(*todayStructural).tm_year+1900;
    month=(*todayStructural).tm_mon+1;
    day=(*todayStructural).tm_mday;
    int operationID=getLastOperationID();
    tempOperation.setUserID(userID);
    tempOperation.setOperationID(operationID+1);
    tempOperation.setYear(year);
    tempOperation.setMonth(month);
    tempOperation.setDay(day);
    tempOperation.setAmmount(value);
    tempOperation.setItem(description);
    allOperations.push_back(tempOperation);
    saveToFile(operationType);
}

void operations::showAllOperations (){
    int vectorSize=allOperations.size();
    for (int i=0; i<vectorSize; i++){
        cout << allOperations[i].getOperationID() <<  "|" <<allOperations[i].getUserID()<< "|"<<allOperations[i].getAmmount()<< "|"<<allOperations[i].getItem();
        cout << "|"<<allOperations[i].getYear()<<"-"<<allOperations[i].getMonth()<<"-"<<allOperations[i].getDay()<<endl;
    }
}

void operations::saveToFile (string filename){
    xmlOperationFile allOpers(filename);
    allOpers.saveToXML(allOperations);
}


void operations::loadFromFile (string filename, vector <operation> *allOpers){
    xmlOperationFile operations(filename);
    operations.loadFromXML(allOpers);
}

operations::operations (string xmlFilename){
    operationType=xmlFilename;
    loadFromFile(xmlFilename, &allOperations);
}

bool operations::checkLeapYear(unsigned specificYear){
    return (specificYear % 4 == 0 && specificYear % 100 != 0 || specificYear % 400 == 0);
}

bool operations::validateDate(bool leapYear, int year, int month, int day){
    int todayYear, todayMonth, todayDay;
    time_t today;
    time (&today);
    struct tm *todayStructural;
    todayStructural = localtime (&today);
    todayYear=(*todayStructural).tm_year+1900;
    todayMonth=(*todayStructural).tm_mon+1;
    todayDay=(*todayStructural).tm_mday;
    if (year<2000 || year>todayYear) return false;
    if (month>todayMonth &&year>=todayYear) return false;
    if (day>todayDay && month>=todayMonth &&year>=todayYear) return false;
    if (month>12 || month<1) return false;

    map <int, int> daysOfMonth;
    daysOfMonth.insert(pair <int, int> (1, 31));
    if (leapYear==true) daysOfMonth.insert(pair <int, int> (2, 29));
    else daysOfMonth.insert(pair <int, int> (2, 28));
    daysOfMonth.insert(pair <int, int> (3, 31));
    daysOfMonth.insert(pair <int, int> (4, 30));
    daysOfMonth.insert(pair <int, int> (5, 31));
    daysOfMonth.insert(pair <int, int> (6, 30));
    daysOfMonth.insert(pair <int, int> (7, 31));
    daysOfMonth.insert(pair <int, int> (8, 31));
    daysOfMonth.insert(pair <int, int> (9, 30));
    daysOfMonth.insert(pair <int, int> (10, 31));
    daysOfMonth.insert(pair <int, int> (11, 30));
    daysOfMonth.insert(pair <int, int> (12, 31));
    if (day>daysOfMonth[month] || day<1) return false;

    return true;
}
