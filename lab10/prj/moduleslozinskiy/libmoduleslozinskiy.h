#ifndef LIBMODULESLOZINSKIY_H_INCLUDED
#define LIBMODULESLOZINSKIY_H_INCLUDED

void writeAuthorInfo(const std::string& filename);
void writeParagraphCount(const std::string& inputFilename, const std::string& outputFilename);
bool containsWord(const std::string& text, const std::string& word);
void checkWordsInFile(const std::string& inputFilePath, const std::string& outputFilePath);
void appendInfoToFile(const std::string& filename);
int SampleAddInt(int x, int z);
void processInputFile(const std::string& inputFilename, const std::string& outputFilename);


#endif // LIBMODULESLOZINSKIY_H_INCLUDED
