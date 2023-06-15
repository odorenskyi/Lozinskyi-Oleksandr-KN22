#ifndef MODULELOZINSKYI_H
#define MODULELOZINSKYI_H

#include "ModuleFidria.h"

class RegistryManipulator {
private:
    Registry& registry;

public:
    explicit RegistryManipulator(Registry& registry) : registry(registry) {}

    void removeSubject(const std::string& name);
    void finishProgram(const std::string& filename);
};

#endif
