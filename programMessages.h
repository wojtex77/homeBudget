#include <string>
#include <map>

using namespace std;
string takeProgramMessage (int errorNumber)
{
    map <int, string> programMessages;
    programMessages.insert(pair<int,string>(1,"Data za krotka, wymagany format dd-mm-rrrr"));
    programMessages.insert(pair<int,string>(2,"Data nie moze wczesniejsza niz 01-01-2000"));
    return programMessages[errorNumber];
}
