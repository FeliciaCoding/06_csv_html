#include <iostream>
#include <string>
#include <cstdlib> //EXIT_SUCCESS

#include "fileOperation.h"
#include "csvToHtml.h"

using namespace std;


int main() {

    const char delimiter = ',';

    // TODO : restart program
    string fileInName = askFileName("CSV file  : ");
    string fileOutName = askFileName("HTML file : ");

    ifstream fileIn;
    ofstream fileOut;

    openFiles(fileInName, fileOutName, fileIn, fileOut);

    csvToHtml(fileInName, fileOutName, delimiter);

    cout << " End of program. " << endl;

    closeFiles(fileIn, fileOut);

    return EXIT_SUCCESS;
}
