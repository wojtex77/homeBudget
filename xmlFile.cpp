#include "xmlFile.h"
#include <stdlib.h>
#include <string>


int xmlFile::convertStringToInt (string data){
    return atoi(data.c_str());
}

void xmlFile::setFilename(string name){
    filename=name;
};
string xmlFile::getFilename (){
    return filename;
};
