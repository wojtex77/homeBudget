#include "programMessages.h"

using namespace std;

string takeProgramMessage (int errorNumber){
    map <int, string> programMessages;
    programMessages.insert(pair<int,string>(1,"Data za krotka, wymagany format dd-mm-rrrr"));
    programMessages.insert(pair<int,string>(2,"Data nie moze wczesniejsza niz 01-01-2000"));
    programMessages.insert(pair<int,string>(3,"Zly format daty, wymagany dd-mm-rrrr"));
    programMessages.insert(pair<int,string>(4,"Ten rok nie jest rokiem przestepnym, luty ma tylko 28 dni"));
    programMessages.insert(pair<int,string>(5,"Ten miesiac nie jest taki dlugi"));
    programMessages.insert(pair<int,string>(6,"Rok ma tylko 12 miesiecy"));
    programMessages.insert(pair<int,string>(7,"Mozesz podac maksymalnie date do konca biezacego miesiaca"));;
    return programMessages[errorNumber];
}
