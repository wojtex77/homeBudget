#include "xmloperationsFile.h"
#include <stdlib.h>
#include <string>


void xmlOperationsFile::saveToXML(vector <Operation> &allOperations, string filename){
    int vectorSize=allOperations.size();
    string fullname=filename+".xml";

    CMarkup operationsFile;
    operationsFile.AddElem("operations");
    operationsFile.IntoElem();
    for (int i=0; i<vectorSize; i++){
        operationsFile.AddElem("operation");
        operationsFile.IntoElem();
        operationsFile.AddElem("operationId",allOperations[i].getOperationId());
        operationsFile.AddElem("userId",allOperations[i].getUserId());
        operationsFile.AddElem("date",allOperations[i].getDate());
        operationsFile.AddElem("item",allOperations[i].getItem());
        operationsFile.AddElem("ammount",allOperations[i].getAmmount());
        operationsFile.OutOfElem();
    }
    operationsFile.OutOfElem();
    operationsFile.Save(fullname);
};


void xmlOperationsFile::loadFromXML(vector <Operation> *allOperations, string filename){
    CMarkup operationsFile;
    Operation singleOperation;
    string fullname=filename+".xml";

    operationsFile.Load( fullname );
    operationsFile.FindElem();
    operationsFile.IntoElem();
    while ( operationsFile.FindElem("operation") ) {
        operationsFile.IntoElem();
        operationsFile.FindElem("operationId");
        singleOperation.setOperationId(convertStringToInt(operationsFile.GetData()));
        operationsFile.FindElem("userId");
        singleOperation.setUserId(convertStringToInt(operationsFile.GetData()));
        operationsFile.FindElem("date");
        singleOperation.setDate(operationsFile.GetData());
        operationsFile.FindElem("item");
        singleOperation.setItem(operationsFile.GetData());
        operationsFile.FindElem("ammount");
        singleOperation.setAmmount(singleOperation.convertStringToFloat(operationsFile.GetData()));
        operationsFile.ResetMainPos();
        operationsFile.OutOfElem();
        allOperations->push_back(singleOperation);
    }

};
