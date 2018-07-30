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

void User::capitalizeString (string &text)
{
    bool cap = true;

    for(unsigned int i = 0; i <= text.length(); i++)
    {
        if (isalpha(text[i]) && cap == true)
        {
            text[i] = toupper(text[i]);
            cap = false;
        }
        else if (isspace(text[i]))
        {
            cap = true;
        }
    }
}

void User::addData () {
    cin.sync();
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    cout << "Wpisz swoje dane" <<endl;
    cout << "Imie: ";
    getline(cin,name);
    capitalizeString(name);
    cout << "Nazwisko: ";
    getline(cin,surname);
    capitalizeString(surname);
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


int User::ASCIItoInt (char letter){
    return int(letter);
}

char User::intToASCII (int number){
    char W = static_cast<char>(number);
    return W;
}

