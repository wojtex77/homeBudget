#include <iostream>
#include "operation.h"
#include "Markup.h"
#include "xmlFile.h"
#include <vector>


using namespace std;

class xmlOperationsFile :public xmlFile {
public:
    void saveToXML (vector <Operation> &allOperations);
    void loadFromXML (vector <Operation> *allOperations);
};
