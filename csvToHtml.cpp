#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "csvToHtml.h"

using namespace std;

const string START_TAG    = "<";
const string END_TAG      = "</";
const string HTML         = "html>\n";
const string BORDER_NUM   = "1";
const string BORDER_PX    = BORDER_NUM + "px";
const string HEAD         = "head>\n";
const string STYLE        = "style>\n";
const string BODY         = "body>\n";
const string TABLE        = "table>\n";
const string TABLE_ROW    = "tr>\n";
const string TABLE_HEADER = "th>";
const string TABLE_DATA   = "td>\n";


// Assume unknown size for rows and columns
void writeHeaderHtml(ofstream &fileOut) {

    fileOut << START_TAG << HTML
            << START_TAG << HEAD
            << START_TAG << STYLE
            << "table, th, td {\n"
            << "border: " << BORDER_PX << " solid black;\n"
            << "border-collapse: collapse;\n"
            << "}\n"
            << END_TAG << STYLE
            << END_TAG << HEAD;

}


void writeBodyHtml(ifstream &fileIn, ofstream &fileOut, const char &delimiter) {

    fileOut << START_TAG << BODY
            << "<table border =" << BORDER_NUM << ">\n";

    string oneLine;
    int    lineCounter = 1;
    while (getline(fileIn, oneLine)) {

        stringstream stringStream(oneLine);
        string       rowType;
        string       cell;

        fileOut << START_TAG << TABLE_ROW;

        while (getline(stringStream, cell, delimiter)) {
            if (lineCounter == 1) {
                rowType = TABLE_HEADER;
            } else {
                rowType = TABLE_DATA;
            }

            fileOut << left << "\t" << START_TAG << rowType
                    << cell
                    << END_TAG << rowType << endl;

        }

        ++lineCounter;

    }

    fileOut << END_TAG << TABLE_ROW;

}


void writeFooterHtml(ostream &fileOut) {

    fileOut << END_TAG << TABLE
            << END_TAG << BODY
            << END_TAG << HTML;

}


void convertCsvToHtml(const string &fileInName, const string &fileOutName, const char &delimiter) {

    ifstream fileIn(fileInName);
    ofstream fileOut(fileOutName, ios::app);

    writeHeaderHtml(fileOut);

    writeBodyHtml(fileIn, fileOut, delimiter);

    writeFooterHtml(fileOut);

}