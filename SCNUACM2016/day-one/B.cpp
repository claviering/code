#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double n;
    int t;
    const double times = 1.000000011;
    cin >> n >> t;
    n *= pow (times,t);
    printf ("%.30f\n",n);
    return 0;
}

