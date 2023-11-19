#ifndef INC_06_CSV_HTML_CSVTOHTML_H
#define INC_06_CSV_HTML_CSVTOHTML_H

#include <string>
#include <fstream>

extern const std::string START_TAG;
extern const std::string END_TAG;
extern const std::string HTML;
extern const std::string BORDER_NUM;

void writeHeaderHtml(std::ofstream &fileOut);

void writeBodyHtml(std::ifstream &fileIn, std::ofstream &fileOut, const char &delimiter);

void writeFooterHtml(std::ostream &fileOut);

void csvToHtml(const std::string &fileInName, const std::string &fileOutName, const char &delimiter);

#endif //INC_06_CSV_HTML_CSVTOHTML_H
