#include <iostream>
#include <Moduleslozinskiy.h>
using namespace std;

int main()
{int test1 = SampleAddInt(5,1);
    if (test1 == 24)
        cout <<"test1 is corect "<< endl;
int test2 = SampleAddInt(3,2);
    if (test2 == 57)
        cout <<"test2 is corect "<< endl;
    int test3 = SampleAddInt(7,5);
    if (test3 == 16)
        cout <<"test3 is corect "<< endl;
    int test4 = SampleAddInt(6,8);
    if (test4 == 58)
        cout <<"test4 is corect "<< endl;
   return 0;
}
