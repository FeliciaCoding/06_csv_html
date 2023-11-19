#include <string>
#include <iostream>
#include <fstream>
#include <cctype> // toupper()
#include <limits> // numeric_limits<type>
#include "IOFileConsole.h"

using namespace std;


bool openFiles(const string &fileInName, const string &fileOutName, ifstream &fileIn,
               ofstream &fileOut) {

    fileIn.open(fileInName);
    if (!fileIn.is_open()) {
        cerr << "Unable to open '" << fileInName << "'\n";
        return false;
    }

    fileOut.open(fileOutName);
    if (!fileOut.is_open()) {
        cerr << "Unable to open '" << fileOutName << "'\n";
        fileIn.close();
        return false;
    }

    return true;
}

void closeFiles(ifstream &fileIn, ofstream &fileOut) {
    fileIn.close();
    fileOut.close();
}


void handleInputError(istream &input) {
    if (input.fail()) {
        input.clear();
        input.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


string askFileName(const string &message) {

    cout << message;
    string fileName;
    getline(cin, fileName);
    handleInputError(cin);
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

        handleInputError(cin);

    } while (userChoice != choice1 && userChoice != choice2);

    return userChoice;

}
