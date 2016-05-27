#include <stdio.h>
int main()
{
    const int nConst = 10;
    *(int *)&nConst = 100;
    printf("%d\n",nConst);
    return 0;
}

