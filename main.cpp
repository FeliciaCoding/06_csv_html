#include <iostream>
#include <string>
#include <fstream> //ifstream, ofstream
#include <cstdlib> // EXIT_SUCCESS
#include <sstream> //stringstream


using namespace std;

//// TODO : cvsToHTML.h + ,cpp

// Assume unknown size for row and col
string writeHeaderHtml(const string &fileName) {

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

//// reading each line from the CSV file,
/// splitting it into cells based on the ',' delimiter,
/// and then writing these cells into an HTML table row (<tr>).

// TODO : Write body -> HTML in the form of a table
bool writeFile(const string &fileInName, const string &fileOutName, const char &delimiter) {

    ifstream fileIn(fileInName);
    ofstream fileOut(fileOutName);

    //// TODO :  Repeated -> Make a function for it ?
    if (!fileIn) {
        cerr << "Errors during opening the file: " << fileInName;
        return false;
    }

    if (!fileOut) {
        cerr << "Errors during opening the file: " << fileOutName;
        return false;
    }

    writeHeaderHtml(fileOutName);

    // TODO : Read the first line, split with delimiter, adding HTML table header tags

    // TODO : create writeCell function
    string oneLine;
    while (getline(fileIn, oneLine)) {
        stringstream extractString(oneLine);
        string       cell;
        // TODO : ADD HTML cell start tags
        while (getline(extractString, cell, delimiter)) {
            fileOut << cell << endl;
        }
        //  TODO : ADD HTML cell end tags
    }

    fileIn.close();
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

    //  TODO : Think about how to make it better -> Ask ing the name of .csv : cities.csv => cities.html
    cout << " fichier html  : ";
    string fileNameHtml;
    getline(cin, fileNameHtml);


    ifstream fileIn(fileNameHtml);

    if (!fileIn) {
        cerr << "Errors during opening the file : " << fileNameHtml;
        return EXIT_FAILURE;
    }


    return EXIT_SUCCESS;
}
