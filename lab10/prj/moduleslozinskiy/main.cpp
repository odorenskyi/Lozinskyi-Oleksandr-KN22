#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <chrono>
#include <cmath>
#include "libmoduleslozinskiy.h"

void writeAuthorInfo(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Unable to open the file." << std::endl;
        return;
    }

    std::string developerName = "Lozinskiy Oleksandr";
    std::string city = "Kropyvnytskyi";
    std::string country = "Ukraine";
    int developmentYear = 2023;

    file << "Ім'я: " << developerName << '\n'
         << "Місто: " << city << '\n'
         << "Країна: " << country << '\n'
         << "Рік розробки: " << developmentYear << '\n';

    std::cout << "Author information has been written to the file." << std::endl;
}

void writeParagraphCount(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile) {
        std::cerr << "Unable to open the input file." << std::endl;
        return;
    }

    int paragraphCount = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            paragraphCount++;
        }
    }

    std::ofstream outputFile(outputFilename, std::ios::app);
    if (!outputFile) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    outputFile << "кількість абзаців: " << paragraphCount << '\n';

    std::cout << "Paragraph count has been written to the file." << std::endl;
}

bool containsWord(const std::string& text, const std::string& word) {
    std::string normalizedText = text;
    std::transform(normalizedText.begin(), normalizedText.end(), normalizedText.begin(), ::tolower);

    std::string normalizedWord = word;
    std::transform(normalizedWord.begin(), normalizedWord.end(), normalizedWord.begin(), ::tolower);

    size_t found = normalizedText.find(normalizedWord);
    return (found != std::string::npos);
}

void checkWordsInFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath);
    std::ofstream outputFile(outputFilePath, std::ios::app); // Дописуємо у вихідний файл

    if (!inputFile) {
        std::cout << "Failed to open the input file." << std::endl;
        return;
    }

    if (!outputFile) {
        std::cout << "Failed to open the output file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (containsWord(line, "Україна")) {
            outputFile << "Україна знайдена: " << line << std::endl;
        }

        if (containsWord(line, "університет")) {
            outputFile << "університет знайдено: " << line << std::endl;
        }

        if (containsWord(line, "блокнот")) {
            outputFile << "блокнот знайдено: " << line << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Completed." << std::endl;
}


void appendInfoToFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Unable to open the input file." << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    int dotCount = 0;
    for (char c : content) {
        if (c == '.')
            dotCount++;
    }

    std::ofstream outputFile(filename, std::ios::app);
    if (!outputFile) {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    outputFile << "\nNumber of dots: " << dotCount << std::endl;

    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    outputFile << "Date and time of append: " << std::ctime(&time);

    std::cout << "Information has been appended to the file." << std::endl;
}

int SampleAddInt(int x, int z)
{
    int s = sqrt(1 + std::fabs(std::cos(x))) + 2 * M_PI + std::pow(std::fabs(z - x) / std::sin(x), 2);
    return s;
}

void processInputFile(const std::string& inputFilename, const std::string& outputFilename)
{
    std::ifstream inputFile(inputFilename);
    if (!inputFile)
    {
        std::cerr << "Unable to open the input file." << std::endl;
        return;
    }

    int x, z, b;
    inputFile >> x >> z >> b;
    inputFile.close();

    int result = SampleAddInt(x, z);

    std::ofstream outputFile(outputFilename, std::ios::app);
    if (!outputFile)
    {
        std::cerr << "Unable to open the output file." << std::endl;
        return;
    }

    // Convert b to binary string
    std::string binaryB;
    while (b > 0)
    {
        binaryB = std::to_string(b % 2) + binaryB;
        b /= 2;
    }

    outputFile << "x: " << x << std::endl;
    outputFile << "z: " << z << std::endl;
    outputFile << "b (binary): " << binaryB << std::endl;
    outputFile << "Result: " << result << std::endl;

    std::cout << "Result has been written to the file." << std::endl;
}
