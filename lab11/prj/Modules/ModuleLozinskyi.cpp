#include "ModuleLozinskyi.h"

void RegistryManipulator::removeSubject(const std::string& name) {
    for (auto it = registry.subjects.begin(); it != registry.subjects.end(); ++it) {
        if (it->name == name) {
            registry.subjects.erase(it);
            std::cout << "Subject removed." << std::endl;
            return;
        }
    }
    std::cout << "Subject not found." << std::endl;
}

void RegistryManipulator::finishProgram(const std::string& filename) {
    registry.saveToFile(filename);
    std::cout << "Program finished. Registry saved to file." << std::endl;
}
