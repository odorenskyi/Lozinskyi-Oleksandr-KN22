#include <iostream>
#include "ModuleFidria.h"
#include "ModuleLozinskyi.h"

int main() {
    Registry registry;
    RegistryManipulator manipulator(registry);
    std::string filename = "registry.txt";

    registry.loadFromFile(filename);

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Print registry" << std::endl;
        std::cout << "2. Add subject" << std::endl;
        std::cout << "3. Search subject" << std::endl;
        std::cout << "4. Remove subject" << std::endl;
        std::cout << "5. Finish program" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            registry.printRegistry();
        }
        else if (choice == 2) {
            Subject subject;
            std::cout << "Enter region: ";
            std::cin >> subject.region;
            std::cout << "Enter name: ";
            std::cin >> subject.name;
            std::cout << "Enter leader: ";
            std::cin >> subject.leader;
            std::cout << "Enter address: ";
            std::cin >> subject.address;
            std::cout << "Enter certificate: ";
            std::cin >> subject.certificate;
            std::cout << "Enter directions: ";
            std::cin >> subject.directions;

            registry.addSubject(subject);
            std::cout << "Subject added." << std::endl;
        }
        else if (choice == 3) {
            std::string name;
            std::cout << "Enter name to search: ";
            std::cin >> name;

            registry.searchSubject(name);
        }
        else if (choice == 4) {
            std::string name;
            std::cout << "Enter name to remove: ";
            std::cin >> name;

            manipulator.removeSubject(name);
        }
        else if (choice == 5) {
            manipulator.finishProgram(filename);
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
