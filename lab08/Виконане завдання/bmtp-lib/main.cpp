#include <math.h>
#include "bib.h"
int SampleAddInt(int x, int z)
{int s = sqrt(1 + fabs(cos(x))) + 2 * M_PI + pow(fabs(z-x)/sin(x),2);
    return s;
}
