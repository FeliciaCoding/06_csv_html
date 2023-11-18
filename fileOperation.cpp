#include <string>
#include <iostream>
#include "fileOperation.h"

bool openFiles(const std::string &fileInName, const std::string &fileOutName, std::ifstream &fileIn,
               std::ofstream &fileOut) {

    fileIn.open(fileInName);
    if (!fileIn.is_open()) { // error (!fileIn)
        std::cerr << "Unable to open '" << fileInName << "'\n";
        return false;
    }

    fileOut.open(fileOutName);
    if (!fileOut.is_open()) {
        std::cerr << "Unable to open '" << fileOutName << "'\n";
        fileIn.close();
        return false;
    }

    return true;
}

void closeFiles(std::ifstream &fileIn, std::ofstream &fileOut) { //// void v.s. bool ?
    fileIn.close();
    fileOut.close();
}