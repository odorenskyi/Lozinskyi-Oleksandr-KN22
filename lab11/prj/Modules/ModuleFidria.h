#ifndef MODULEFIDRIA_H
#define MODULEFIDRIA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Subject {
    std::string region;
    std::string name;
    std::string leader;
    std::string address;
    std::string certificate;
    std::string directions;
};

class Registry {
private:
    std::vector<Subject> subjects;

    // Добавте наступний рядок
    friend class RegistryManipulator;

public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
    void printRegistry();
    void addSubject(const Subject& subject);
    void searchSubject(const std::string& name);
};

#endif
