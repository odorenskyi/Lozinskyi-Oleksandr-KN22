#include "ModuleFidria.h"

void Registry::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        Subject subject;
        while (file >> subject.region >> subject.name >> subject.leader >> subject.address >> subject.certificate >> subject.directions) {
            subjects.push_back(subject);
        }
        file.close();
    }
}

void Registry::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& subject : subjects) {
            file << subject.region << " " << subject.name << " " << subject.leader << " " << subject.address << " " << subject.certificate << " " << subject.directions << "\n";
        }
        file.close();
    }
}

void Registry::printRegistry() {
    for (const auto& subject : subjects) {
        std::cout << "Region: " << subject.region << std::endl;
        std::cout << "Name: " << subject.name << std::endl;
        std::cout << "Leader: " << subject.leader << std::endl;
        std::cout << "Address: " << subject.address << std::endl;
        std::cout << "Certificate: " << subject.certificate << std::endl;
        std::cout << "Directions: " << subject.directions << std::endl;
        std::cout << std::endl;
    }
}

void Registry::addSubject(const Subject& subject) {
    subjects.push_back(subject);
}

void Registry::searchSubject(const std::string& name) {
    bool found = false;
    for (const auto& subject : subjects) {
        if (subject.name == name) {
            std::cout << "Region: " << subject.region << std::endl;
            std::cout << "Name: " << subject.name << std::endl;
            std::cout << "Leader: " << subject.leader << std::endl;
            std::cout << "Address: " << subject.address << std::endl;
            std::cout << "Certificate: " << subject.certificate << std::endl;
            std::cout << "Directions: " << subject.directions << std::endl;
            std::cout << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Subject not found." << std::endl;
    }
}
