#include "xmloperationsFile.h"
#include <stdlib.h>
#include <string>


void xmlOperationsFile::saveToXML(vector <Operation> &allOperations){
    int vectorSize=allOperations.size();

    CMarkup operationsFile;
    operationsFile.AddElem("users");
    operationsFile.IntoElem();
    for (int i=0; i<vectorSize; i++){
        operationsFile.AddElem("user");
        operationsFile.IntoElem();
        operationsFile.AddElem("id",allOperations[i].getOperationId());
        operationsFile.AddElem("name",allOperations[i].getUserId());
        operationsFile.AddElem("surname",allOperations[i].getDate());
        operationsFile.AddElem("login",allOperations[i].getItem());
        operationsFile.AddElem("password",allOperations[i].getAmmount());
        operationsFile.OutOfElem();
    }
    operationsFile.OutOfElem();
    operationsFile.Save("users.xml");
};


void xmlOperationsFile::loadFromXML(vector <Operation> *allOperations){
    CMarkup operationsFile;
    Operation singleOperation;

    operationsFile.Load( "users.xml" );
    operationsFile.FindElem();
    operationsFile.IntoElem();
    while ( operationsFile.FindElem("user") ) {
        operationsFile.IntoElem();
        operationsFile.FindElem("id");
        singleOperation.setUserID(convertStringToInt(operationsFile.GetData()));
        operationsFile.FindElem("name");
        singleOperation.setName(operationsFile.GetData());
        operationsFile.FindElem("surname");
        singleOperation.setSurname(operationsFile.GetData());
        operationsFile.FindElem("login");
        singleOperation.setLogin(operationsFile.GetData());
        operationsFile.FindElem("password");
        singleOperation.setPassword(operationsFile.GetData());
        operationsFile.ResetMainPos();
        operationsFile.OutOfElem();
        allOperations->push_back(singleOperation);
    }

};
*/
