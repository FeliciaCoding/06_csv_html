#ifndef INC_06_CSV_HTML_CSVTOHTML_H
#define INC_06_CSV_HTML_CSVTOHTML_H

#include <string>
#include <fstream>

void writeHeaderHtml(std::ofstream &fileOut);

void writeBodyHtml(std::ifstream &fileIn, std::ofstream &fileOut, const char &delimiter);

void writeFooterHtml(std::ostream &fileOut);

void convertCsvToHtml(const std::string &fileInName, const std::string &fileOutName, const char &delimiter);

#endif //INC_06_CSV_HTML_CSVTOHTML_H
