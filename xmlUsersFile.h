#include <iostream>
#include "user.h"
#include "Markup.h"
#include "xmlFile.h"
#include <vector>


using namespace std;

class XmlUsersFile :public xmlFile {
public:
    void saveToXML (vector <User> &allUsers);
    void loadFromXML (vector <User> *allUsers);
};
