#include "struct_type_project.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

int main()
{
    std::string filename = "registry.txt"; // ім'я файлу для збереження реєстру
    Registry registry(filename); // створення об'єкту класу Registry

    int choice;
    while (true) {
        std::cout << "--------------------------\n";
        std::cout << "1. Display the register\n";
        std::cout << "2. Add a record\n";
        std::cout << "3. Search by name of legal entity\n";
        std::cout << "4. Remove entry\n";
        std::cout << "5. Finish the job\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Register of subjects of evaluation activity:\n";
            registry.printRegistry();
            break;
        case 2: {
            Subject subject;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
            std::cout << "Region: ";
            std::getline(std::cin, subject.region);
            std::cout << "Name: ";
            std::getline(std::cin, subject.name);
            std::cout << "Head: ";
            std::getline(std::cin, subject.manager);
            std::cout << "Legal address: ";
            std::getline(std::cin, subject.address);
            std::cout << "Certificate: ";
            std::getline(std::cin, subject.certificate);
            std::cout << "Areas of activity (through whom): ";
            std::string activities;
            std::getline(std::cin, activities);
            size_t pos = 0;
            while ((pos = activities.find(',')) != std::string::npos) {
                std::string activity = activities.substr(0, pos);
                subject.activities.push_back(activity);
                activities.erase(0, pos + 1);
            }
            subject.activities.push_back(activities);
            registry.addSubject(subject);
            std::cout << "The entry has been added to the register.\n";
            break;
        }
        case 3: {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string searchName;
            std::cout << "Enter the name of the legal entity: ";
            std::getline(std::cin, searchName);
            registry.searchByName(searchName);
            break;
        }
        case 4: {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string removeName;
            std::cout << "Enter the name of the legal entity to remove: ";
            std::getline(std::cin, removeName);
            registry.removeSubject(removeName);
            break;
        }
        case 5:
            registry.saveRegistry();
            std::cout << "The program has been completed. The register is saved in a file " << filename << ".\n";
            return 0;
        default:
            std::cout << "Wrong choice. Try again.\n";
        }
    }

    return 0;
}
