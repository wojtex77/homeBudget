#include <vector>
#include "xmlUsersFile.h"

using namespace std;

class Users {
private:
    vector <User> allUsers;
    bool verifyUniqueLogin (User &newUser);
    int findLoginIndex (string login);
    int validLoginIndexNumber, loggedUserID;
    string loggedUserName, loggedUserSurname;
public:
    void createNewUser();
    void saveToXML ();
    void loadFromXML ();
    bool verifyVoidOfVector ();
    void showAllUsers ();
    bool findLogin (string login);
    bool verifyPassword (string password);
    int getLoggedUserID ();
    string getLoggedUserName ();
    string getLoggedUserSurname ();
    void changePassword ();
};

