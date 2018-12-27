#include <iostream>
#include "Markup.h"
#pragma once

using namespace std;

class xmlFile {
private:

public:
    string filename;
    int convertStringToInt (string data);
    float convertStringToFloat (string data);
    void setFilename(string name);
    string getFilename ();
};
