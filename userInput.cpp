#include <iostream>
#include <cctype> // toupper()
#include <limits> // numeric_limits<type>
#include "userInput.h"

using namespace std;

string askFileName(const string &message) {

    cout << message;
    string fileName;
    getline(cin, fileName);
    return fileName;
}


char getUserChoice(const string &message, const char &choice1, const char &choice2) {

    char userChoice;
    do {
        cout << message;
        cin >> userChoice;

        // Assume restart program accepts both lowercase & uppercase (Case-insensitive)
        if (islower(userChoice)) {
            userChoice = (char) toupper(userChoice);
        }

        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


    } while (userChoice != choice1 && userChoice != choice2);

    return userChoice;

}
