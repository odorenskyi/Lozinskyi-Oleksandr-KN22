#include <iostream>
#include <vector>
#include <math.h>
#include"moduleslozinskiy.h"
using namespace std;

double windbyBafort(double x)
{
    setlocale(LC_ALL, "ukr");
    double c = x / 1000;
    if (c < 0.3)
        cout << "�������� ����: <0.3. ��������������: ³�������� ����. ��� ��������� ����������. ����� ����� �������" << endl;
    if (c >= 0.3 && c <= 1.5)
        cout << "�������� ����: 0.3-1.5. ��������������: ��� �����. ������ �� ����������" << endl;
    if (c >= 1.6 && c <= 3.3)
        cout << "�������� ����: 1.6-9.4. ��������������: ��� ������ ���������� ��������. ��������� �����. ������ ����������" << endl;
    if (c >= 3.4 && c <= 5.4)
        cout << "�������� ����: 9.4-5.4. ��������������: ������ �����, ��������� ���� ����. ������� �������" << endl;
    if (c >= 5.5 && c <= 7.9)
        cout << "�������� ����: 5.5-7.9. ��������������: ��������� ���� ���� �����. ³��� ����� ��� �� ������ ������" << endl;
    if (c >= 8.0 && c <= 10.7)
        cout << "�������� ����: 8.0-10.7. ��������������: ��������� ����� ����. �� ��� �'��������� ����" << endl;
    if (c >= 10.8 && c <= 13.8)
        cout << "�������� ����: 10.8-13.8. ��������������: ��������� ����� ����" << endl;
    if (c >= 13.9 && c <= 17.1)
        cout << "�������� ����: 13.9-17.1. ��������������: ��������� ������� �������� �����. �� ��� ���������� ����, �������" << endl;
    if (c >= 17.2 && c <= 20.7)
        cout << "�������� ����: 17.2-20.7. ��������������: ��������� ���� �����, ����� ��� ����� ����" << endl;
    if (c >= 20.8 && c <= 24.4)
        cout << "�������� ����: 20.8-24.4. ��������������: ������� ����������. ����� ������, ����� �����." << endl;
    if (c >= 24.5 && c <= 28.4)
        cout << "�������� ����: 24.5-28.4. ��������������: ����� ����������. ������ ����������� � �������" << endl;
    if (c >= 28.5 && c <= 32.6)
        cout << "�������� ����: 28.5-32.6. ��������������: ����� ����������" << endl;
    if (c >= 32.7)
        cout << "�������� ����: >=32.7. ��������������: ���������� �� ����������" << endl;

    return 0;
}

double calculateWeeklyAverage(const std::vector<double>& temperatures) {
    double sum = 0.0;
    for (double temp : temperatures) {
        sum += temp;
    }
    double average = sum / temperatures.size();
    return average;
}

double convertToCelsiusToFahrenheit(double celsius) {
    double fahrenheit = celsius * 9 / 5 + 32;
    return fahrenheit;
}
bool checkD7Bit(unsigned int n) {
    return (n & (1 << 7)) == 0;
}

// ���������� ������� �������� ���� � ���� n
int countZeroes(unsigned int n) {
    int count = 0;
    while (n != 0) {
        if ((n & 1) == 0) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// ���������� ������� �������� ������� � ���� n
int countOnes(unsigned int n) {
    int count = 0;
    while (n != 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}
int SampleAddInt(int x, int z)
{int s = sqrt(1 + fabs(cos(x))) + 2 * M_PI + pow(fabs(z-x)/sin(x),2);
    return s;
}

