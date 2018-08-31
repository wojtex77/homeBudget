#include "operation.h"

void operation::setOperationID(int operID){
    operationID=operID;
}
void operation::setUserID(int usID){
    userID=usID;
}

void operation::setItem (string description){
    item=description;
}
void operation::setAmmount (string value){
    changeCommasToPoints(value);
}

int operation::getOperationID () {
    return operationID;
}
int operation::getUserID (){
    return userID;
}
string operation::getItem (){
    return item;
}
float operation::getAmmount (){
    return ammount;
}

void operation::setYear (int yearDate){
    year=yearDate;
}
void operation::setMonth (int monthDate){
    month=monthDate;
}
void operation::setDay (int dayDate){
    day=dayDate;
}

int operation::getYear (){
    return year;
}
int operation::getMonth (){
    return month;
}
int operation::getDay (){
    return day;
}

void operation::changeCommasToPoints(string number){
    int stringLength=number.length();
    size_t found=number.find(',');
    if (found!=string::npos) number.replace(found,1,".");
    float numberByFloat;
    numberByFloat=atof(number.c_str());
    ammount=numberByFloat;
}
