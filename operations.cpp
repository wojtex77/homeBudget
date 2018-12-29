#include "operations.h"


void Operations::addNewOperation (int userId, string date, string item, float ammount){
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
void Operations::showAllOperationsByUser (int loggedUserID){
    for (int i=0; i<allOperations.size(); i++)
    {
        if (allOperations[i].getUserId()==loggedUserID){
            cout << allOperations[i].getDate()<< " | ";
            cout << allOperations[i].getAmmount() << " PLN | ";
            cout << allOperations[i].getItem() <<endl;
        }
    }
};
void Operations::sortOperations (){
    sort(allOperations.begin(),
          allOperations.end(),
          [](Operation & one, Operation & two){return one.getTime () < two.getTime ();});
};
Operations::Operations(string operationName){
    setTypename(operationName);
    loadFromXML(filename);
};
void Operations::addData (int userId){
    string item, date;
    char choice;
    float ammount;
    cin.sync();
    cout << "------Twoj Budzet Domowy------"<<endl<<endl;
    cout << "Wpisz dane operacji" <<endl;
    cout << "Czy operacja z data dzisiejsza? t/n" <<endl;
    do {
        cin >> choice;
        if (choice=='t') date=getActualDataFromSystem();
        else if (choice=='n'){
            cout << "Wpisz date w formacie dd-mm-rrrr: ";
            do {
                int error;
                cin >> date;
                error=checkDate(date);
                if (error!=0) cout << takeProgramMessage(error)<< endl <<"Podaj date jeszcze raz: ";
            } while (checkDate(date)!=0);

        }
        else cout << "Niepoprawny wybor, wpisz ""t"" lub ""n"""<< endl;
    } while (choice!='t' && choice!='n');
    cin.sync();
    cout << "Opis operacji: ";
    getline(cin,item);
    cout << "Wartosc operacji: ";
    cin>>ammount;
    addNewOperation(userId, date, item, ammount);
    saveToXML(filename);
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
string Operations::convertIntToString (int number){
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
float Operations::getSumSelectedOperations(int userID){
    sumSelectedOpers=0;
    for (int i=0; i < selectedOperations.size(); i++){
        if (selectedOperations[i].getUserId()==userID)
            sumSelectedOpers+=selectedOperations[i].getAmmount();
    }
    return sumSelectedOpers;
};
int Operations::convertStringToInt (string number){
    return stoi (number);
};
void Operations::separateStringDateToInts(string beginningDateByString, string endingDateByString){
    beginningDay=convertStringToInt(beginningDateByString.substr(0,2));
    beginningMonth=convertStringToInt(beginningDateByString.substr(3,2));
    beginningYear=convertStringToInt(beginningDateByString.substr(6,4));
    endingDay=convertStringToInt(endingDateByString.substr(0,2));
    endingMonth=convertStringToInt(endingDateByString.substr(3,2));
    endingYear=convertStringToInt(endingDateByString.substr(6,4));
};
void Operations::convertIntToTime_t (int begDayInt, int begMonthInt, int begYearInt, int endDayInt, int endMonthInt, int endYearInt){
    time ( &beginningDate );
    time ( &endingDate );
    endTimeInfo = localtime ( &endingDate);
    beginTimeInfo = localtime ( &beginningDate );

    beginTimeInfo->tm_year = begYearInt - 1900;
    beginTimeInfo->tm_mon = begMonthInt - 1;
    beginTimeInfo->tm_mday = begDayInt;

    beginTimeInfo->tm_sec = 5; // <- added to have always same hour, minutes and seconds for selecting operations by date
    beginTimeInfo->tm_min = 5;
    beginTimeInfo->tm_hour = 5;

    beginningDate = mktime(beginTimeInfo);

    endTimeInfo->tm_year = endYearInt - 1900;
    endTimeInfo->tm_mon = endMonthInt - 1;
    endTimeInfo->tm_mday = endDayInt;

    endTimeInfo->tm_sec = 5; // <- added to have always same hour, minutes and seconds for selecting operations by date
    endTimeInfo->tm_min = 5;
    endTimeInfo->tm_hour = 5;

    endingDate = mktime(endTimeInfo);
};
void Operations::setTypename (string name){
    filename=name;
};
void Operations::selectOperationsByDateAndID (string beginingDateString, string endingDateString, int userId){
    selectedOperations.clear();
    separateStringDateToInts(beginingDateString,endingDateString);
    convertIntToTime_t(beginningDay, beginningMonth, beginningYear, endingDay, endingMonth, endingYear);

    for (int i=0; i<allOperations.size(); i++)
    {
        unsigned long long int timeFromVector=allOperations[i].getTime();
        int idFromVector=allOperations[i].getUserId();
        if ((timeFromVector>=beginningDate) && (timeFromVector<=endingDate) && (userId==idFromVector))
            selectedOperations.push_back(allOperations[i]);
    }
};
void Operations::showSelectedOperations(){
    for (int i=0; i<selectedOperations.size(); i++)
    {
        cout << selectedOperations[i].getDate()<< " | ";
        cout << selectedOperations[i].getAmmount() << " PLN | ";
        cout << selectedOperations[i].getItem() <<endl;    }
};
void Operations::saveToXML (string filename){
    xmlOperationsFile file (filename);
    file.saveToXML(allOperations);
};
void Operations::loadFromXML (string filename){
    xmlOperationsFile file (filename);
    allOperations.clear();
    vector<Operation> * allOperationsPointer = &allOperations;
    file.loadFromXML(allOperationsPointer);
};
