#include "operations.h"

void Operations::addNewOperation (int userId, string date, string item, float ammount)
{
    Operation newOperation;
    newOperation.setUserId(userId);
    newOperation.setItem(item);
    newOperation.setDate(date);
    newOperation.setAmmount(ammount);
    newOperation.separateStringDateToInts(date);
    newOperation.convertIntToTimeStruct(newOperation.getDayInt(), newOperation.getMonthInt(), newOperation.getYearInt());
    newOperation.convertTimeStructToTime_t();
    int lastID;
    int newOperationId;
    if (allOperations.empty()==false)
    {
        lastID=allOperations[allOperations.size()-1].getOperationId();
        newOperationId=lastID+1;
    }
    else
        newOperationId=1;
    newOperation.setOperationId(newOperationId);
    allOperations.push_back(newOperation);
};

void Operations::showAllOperations()
{
    for (int i=0; i<allOperations.size(); i++)
    {
        cout << allOperations[i].getUserId() << " | ";
        cout << allOperations[i].getOperationId() << " | ";
        cout << allOperations[i].getItem() << " | ";
        cout << allOperations[i].getDate()<< " | ";
        cout << allOperations[i].getAmmount() << " | " << endl;
    }
};


void Operations::sortOperations ()
{
    sort(allOperations.begin(),
          allOperations.end(),
          [](Operation & one, Operation & two){return one.getTime () < two.getTime ();});
};
Operations::Operations()
{
};

void Operations::addData (int userId){
    string item, date;
    char choice;
    float ammount;
    cin.sync();
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    cout << "Wpisz dane operacji" <<endl;
    cout << "Czy operacja z data dzisiejsza? t/n" <<endl;
    cin >> choice;
    if (choice=='t') date=getActualDataFromSystem();
    else if (choice=='n'){
        cout << "Wpisz date w formacie dd-mm-rrrr: ";
        cin >> date;
    }
    else cout << "Niepoprawny wybor" << endl;
    cin.sync();
    cout << "Opis operacji: ";
    getline(cin,item);
    cout << "Wartosc operacji: ";
    cin>>ammount;
    addNewOperation(userId, date, item, ammount);
};

string Operations::getActualDataFromSystem (){
    time_t systemTime;
    time (&systemTime);
    struct tm * timeinfo;
    int year, month, day;
    string stringYear, stringMonth, stringDay;

    timeinfo = localtime (&systemTime);
    year=timeinfo->tm_year+1900;
    month=timeinfo->tm_mon+1;
    day=timeinfo->tm_mday;

    stringYear=convertIntToString(year);
    stringMonth=convertIntToString(month);
    stringDay=convertIntToString(day);

    string date=stringDay+"-"+stringMonth+"-"+stringYear;
    return date;
};

string Operations::convertIntToString (int number)
{
    stringstream ss;
    ss << number;
    string numberByString=ss.str();
    return numberByString;
};
float Operations::getSumAllOpers (int userId){
    sumAllOpers=0;
    for (int i=0; i < allOperations.size(); i++){
        if (allOperations[i].getUserId()==userId)
            sumAllOpers+=allOperations[i].getAmmount();
    }
    return sumAllOpers;
};
    float getSumAllOpers ();

int Operations::convertStringToInt (string number)
{
    return stoi (number);
};


void Operations::separateStringDateToInts(string beginningDateByString, string endingDateByString)
{
    beginningDay=convertStringToInt(beginningDateByString.substr(0,2));
    beginningMonth=convertStringToInt(beginningDateByString.substr(3,2));
    beginningYear=convertStringToInt(beginningDateByString.substr(6,4));
    endingDay=convertStringToInt(endingDateByString.substr(0,2));
    endingMonth=convertStringToInt(endingDateByString.substr(3,2));
    endingYear=convertStringToInt(endingDateByString.substr(6,4));
};

void Operations::convertIntToTimeStruct (int begDayInt, int begMonthInt, int begYearInt, int endDayInt, int endMonthInt, int endYearInt){
    time ( &beginningDate );
    beginTimeInfo = localtime ( &beginningDate );
    beginTimeInfo->tm_year = begYearInt - 1900;
    beginTimeInfo->tm_mon = begMonthInt - 1;
    beginTimeInfo->tm_mday = begDayInt;

    time ( &endingDate );
    endTimeInfo = localtime ( &endingDate);
    endTimeInfo->tm_year = endYearInt - 1900;
    endTimeInfo->tm_mon = endMonthInt - 1;
    endTimeInfo->tm_mday = endDayInt;
};

void Operations::convertTimeStructToTime_t (){
    beginningDate = mktime(beginTimeInfo);
    endingDate = mktime(endTimeInfo);
};

void Operations::selectOperationsByDateAndID (string beginingDateString, string endingDateString, int userId){
    separateStringDateToInts(beginingDateString,endingDateString);
    convertIntToTimeStruct(beginningDay, beginningMonth, beginningYear, endingDay, endingMonth, endingYear);
    convertTimeStructToTime_t();

    for (int i=0; i<allOperations.size(); i++)
    {
        if ((allOperations[i].getTime()>=beginningDate) && (allOperations[i].getTime()<=endingDate) && (userId==allOperations[i].getUserId()))
            selectedOperations.push_back(allOperations[i]);
    }
};

void Operations::showSelectedOperations()
{
    for (int i=0; i<selectedOperations.size(); i++)
    {
        cout << selectedOperations[i].getUserId() << " | ";
        cout << selectedOperations[i].getOperationId() << " | ";
        cout << selectedOperations[i].getItem() << " | ";
        cout << selectedOperations[i].getDate()<< " | ";
        cout << selectedOperations[i].getAmmount() << " | " << endl;
    }
};
