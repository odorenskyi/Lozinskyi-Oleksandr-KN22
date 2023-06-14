#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

class WheelOfFortune {
private:
    std::string name;
    double radius;
    int numSegments;
    bool isSpinning;

public:
    WheelOfFortune() : name(""), radius(0.0), numSegments(0), isSpinning(false) {}

    void spin() {
        if (!isSpinning) {
            isSpinning = true;
            std::cout << "������ ������� ������ ���������!" << std::endl;
        }
    }

    void stop() {
        if (isSpinning) {
            isSpinning = false;
            std::cout << "������ ������� ����������." << std::endl;
        }
    }

    std::string getName() const {
        return name;
    }

    double getRadius() const {
        return radius;
    }

    int getNumSegments() const {
        return numSegments;
    }

    void setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        } else {
            std::cout << "���������� ��'�. ���� �����, ������ �������� ��'�." << std::endl;
        }
    }

    void setRadius(double newRadius) {
        if (newRadius > 0) {
            radius = newRadius;
        } else {
            std::cout << "����������� �����. ���� �����, ������ ��������� ��������." << std::endl;
        }
    }

    void setNumSegments(int newSegments) {
        if (newSegments > 0) {
            numSegments = newSegments;
        } else {
            std::cout << "���������� ������� ��������. ���� �����, ������ ��������� ��������." << std::endl;
        }
    }

    double computeArea() const {
        double area = 3.14159 * radius * radius * numSegments;
        return area;
    }

    void inputData() {
        std::cout << "������ ����� ������: ";
        std::getline(std::cin, name);

        std::cout << "������ ����� ������: ";
        std::cin >> radius;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "������ ������� ��������: ";
        std::cin >> numSegments;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void displayInfo() {
        std::cout << "����� ������: " << getName() << std::endl;
        std::cout << "����� ������: " << getRadius() << std::endl;
        std::cout << "ʳ������ ��������: " << getNumSegments() << std::endl;
        std::cout << "����� ������: " << computeArea() << std::endl;
        std::cout << "������ ���������: " << (isSpinning ? "���" : "ͳ") << std::endl;
    }
};

int main() {
     SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    WheelOfFortune wheel;
    wheel.inputData();

    wheel.displayInfo();

    wheel.spin();
    wheel.displayInfo();

    wheel.stop();
    wheel.displayInfo();

    return 0;
}
