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
            std::cout << "Колесо фортуни почало крутитись!" << std::endl;
        }
    }

    void stop() {
        if (isSpinning) {
            isSpinning = false;
            std::cout << "Колесо фортуни зупинилося." << std::endl;
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
            std::cout << "Некоректне ім'я. Будь ласка, введіть непорожнє ім'я." << std::endl;
        }
    }

    void setRadius(double newRadius) {
        if (newRadius > 0) {
            radius = newRadius;
        } else {
            std::cout << "Некоректний радіус. Будь ласка, введіть позитивне значення." << std::endl;
        }
    }

    void setNumSegments(int newSegments) {
        if (newSegments > 0) {
            numSegments = newSegments;
        } else {
            std::cout << "Некоректна кількість сегментів. Будь ласка, введіть позитивне значення." << std::endl;
        }
    }

    double computeArea() const {
        double area = 3.14159 * radius * radius * numSegments;
        return area;
    }

    void inputData() {
        std::cout << "Введіть назву колеса: ";
        std::getline(std::cin, name);

        std::cout << "Введіть радіус колеса: ";
        std::cin >> radius;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Введіть кількість сегментів: ";
        std::cin >> numSegments;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void displayInfo() {
        std::cout << "Назва колеса: " << getName() << std::endl;
        std::cout << "Радіус колеса: " << getRadius() << std::endl;
        std::cout << "Кількість сегментів: " << getNumSegments() << std::endl;
        std::cout << "Площа колеса: " << computeArea() << std::endl;
        std::cout << "Колесо крутиться: " << (isSpinning ? "Так" : "Ні") << std::endl;
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
