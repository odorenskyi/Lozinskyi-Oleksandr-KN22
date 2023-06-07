#include <iostream>
#include <string>
#include "libmoduleslozinskiy.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.txt";

    // Вызов функции writeAuthorInfo
    writeAuthorInfo(outputFilename);

    // Вызов функции writeParagraphCount
    writeParagraphCount(inputFilename, outputFilename);

    // Вызов функции writeWordPresence
    checkWordsInFile(inputFilename, outputFilename);

    // Вызов функции appendInfoToFile
    appendInfoToFile(inputFilename);

    // Вызов функции processInputFile
    processInputFile(inputFilename, outputFilename);

    return 0;
}


