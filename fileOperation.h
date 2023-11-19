#ifndef INC_06_CSV_HTML_FILEOPERATION_H
#define INC_06_CSV_HTML_FILEOPERATION_H

bool openFiles(const std::string &fileInName, const std::string &fileOutName,
               std::ifstream &fileIn, std::ofstream &fileOut);

void closeFiles(std::ifstream &fileIn, std::ofstream &fileOut);

#endif //INC_06_CSV_HTML_FILEOPERATION_H
