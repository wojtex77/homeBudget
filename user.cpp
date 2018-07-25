#include <iostream>
#include "user.h"

using namespace std;

User::User () {
    name="";
    surname="";
    login="";
    password="";
    userID=0;
}
void User::addData () {
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    cout << "Wpisz swoje dane" <<endl;
    cout << "Imie: ";
    cin >> name;
    changeFirstLetterToCapital(name);
    cout << "Nazwisko: ";
    cin >> surname;
    changeFirstLetterToCapital(surname);
    cout << "Login: ";
    cin >> login;
    cout << "Haslo: ";
    cin >> password;
}
void User::showData () {
    cout << userID << ". " << name << " " << surname << endl;
    cout << login << " / " << password << endl;
}

void User::setUserID(int ID){
    userID=ID;
}
void User::setName(string userName){
    name=userName;
}
void User::setSurname(string userSurname){
    surname=userSurname;
}
void User::setLogin(string userLogin){
    login=userLogin;
}
void User::setPassword(string userPassword){
    password=userPassword;
}

int User::getUserID () {
    return userID;
}
string User::getName() {
    return name;
}
string User::getSurname() {
    return surname;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}

void User::changeFirstLetterToCapital (string &text){
    char firstLetter=text[0];
    int ASCIIvalue=ASCIItoInt(firstLetter);
    if (ASCIIvalue<65){
        text[0]=intToASCII(ASCIIvalue+23);
    }
}

int User::ASCIItoInt (char letter){
    return int(letter);
}

char User::intToASCII (int number){
    char W = static_cast<char>(number);
    return W;
}

