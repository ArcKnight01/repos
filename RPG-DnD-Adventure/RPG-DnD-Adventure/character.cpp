#include "character.h"
using namespace std;

character::character() : character::character("Default Name", "Default Description", "Neutral") {

};

character::character(string enteredName, string enteredDescription, string enteredAlignment)
{
    name = enteredName;
    description = enteredDescription;
    alignment = enteredAlignment;
}
void character::describe()
{
    cout << name << " apears to be a " << description << "." << endl;
}
