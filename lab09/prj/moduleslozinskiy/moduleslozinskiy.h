#ifndef MODULESLOZINSKIY_H_INCLUDED
#define MODULESLOZINSKIY_H_INCLUDED

#include <vector>

double windbyBafort(double c);
double calculateWeeklyAverage(const std::vector<double>& temperatures);
double convertToCelsiusToFahrenheit(double celsius);
bool checkD7Bit(unsigned int n);
int countZeroes(unsigned int n);
int countOnes(unsigned int n);
int SampleAddInt(int x, int z);


#endif // MODULESLOZINSKIY_H_INCLUDED
