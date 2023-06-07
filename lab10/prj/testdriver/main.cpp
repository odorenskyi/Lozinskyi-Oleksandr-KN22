#include <iostream>
#include <string>
#include "libmoduleslozinskiy.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    // ����� ������� writeAuthorInfo
    writeAuthorInfo(outputFilename);

    // ����� ������� writeParagraphCount
    writeParagraphCount(inputFilename, outputFilename);

    // ����� ������� writeWordPresence
    checkWordsInFile(inputFilename, outputFilename);

    // ����� ������� appendInfoToFile
    appendInfoToFile(inputFilename);

    // ����� ������� processInputFile
    processInputFile(inputFilename, outputFilename);

    return 0;
}


