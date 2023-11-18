#include <string>
#include <iostream>
#include <sstream>
#include "csvToHtml.h"


using namespace std;

const string START_TAG  = "<";
const string END_TAG    = "</";
const string HTML       = "html>\n";
const string BORDER_NUM = "1";


// Assume unknown size for row and columns
void writeHeaderHtml(const string &fileInName, const string &fileOutName) {

    const string HEAD      = "head>\n";
    const string STYLE     = "style>\n";
    const string BORDER_PX = BORDER_NUM + "px";

    ifstream fileIn(fileInName);
    ofstream fileOut(fileOutName, ios::app);

    fileOut << START_TAG << HTML
            << START_TAG << HEAD
            << START_TAG << STYLE
            << "\ttable, th, td {\n"
            << "\t\tborder: " << BORDER_PX << " solid black;\n"
            << "\t\tborder-collapse: collapse;\n"
            << "}\n"
            << END_TAG << STYLE
            << END_TAG << HEAD;

    //closeFiles(fileIn, fileOut);
}


void writeFooterHtml(const string &fileInName, const string &fileOutName) {

    const string TABLE = "table>\n";
    const string BODY  = "body>\n";

    ifstream fileIn(fileInName);
    ofstream fileOut(fileOutName, ios::app);

    fileOut << END_TAG << TABLE
            << END_TAG << BODY
            << END_TAG << HTML;

    //closeFiles(fileIn, fileOut); //// is it a good practice to close the file right after writing?
}


void csvToHtml(const string &fileInName, const string &fileOutName, const char &delimiter) {

    ifstream fileIn(fileInName);
    ofstream fileOut(fileOutName, ios::app);

    writeHeaderHtml(fileInName, fileOutName);

    const string BODY = "body>\n";

    fileOut << START_TAG << BODY
            << "<table border =" << BORDER_NUM << ">\n";

    // TODO : A fonction for columnHeader / TABLE_DATA
    //  TODO : left
    const string TABLE_ROW    = "tr>\n";
    const string TABLE_HEADER = "th>";

    string firstLine;


    while (getline(fileIn, firstLine)) {
        stringstream stringStream1(firstLine);
        string       columnHeader;

        fileOut << START_TAG << TABLE_ROW;
        while (getline(stringStream1, columnHeader, delimiter)) {

            fileOut << "\t" << START_TAG << TABLE_HEADER
                    << columnHeader
                    << END_TAG << TABLE_HEADER << endl;

        }
        fileOut << END_TAG << TABLE_ROW;
        break;
    }



    const string TABLE_DATA = "td>\n";

    string oneLine;

    while (getline(fileIn, oneLine)) {

        stringstream stringStream2(oneLine);
        string       cell;

        fileOut << START_TAG << TABLE_ROW;
        while (getline(stringStream2, cell, delimiter)) {
            fileOut << "\t" << START_TAG << TABLE_DATA
                    << cell
                    << END_TAG << TABLE_DATA << endl;
        }
        fileOut << END_TAG << TABLE_ROW;
    }

    writeFooterHtml(fileInName, fileOutName);

}