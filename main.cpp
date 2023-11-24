#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "IOFileConsole.h"
#include "csvToHtml.h"


using namespace std;


int main() {

    // #4 in all caps when constants
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

      // #6 use positiveChoice and negativeChoice in string
        restartChoice = getUserChoice("Would you like to restart the program [Y/N] ?: ", positiveChoice,
                                      negativeChoice);

        // should not be in the main loop
        if (restartChoice == negativeChoice) {
            cout << "End of program." << endl;
        }

    } while (restartChoice == positiveChoice);

    // should be here
    // cout << "End of program." << endl;
    return EXIT_SUCCESS;
}
