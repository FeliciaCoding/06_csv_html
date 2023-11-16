#include <iostream>
#include <string>
#include <fstream> //ifstream, ofstream
#include <cstdlib> // EXIT_SUCCESS
#include <sstream> //stringstream


using namespace std;

//// TODO : cvsToHTML.h + ,cpp

bool readFile(const string &fileName) {

    ifstream fileIn(fileName);

    if (!fileIn) {
        cerr << "Errors during opening the file: " << fileName;
        return false;
    }

    while (fileIn) {
        string oneLine;
        getline(fileIn, oneLine);
        stringstream stringStream(oneLine);
        string       word;


        cout << oneLine << endl;
    }

    fileIn.close();
}


// Write the Header -> Assume unknown size for row and col
string writeHeaderHtml(const string &fileName, const char deliminator) {

    const string START_TAG = "<";
    const string END_TAG   = "</";
    const string HTML      = "html>\n";
    const string HEAD      = "head>\n";
    const string STYLE     = "style>\n";

    ofstream fileOut(fileName);

    fileOut << START_TAG << HTML
            << START_TAG << HEAD
            << START_TAG << STYLE
            << "\ttable, th, td {\n"
            << "\t\tborder: 1px solid black;\n"
            << "\t\tborder-collapse: collapse;\n"
            << "}\n"
            << END_TAG << STYLE
            << END_TAG << HEAD;

}


// TODO : Write body -> HTML in the form of a table
bool writeFile(const string &fileName) {

    ofstream fileOut(fileName);

    string oneLine;

    if (!fileOut) {
        cerr << "Errors during opening the file: " << fileName;
        return false;
    }

    while (getline(cin, oneLine)) {
        fileOut << oneLine << endl;
    }

    fileOut.close();
    return true;
}




// Write the footer

string writeFooterHtml(const string &fileName) {

    const string END_TAG = "</"; // repeated
    const string TABLE   = "html>\n";
    const string BODY    = "body>\n";
    const string HTML    = "html>\n"; // repeated


    ofstream fileOut(fileName);

    fileOut << END_TAG << TABLE
            << END_TAG << BODY
            << END_TAG << HTML;

}


int main() {

    //const string FILE_CSV = "csv";
    //const string FILE_HTML = ".html";

    // TODO : make a function:  askingFileName (const string& filename)
    cout << " fichier csv  : ";
    string fileNameCsv;
    getline(cin, fileNameCsv);

    // TODO : Read data from csv. file (diliminator: coma )
    readFile(fileNameCsv);

    //  TODO : Think about how to make it better -> Ask ing the name of .csv : cities.csv => cities.html
    cout << " fichier html  : ";
    string fileNameHtml;
    getline(cin, fileNameHtml);

    ifstream fileIn(fileNameHtml);

    if (!fileIn) {
        cerr << "Errors during opening the file : " << fileNameHtml;
        return EXIT_FAILURE;
    }


    auto backup = cin.rdbuf();
    cin.rdbuf(fileIn.rdbuf());

    //// TODO :  write HTML file -> translator from .cvs to html

    cin.rdbuf(backup);
    fileIn.clear();


    return EXIT_SUCCESS;
}
