#ifndef INC_06_CSV_HTML_CSVTOHTML_H
#define INC_06_CSV_HTML_CSVTOHTML_H

#include <string>
#include <fstream>

extern const std::string START_TAG; //  = "<";
extern const std::string END_TAG; //   = "</";
extern const std::string HTML; //       = "html>\n";
extern const std::string BORDER_NUM; // = "1";


//extern std::ifstream fileIn(const std::string& fileInName); //// question: const reference?
//extern std::ofstream fileOut(const std::string& fileOutName); //// question: const reference?


void writeHeaderHtml(const std::string &fileInName, const std::string &fileOutName);

void writeFooterHtml(const std::string &fileInName, const std::string &fileOutName);

void csvToHtml(const std::string &fileInName, const std::string &fileOutName, const char &delimiter);

#endif //INC_06_CSV_HTML_CSVTOHTML_H
