#include "operation.h"

//setters
void Operation::setOperationId(int idOfOperation)
{
    operationId=idOfOperation;
    operationIdByString=convertIntToString(idOfOperation);
};
void Operation::setUserId(int idOfUser)
{
    userId=idOfUser;
    userIdByString=convertIntToString(idOfUser);
};
void Operation::setDate(string inputDate)
{
    date=inputDate;
};
void Operation::setItem(string inputItem)
{
    item=inputItem;
};
void Operation::setAmmount(float inputAmmount)
{
    ammount=inputAmmount;
    ammountByString=convertFloatToString(ammount);
};

//getters
int Operation::getOperationId ()
{
    return operationId;
};
int Operation::getUserId ()
{
    return userId;
};
string Operation::getDate ()
{
    return date;
};
string Operation::getItem ()
{
    return item;
};
float Operation::getAmmount ()
{
    return ammount;
};

string Operation::convertIntToString (int number)
{
    stringstream ss;
    ss << number;
    string numberByString=ss.str();
    return numberByString;
};
string Operation::convertFloatToString (float number)
{
    stringstream ss;
    ss << number;
    string numberByString=ss.str();
    return numberByString;
};
int Operation::convertStringToInt (string number)
{
    return stoi (number);
};
float Operation::convertStringToFloat (string number)
{
    return stof (number);
};

void Operation::convertIntToTimeStruct (int dayInt, int monthInt, int yearInt)
{
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = yearInt - 1900;
    timeinfo->tm_mon = monthInt - 1;
    timeinfo->tm_mday = dayInt;
};

void Operation::separateStringDateToInts(string date)
{
    int dateLength=date.length();
    vector <int> separatorPositions;
    for (int i=0; i<dateLength; i++)
    {
        if (date[i]=='-')
            separatorPositions.push_back(i);
    }
    dayInt=convertStringToInt(date.substr(0,2));
    monthInt=convertStringToInt(date.substr(3,2));
    yearInt=convertStringToInt(date.substr(6,4));
};

int Operation::getDayInt ()
{
    return dayInt;
};
int Operation::getMonthInt ()
{
    return monthInt;
};
int Operation::getYearInt ()
{
    return yearInt;
};

void Operation::convertTimeStructToTime_t (){
    actualDate=mktime(timeinfo);
};
time_t Operation::getTime (){
    return actualDate;
};


