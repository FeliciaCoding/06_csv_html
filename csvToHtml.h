#ifndef INC_06_CSV_HTML_CSVTOHTML_H
#define INC_06_CSV_HTML_CSVTOHTML_H

#include <string>
#include <fstream>

extern const std::string START_TAG;
extern const std::string END_TAG;
extern const std::string HTML;
extern const std::string BORDER_NUM;

void writeHeaderHtml(const std::string &fileInName, const std::string &fileOutName);

void writeFooterHtml(const std::string &fileInName, const std::string &fileOutName);

void csvToHtml(const std::string &fileInName, const std::string &fileOutName, const char &delimiter);

#endif //INC_06_CSV_HTML_CSVTOHTML_H
