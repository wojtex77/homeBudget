#include <iostream>
#include "operation.h"
#include "Markup.h"
#include "xmlFile.h"
#include <vector>


using namespace std;

class xmlOperationFile :public xmlFile {
    string filename;
    int returnYearFromString (string fullDate);
    int returnMonthFromString (string fullDate);
    int returnDayFromString (string fullDate);
public:
    void saveToXML (vector <operation> &allOperations);
    void loadFromXML (vector <operation> *allOperations);
    void setFilename (string file);
    string getFilename ();

    xmlOperationFile (string fileName);
};
