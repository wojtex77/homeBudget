#include "xmlOperationFile.h"
#include <stdlib.h>
#include <string>



void xmlOperationFile::saveToXML(vector <operation> &allOperations){
    int vectorSize=allOperations.size();
    string fullDate, year, month, day;
    CMarkup operationsFile;
    operationsFile.AddElem("operations");
    operationsFile.IntoElem();
    for (int i=0; i<vectorSize; i++){
        year=IntToString(allOperations[i].getYear());
        month=IntToString(allOperations[i].getMonth());
        day=IntToString(allOperations[i].getDay());

        fullDate=year+"-"+month+"-"+day;
        operationsFile.AddElem("operation");
        operationsFile.IntoElem();
        operationsFile.AddElem("operationID",allOperations[i].getOperationID());
        operationsFile.AddElem("userID",allOperations[i].getUserID());//allUsers[i].getName());
        operationsFile.AddElem("date",fullDate);
        operationsFile.AddElem("item",allOperations[i].getItem());
        operationsFile.AddElem("ammount",allOperations[i].getAmmount());
        operationsFile.OutOfElem();
    }
    operationsFile.OutOfElem();
    operationsFile.Save(getFilename());
};

string xmlOperationFile::getFilename (){
    return filename;
}

void xmlOperationFile::setFilename (string file){
    filename=file+".xml";
}

xmlOperationFile::xmlOperationFile (string fileName){
    setFilename(fileName);
}

int xmlOperationFile::returnYearFromString (string fullDate){
    int signPosition=0;
    int i=0;
    while (fullDate[signPosition]!='-'){
        signPosition++;
    }
    int number=convertStringToInt(fullDate.substr(0,signPosition));
    return number;
}

int xmlOperationFile::returnMonthFromString (string fullDate){
    int signPosition=0;
    int i=0;
    while (fullDate[signPosition]!='-'){
        signPosition++;
    }
    signPosition++;
    while (fullDate[signPosition]!='-'){
        signPosition++;
    }
    int number=convertStringToInt(fullDate.substr(5,signPosition-5));
    return number;
}

int xmlOperationFile::returnDayFromString (string fullDate){
    int signPosition=0;
    int i=0;
    while (fullDate[signPosition]!='-'){
        signPosition++;
    }
    signPosition++;
    while (fullDate[signPosition]!='-'){
        signPosition++;
    }
    signPosition++;
    int number=convertStringToInt(fullDate.substr(signPosition,fullDate.length()-signPosition));
    return number;
}

void xmlOperationFile::loadFromXML(vector <operation> *allOperations){
    string fullDate;

    CMarkup OperationsFile;
    operation singleOperation;

    OperationsFile.Load(getFilename());
    OperationsFile.FindElem();
    OperationsFile.IntoElem();
    while ( OperationsFile.FindElem("operation") ) {
        OperationsFile.IntoElem();
        OperationsFile.FindElem("operationID");
        singleOperation.setOperationID(convertStringToInt(OperationsFile.GetData()));
        OperationsFile.FindElem("userID");
        singleOperation.setUserID(convertStringToInt(OperationsFile.GetData()));
        OperationsFile.FindElem("date");
        fullDate=OperationsFile.GetData();
        singleOperation.setYear (returnYearFromString(fullDate));
        singleOperation.setMonth (returnMonthFromString(fullDate));
        singleOperation.setDay (returnDayFromString(fullDate));
        OperationsFile.FindElem("item");
        singleOperation.setItem(OperationsFile.GetData());
        OperationsFile.FindElem("ammount");
        singleOperation.setAmmount(OperationsFile.GetData());
        OperationsFile.ResetMainPos();
        OperationsFile.OutOfElem();
        allOperations->push_back(singleOperation);
    }

};

