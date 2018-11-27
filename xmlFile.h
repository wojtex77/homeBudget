#include <iostream>
#include "Markup.h"

using namespace std;

class xmlFile {
private:
    string filename;

public:
    int convertStringToInt (string data);
    void setFilename(string name);
    string getFilename ();
};
