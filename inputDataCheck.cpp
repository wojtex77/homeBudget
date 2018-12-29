#include "inputDataCheck.h"


int getActualMonth (){
    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;

return actualDate->tm_mon+1;
}
int getActualYear (){
    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;

return actualDate->tm_year+1900;
}

int checkDate(string date){
    map <int,int> monthsLength;
    monthsLength[1]=31;
    monthsLength[2]=28;
    monthsLength[3]=31;
    monthsLength[4]=30;
    monthsLength[5]=31;
    monthsLength[6]=30;
    monthsLength[7]=31;
    monthsLength[8]=31;
    monthsLength[9]=30;
    monthsLength[10]=31;
    monthsLength[11]=30;
    monthsLength[12]=31;

    if (date.length()!=10) return 1; //<-- warunek dlugosci ciagu daty
    if ((date[2]!='-') || (date[5]!='-')) return 3; //<--warunek wprowadzoengo separatora '-'

    string day=date.substr(0,2);
    string month=date.substr(3,2);
    string year=date.substr(6,4);
    int dayInt, monthInt, yearInt;
    dayInt = stoi(day);
    monthInt = stoi(month);
    yearInt = stoi (year);

    if (yearInt<2000) return 2; //<-- warunek rok nie wczesniejszy niz 2000
    //warunek na rok przestepny
    if (yearInt%4>0){
        if (monthInt==2)
            if(dayInt==29) return 4;
    }

    if (dayInt>monthsLength[monthInt]) return 5;
    if (monthInt>12) return 6;
    int actualMonth=getActualMonth();
    int actualYear=getActualYear();
    if (yearInt==actualYear){
            if (monthInt>actualMonth) return 7;
    };
    if (yearInt>actualYear) return 7;

    return 0;
}

string getCurrentMonthBeginingDate (){
    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;
    actualDate->tm_mday = 1;

    string textDate, day, month, year;
    year=to_string(actualDate->tm_year+1900);
    month=to_string(actualDate->tm_mon+1);
    day="01";
    textDate=day+"-"+month+"-"+year;
    return textDate;
};
string getCurrentMonthEndingDate (){
map <int,int> monthsLength;
    monthsLength[1]=31;
    monthsLength[2]=28;
    monthsLength[3]=31;
    monthsLength[4]=30;
    monthsLength[5]=31;
    monthsLength[6]=30;
    monthsLength[7]=31;
    monthsLength[8]=31;
    monthsLength[9]=30;
    monthsLength[10]=31;
    monthsLength[11]=30;
    monthsLength[12]=31;
    monthsLength[13]=29; //luty rok przestepny


    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;
    if ((actualDate->tm_year%4==0)&&(actualDate->tm_mon==1)) actualDate->tm_mday = monthsLength[13];
    else actualDate->tm_mday = monthsLength[actualDate->tm_mon+1];


    string textDate, day, month, year;
    year=to_string(actualDate->tm_year+1900);
    month=to_string(actualDate->tm_mon+1);
    day=to_string(actualDate->tm_mday);
    textDate=day+"-"+month+"-"+year;
    return textDate;
};
string getPastMonthBeginingDate (){
    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;
    actualDate->tm_mday = 1;

    string textDate, day, month, year;
    if (actualDate->tm_mon==0){
        actualDate->tm_mon=11;
        actualDate->tm_year--;
    }
    year=to_string(actualDate->tm_year+1900);
    month=to_string(actualDate->tm_mon);
    day="01";
    textDate=day+"-"+month+"-"+year;
    return textDate;
};
string getPastMonthEndingDate (){
map <int,int> monthsLength;
    monthsLength[1]=31;
    monthsLength[2]=28;
    monthsLength[3]=31;
    monthsLength[4]=30;
    monthsLength[5]=31;
    monthsLength[6]=30;
    monthsLength[7]=31;
    monthsLength[8]=31;
    monthsLength[9]=30;
    monthsLength[10]=31;
    monthsLength[11]=30;
    monthsLength[12]=31;
    monthsLength[13]=29; //luty rok przestepny


    time_t timer;
    struct tm *actualDate;

    time (&timer);
    actualDate = localtime (&timer);
    actualDate->tm_hour = 5;   actualDate->tm_min = 5; actualDate->tm_sec = 5;
    if ((actualDate->tm_year%4==0)&&(actualDate->tm_mon==1)) actualDate->tm_mday = monthsLength[13];
    else actualDate->tm_mday = monthsLength[actualDate->tm_mon+1];


    string textDate, day, month, year;
    if (actualDate->tm_mon==0){
        actualDate->tm_mon=11;
        actualDate->tm_year--;
    }

    year=to_string(actualDate->tm_year+1900);
    month=to_string(actualDate->tm_mon);
    day=to_string(actualDate->tm_mday);
    textDate=day+"-"+month+"-"+year;
    return textDate;
};


float lookForCommaAndChangeToDot (string ammountByString){
    int stringLength=ammountByString.length();
    for (int i=0; i<stringLength; i++){
        if (ammountByString[i]==',') ammountByString[i]='.';
    }
    return stof(ammountByString);
};
