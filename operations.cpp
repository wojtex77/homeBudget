#include "operations.h"

void Operations::addNewOperation (int userId, string item, string date, float ammount)
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
