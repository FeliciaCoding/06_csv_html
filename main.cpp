#include <iostream>
#include <string>
#include <cstdlib> //EXIT_SUCCESS

#include "fileOperation.h"
#include "csvToHtml.h"

using namespace std;

//  TODO : Function?
void askFilesNames(const string& message) {

    cout << " fichier csv  : ";
    string fileInName;
    getline(cin, fileInName);

    cout << " fichier html  : ";
    string fileOutName;
    getline(cin, fileOutName);

}

int main() {

    const char delimiter = ',';

    // TODO : make a function
    cout << " fichier csv  : ";
    string fileInName;
    getline(cin, fileInName);

    cout << " fichier html  : ";
    string fileOutName;
    getline(cin, fileOutName);

    ifstream fileIn;
    ofstream fileOut;

    openFiles(fileInName, fileOutName, fileIn, fileOut);

    csvToHtml(fileInName, fileOutName, delimiter);

    cout << " End of program. " << endl;

    closeFiles(fileIn, fileOut);

    return EXIT_SUCCESS;
}
