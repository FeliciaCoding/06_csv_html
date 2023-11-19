#ifndef INC_06_CSV_HTML_IOFILECONSOLE_H
#define INC_06_CSV_HTML_IOFILECONSOLE_H

std::string askFileName(const std::string &message);

bool openFiles(const std::string &fileInName, const std::string &fileOutName,
               std::ifstream &fileIn, std::ofstream &fileOut);

void closeFiles(std::ifstream &fileIn, std::ofstream &fileOut);

char getUserChoice(const std::string &message, const char &choice1, const char &choice2);

#endif //INC_06_CSV_HTML_IOFILECONSOLE_H
