#ifndef STRUCT_TYPE_PROJECT_H_INCLUDED
#define STRUCT_TYPE_PROJECT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// c�������� �� ����� ���'��� �������� ��������
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
    // �����������
    Registry(const std::string& filename);

    // ������� ��� ������������ ������ � �����
    void loadRegistry();

    // ������� ��� ���������� ������ � ����
    void saveRegistry();

    // ������� ��� ��������� ������ �� ����� ��� � ������� ��������� ����
    void printRegistry(std::ostream& output = std::cout) const;

    // ������� ��� ��������� ������ ������ �� ������
    void addSubject(const Subject& subject);

    // ������� ��� ������ ������ � ����� �� ������ �������� �����
    void searchByName(const std::string& name) const;

    // ������� ��� ��������� �������� ������ � ������
    void removeSubject(const std::string& name);
};

#endif // STRUCT_TYPE_PROJECT_H_INCLUDED
