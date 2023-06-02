#include <iostream>
#include "moduleslozinskiy.h"
#include <windows.h>
#include <clocale>
#include <iomanip>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

double s_calculation(double x, double z) {
    return pow(sqrt(1 + fabs(cos(x))) + 2 * M_PI + pow(fabs(z - x) / sin(x), 2), 1.0);
}

void mainmenu(){
    int first,second;
    char action;
    cout<<"Enter your action:q, e, g, r"<<endl;
    cin>>action;

    if(action=='q')
    {  cin>>first>>second;
        cout<<"Enter your x:"<<first<<endl;
       cout<<"Enter your y:"<<second<<endl;
       cout<<"Result: " << s_calculation(first,second)<<endl;
    }
    if(action=='e')
    {
         setlocale(LC_ALL,"ukr");
    double windSpeed;

    cout << "Введіть швидкість вітру: ";
    cin >> windSpeed;

    windbyBafort(windSpeed);

    }
    if(action=='g')
    {
        cout<<"Enter your deposit: "<<first<<endl;
        cout<<"Enter your term months: "<<second<<endl;

       int term(int first, int second);
    }
    if(action=='r')
    {
        setlocale(LC_ALL,"ukr");
        std::vector<double> temperatures;

    std::cout << "Введіть температури за тиждень (7 значень):\n";

    for (int i = 1; i <= 7; ++i) {
        double temp;
        std::cout << "Температура " << i << ": ";
        std::cin >> temp;
        temperatures.push_back(temp);
    }

    double average = calculateWeeklyAverage(temperatures);
    double averageFahrenheit = convertToCelsiusToFahrenheit(average);

    std::cout << "Середньотижнева температура: " << average << " градусів Цельсія\n";
    std::cout << "Середньотижнева температура: " << averageFahrenheit << " градусів Фаренгейта\n";
    }
    else{
        cout<<"\a"<<endl;
        cout<<"Enter new action: (y-exit)"<<endl;
        cin>>action;
        if(action=='y'||action=='Y')
        {
            exit(0);
        }
        else{
            mainmenu();
        }
    }
}
int main()
{   mainmenu();
    return 0;
}
