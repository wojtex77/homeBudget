#include "operations.h"

void Operations::addNewOperation (int userId, string date, string item, float ammount)
{
//    int userId;
//    string item, date;
//    float ammount;
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
