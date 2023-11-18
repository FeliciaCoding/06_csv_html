#include <iostream>
#include <string>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //EXIT_SUCCESS
#include <sstream> //stringstream

#include "fileOperation.h"
#include "csvToHtml.h"

using namespace std;

//  TODO : Function?
//void askCsvFileName(const string& message){
//
//    cout << " fichier csv  : ";
//    string fileNameCsv;
//    getline(cin, fileNameCsv);
//
//    //  TODO : Think about how to make it better -> Ask the name of .csv : cities.csv => cities.html
//    cout << " fichier html  : ";
//    static string fileNameHtml = fileNameCsv.erase(fileNameCsv.length()-4) + ".html";
//    getline(cin, fileNameHtml);
//
//}


int main() {

    //const string FILE_CSV = "csv";
    //const string FILE_HTML = ".html";
    //const string MESSAGE_CVS = " fichier csv  : ";
    //const string MESSAGE_HTML = " fichier html  : ";
    const char delimiter = ',';

    // TODO : make a function
    cout << " fichier csv  : ";
    string fileInName;
    getline(cin, fileInName);

    //  TODO : Think about how to make it better -> Ask ing the name of .csv : cities.csv => cities.html
    cout << " fichier html  : ";
    //string fileNameHtml = (fileInName.erase(fileInName.length() - 4) + ".html");
    string fileOutName; // = fileNameHtml;
    getline(cin, fileOutName);

//    ifstream fileIn(fileInName);
//    ofstream fileOut(fileOutName, ios::app);
    ifstream fileIn;
    ofstream fileOut;

    openFiles(fileInName, fileOutName, fileIn, fileOut);

    csvToHtml(fileInName, fileOutName, delimiter);

    cout << " End of program. " << endl;

    closeFiles(fileIn, fileOut);

    return EXIT_SUCCESS;
}
