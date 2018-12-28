#include <string>

int checkDateFormat (string date){
    if (date.length()!=10) return 1;

    string day=date.substr(0,2);
    string month=date.substr(3,2);
    string year=date.substr(6,4);
    int dayInt, monthInt, yearInt;
    dayInt = stoi(day);
    monthInt = stoi(month);
    yearInt = stoi (year);
    if (yearInt<2000) return 2;


    return 0;
}
