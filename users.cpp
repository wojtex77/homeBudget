#include <iostream>
#include "users.h"
#include <windows.h>

using namespace std;

bool Users::verifyUniqueLogin (User &newUser){
    int i=0;
    bool uniqueLogin=true;
    while((i<allUsers.size())&&(uniqueLogin==true)){
        if (allUsers[i].getLogin()!=newUser.getLogin()){
            uniqueLogin=true;
        }
        else uniqueLogin=false;
        i++;
    }
    return uniqueLogin;
}
void Users::createNewUser(){
    User newUser;
    newUser.addData();
    bool uniqueLogin=true;
    uniqueLogin=verifyUniqueLogin (newUser);
    if (allUsers.empty()==true){
        newUser.setUserID(1);
    }
    else {
        int lastID=allUsers[allUsers.size()-1].getUserID();
        int userID=lastID+1;
        newUser.setUserID(userID);
    }
    if (uniqueLogin==true) allUsers.push_back(newUser);
    else {
        cout << "Login wystepuje w bazie, sprobuj z innym loginem";
        Sleep(1000);
    }
}
void Users::showAllUsers() {
    for (int i=0; i < allUsers.size(); i++){
        allUsers[i].showData();
    }
}
void Users::saveToXML(){
    XmlUsersFile file;
    file.saveToXML(allUsers);
}
void Users::loadFromXML(){
    allUsers.clear();
    vector<User> * allUsersPointer = &allUsers;
    XmlUsersFile file;
    file.loadFromXML(allUsersPointer);
}
bool Users::findLogin(string login){
    int index=findLoginIndex(login);
    if (index<0) return false;
    else {
        validLoginIndexNumber=index;
        return true;
    }
}
int Users::findLoginIndex (string login){
    int validUserIndex=-1;
    int i=0;
    bool userFound=false;

    while((i<allUsers.size())&&(userFound==false)){
        if (allUsers[i].getLogin()!=login){
            userFound=false;
        }
        else {
            userFound=true;
            validUserIndex=i;
        }
        i++;
    }
    return validUserIndex;
}
bool Users::verifyPassword (string password){
    if (password==allUsers[validLoginIndexNumber].getPassword()){
        loggedUserID=allUsers[validLoginIndexNumber].getUserID();
        loggedUserName=allUsers[validLoginIndexNumber].getName();
        loggedUserSurname=allUsers[validLoginIndexNumber].getSurname();
        return true;

    }
    else return false;
}
int Users::getLoggedUserID (){
    return loggedUserID;
}
string Users::getLoggedUserName (){
    return loggedUserName;
}
string Users::getLoggedUserSurname (){
    return loggedUserSurname;
}
bool Users::verifyVoidOfVector (){
    if (allUsers.empty()==true) return true;
    else return false;
}
void Users::changePassword (){
    string currentPassword, newPassword;
    cout << "Podaj obecne haslo: ";
    cin >> currentPassword;
    if (currentPassword==allUsers[validLoginIndexNumber].getPassword()){
        cout << "Podaj nowe haslo: ";
        cin >> newPassword;
        allUsers[validLoginIndexNumber].setPassword(newPassword);
        saveToXML();
    }
    else {
        cout << "Niepoprawne haslo!";
        Sleep(1500);
    }
}
