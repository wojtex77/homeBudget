#include "xmlUsersFile.h"
#include <stdlib.h>
#include <string>


void XmlUsersFile::saveToXML(vector <User> &allUsers){
    int vectorSize=allUsers.size();

    CMarkup usersFile;
    usersFile.AddElem("users");
    usersFile.IntoElem();
    for (int i=0; i<vectorSize; i++){
        usersFile.AddElem("user");
        usersFile.IntoElem();
        usersFile.AddElem("id",allUsers[i].getUserID());
        usersFile.AddElem("name",allUsers[i].getName());
        usersFile.AddElem("surname",allUsers[i].getSurname());
        usersFile.AddElem("login",allUsers[i].getLogin());
        usersFile.AddElem("password",allUsers[i].getPassword());
        usersFile.OutOfElem();
    }
    usersFile.OutOfElem();
    usersFile.Save("users.xml");
};


void XmlUsersFile::loadFromXML(vector <User> *allUsers){
    CMarkup usersFile;
    User singleUser;

    usersFile.Load( "users.xml" );
    usersFile.FindElem();
    usersFile.IntoElem();
    while ( usersFile.FindElem("user") ) {
        usersFile.IntoElem();
        usersFile.FindElem("id");
        singleUser.setUserID(convertStringToInt(usersFile.GetData()));
        usersFile.FindElem("name");
        singleUser.setName(usersFile.GetData());
        usersFile.FindElem("surname");
        singleUser.setSurname(usersFile.GetData());
        usersFile.FindElem("login");
        singleUser.setLogin(usersFile.GetData());
        usersFile.FindElem("password");
        singleUser.setPassword(usersFile.GetData());
        usersFile.ResetMainPos();
        usersFile.OutOfElem();
        allUsers->push_back(singleUser);
    }

};
