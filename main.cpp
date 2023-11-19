#include <iostream>
#include <string>
#include <cstdlib>
#include "fileOperation.h"
#include "csvToHtml.h"
#include "userInput.h"

using namespace std;


int main() {

    const char delimiter      = ',';
    const char positiveChoice = 'Y';
    const char negativeChoice = 'N';

    ifstream fileIn;
    ofstream fileOut;

    char restartChoice;
    do {

        string fileInName  = askFileName("CSV file  : ");
        string fileOutName = askFileName("HTML file : ");

        openFiles(fileInName, fileOutName, fileIn, fileOut);

        convertCsvToHtml(fileInName, fileOutName, delimiter);

        closeFiles(fileIn, fileOut);

        restartChoice = getUserChoice("Would you like to restart the program [Y/N] ?: ", positiveChoice,
                                      negativeChoice);

        if (restartChoice == negativeChoice) {
            cout << "End of program." << endl;
        }

    } while (restartChoice == positiveChoice);


    return EXIT_SUCCESS;
}
