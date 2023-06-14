#include "struct_type_project.h"

Registry::Registry(const std::string& filename)
    : filename(filename)
{
    loadRegistry();
}

void Registry::loadRegistry()
{
    std::ifstream file(filename);
    if (file.is_open()) {
        subjects.clear();
        std::string line;
        while (std::getline(file, line)) {
            Subject subject;
            subject.region = line;
            std::getline(file, subject.name);
            std::getline(file, subject.manager);
            std::getline(file, subject.address);
            std::getline(file, subject.certificate);
            std::string activities;
            std::getline(file, activities);
            // розділити напрямки діяльності за комами і зберегти у вектор
            size_t pos = 0;
            while ((pos = activities.find(',')) != std::string::npos) {
                std::string activity = activities.substr(0, pos);
                subject.activities.push_back(activity);
                activities.erase(0, pos + 1);
            }
            subject.activities.push_back(activities); // додати останній напрямок діяльності
            subjects.push_back(subject);
        }
        file.close();
    }
}

void Registry::saveRegistry()
{
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Subject& subject : subjects) {
            file << subject.region << "\n";
            file << subject.name << "\n";
            file << subject.manager << "\n";
            file << subject.address << "\n";
            file << subject.certificate << "\n";
            for (size_t i = 0; i < subject.activities.size() - 1; ++i) {
                file << subject.activities[i] << ",";
            }
            file << subject.activities.back() << "\n";
        }
        file.close();
    }
}

void Registry::printRegistry(std::ostream& output) const
{
    for (const Subject& subject : subjects) {
        output << "Region: " << subject.region << "\n";
        output << "Name: " << subject.name << "\n";
        output << "Manager: " << subject.manager << "\n";
        output << "Address: " << subject.address << "\n";
        output << "Certificate: " << subject.certificate << "\n";
        output << "Activities: ";
        for (size_t i = 0; i < subject.activities.size() - 1; ++i) {
            output << subject.activities[i] << ", ";
        }
        output << subject.activities.back() << "\n";
        output << "--------------------------\n";
    }
}

void Registry::addSubject(const Subject& subject)
{
    subjects.push_back(subject);
}

void Registry::searchByName(const std::string& name) const
{
    bool found = false;
    for (const Subject& subject : subjects) {
        if (subject.name == name) {
            std::cout << "Subject found:\n";
            std::cout << "Region: " << subject.region << "\n";
            std::cout << "Name: " << subject.name << "\n";
            std::cout << "Manager: " << subject.manager << "\n";
            std::cout << "Address: " << subject.address << "\n";
            std::cout << "Certificate: " << subject.certificate << "\n";
            std::cout << "Activities: ";
            for (size_t i = 0; i < subject.activities.size() - 1; ++i) {
                std::cout << subject.activities[i] << ", ";
            }
            std::cout << subject.activities.back() << "\n";
            std::cout << "--------------------------\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Subject not found.\n";
    }
}

void Registry::removeSubject(const std::string& name)
{
    for (auto it = subjects.begin(); it != subjects.end(); ++it) {
        if ((*it).name == name) {
            subjects.erase(it);
            std::cout << "Subject removed:\n";
            std::cout << "Region: " << (*it).region << "\n";
            std::cout << "Name: " << (*it).name << "\n";
            std::cout << "Manager: " << (*it).manager << "\n";
            std::cout << "Address: " << (*it).address << "\n";
            std::cout << "Certificate: " << (*it).certificate << "\n";
            std::cout << "Activities: ";
            for (size_t i = 0; i < (*it).activities.size() - 1; ++i) {
                std::cout << (*it).activities[i] << ", ";
            }
            std::cout << (*it).activities.back() << "\n";
            std::cout << "--------------------------\n";
            return;
        }
    }
    std::cout << "Subject not found.\n";
}
