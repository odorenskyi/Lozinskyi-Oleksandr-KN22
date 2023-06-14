#ifndef STRUCT_TYPE_PROJECT_H_INCLUDED
#define STRUCT_TYPE_PROJECT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// cтруктура що описує суб'єкт оціночної діяльності
struct Subject {
    std::string region;
    std::string name;
    std::string manager;
    std::string address;
    std::string certificate;
    std::vector<std::string> activities;
};

class Registry {
private:
    std::vector<Subject> subjects;
    std::string filename;

public:
    // конструктор
    Registry(const std::string& filename);

    // функція для завантаження реєстру з файлу
    void loadRegistry();

    // функція для збереження реєстру у файл
    void saveRegistry();

    // функція для виведення реєстру на екран або у заданий текстовий файл
    void printRegistry(std::ostream& output = std::cout) const;

    // функція для додавання нового запису до реєстру
    void addSubject(const Subject& subject);

    // функція для пошуку запису в реєстрі за назвою юридичної особи
    void searchByName(const std::string& name) const;

    // функція для вилучення заданого запису з реєстру
    void removeSubject(const std::string& name);
};

#endif // STRUCT_TYPE_PROJECT_H_INCLUDED
