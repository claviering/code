#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    if (a == 0)
    {
        double x = (double)-c / b;
        printf ("%.15f\n",x);
        printf ("%.15f\n",x);

    }
    else
    {
        double x1;
        double x2;
        double d = (double)(b * b - 4 * a * c);
        if (d >= 0)
        {
            x1 = ((double)(-b + sqrt (d)) / (2 * a));
            x2 = ((double)(-b - sqrt (d)) / (2 * a));
            printf ("%.20f\n%.20f\n",x1,x2);
        }
    }
    return 0;
}

