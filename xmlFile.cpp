#include "xmlFile.h"
#include <stdlib.h>
#include <string>


int xmlFile::convertStringToInt (string data){
    return atoi(data.c_str());
}

string xmlFile::IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
