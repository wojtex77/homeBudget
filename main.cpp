#include <iostream>
#include <windows.h>
#include "users.h"
#include "operations.h"

using namespace std;
void showProgramMenu (int loggedUserID, string UserName, string UserSurname){
    system("cls");
    cout << "Witaj "<< UserName << " " << UserSurname << endl;
    cout << "W czym moge pomoc?" << endl << endl;
    cout << "1. Dodaj przychod"<<endl;
    cout << "2. Dodaj wydatek"<<endl;
    cout << "3. Bilans biezacego miesiaca"<<endl;
    cout << "4. Bilans poprzedniego miesiaca"<<endl;
    cout << "5. Bilans wybranego okresu"<<endl;
    cout << "9. Zmien haslo"<<endl;
    cout << "0. Wyloguj"<<endl;
    cout << endl << "Twoj wybor (potwierdz enterem): ";
}

void showLoginMenu () {
    system("cls");
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    cout << "1. Logowanie"<<endl;
    cout << "2. Rejestracja"<<endl;
    cout << "0. Zakoncz"<<endl;
    cout << endl << "Twoj wybor (potwierdz enterem): ";
}

void changePassword (Users &appUsers) {
    appUsers.changePassword();
}

void programMenu (int loggedUserID, string UserName, string UserSurname, Users &appUsers){
    char choice='0';
    Operations incomes, expenses;
    do {
        showProgramMenu(loggedUserID, UserName, UserSurname);
        cin >> choice;

        switch(choice) {
        case '1': {
            incomes.addData(loggedUserID);
            break;
        }
        case '2': {
            expenses.addData(loggedUserID);
            break;
        }
        case '8': {
            cout <<endl<< "Suma wszystkich wydatkow wynosi " << expenses.getSumAllOpers(loggedUserID) << " zlotych"<<endl;
            system("pause");
            break;
        }
        case '9': {
            changePassword(appUsers);
            break;
        }
        case '0': {
            break;
        }
        default: {
            cout << "Niepoprawny wybor!";
            Sleep(1500);
        }
        }
    } while (choice!='0');
}

void logIn (Users &appUsers) {
    system("cls");
    string login, password;
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    appUsers.loadFromXML();
    if (appUsers.verifyVoidOfVector()==false) {
        cout << "Login: ";
        cin >> login;
        if (appUsers.findLogin(login)==true) {
            cout << "Haslo: ";
            cin >> password;
            if (appUsers.verifyPassword(password)==true)programMenu(appUsers.getLoggedUserID(),appUsers.getLoggedUserName(),appUsers.getLoggedUserSurname(), appUsers);
            else {
                cout << "Haslo niezgodne";
                Sleep(2000);
            }

        } else {
            cout << "Nie znaleziono podanego loginu w bazie";
            Sleep(2000);
        }}
    else{
        cout << "Zarejestruj najpierw nowych uzytkownikow";
        Sleep(2000);
    }
}

void registerNewUser (Users &appUsers) {
    system("cls");
    appUsers.loadFromXML();
    appUsers.createNewUser();
    appUsers.saveToXML();
}

void loginMenu (Users &appUsers) {

    char choice=0;
    do {
        showLoginMenu();
        cin >> choice;

        switch(choice) {
        case '1': {
            logIn(appUsers);
            break;
        }
        case '2': {
            registerNewUser(appUsers);
            break;
        }
        case '0': {
            cout << endl << "Do widzenia";
            Sleep(1500);
            break;
        }
        default: {
            cout << "Niepoprawny wybor!";
            Sleep(1500);
        }
        }
    } while (choice!='0');
}

int main() {
    Users appUsers;
    loginMenu(appUsers);
    return 0;
}
