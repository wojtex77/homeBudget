using namespace std;

class User {
private:
    int userID;
    string name, surname, login, password;
    int ASCIItoInt (char letter);
    char intToASCII (int number);
    void capitalizeString (string &text);
public:
    User ();
    void addData ();
    void showData ();
    void setUserID(int ID);
    void setName(string userName);
    void setSurname(string userSurname);
    void setLogin(string userLogin);
    void setPassword(string userPassword);
    int getUserID ();
    string getName ();
    string getSurname ();
    string getLogin ();
    string getPassword ();
};
