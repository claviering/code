#include <stdio.h>
int main()
{
    int arr[48];
    int i;
    for (i = 0; i < 48; i++)
    {
        int temp;
        scanf ("%d",&temp);
        arr[i] = temp;
    }
    int r,g,b;
    while (scanf ("%d %d %d",&r,&g,&b) != EOF && r >= 0 && g >= 0 && b >= 0)
    {
        int minI[3] = {0};
        int dMax = 10000000;
        int i;
        for (i = 0; i <= 45; i += 3)
        {
           int d = (r - arr[i])*(r - arr[i]) + (g - arr[i+1])*(g - arr[i+1]) + (b - arr[i+2])*(b - arr[i+2]);
           if (d <= dMax)
           {
               dMax = d;
               minI[0] = arr[i];
               minI[1] = arr[i+1];
               minI[2] = arr[i+2];
           }
        }
        printf ("(%d,%d,%d) maps to (%d,%d,%d)\n",r,g,b,minI[0],minI[1],minI[2]);
    }
    return 0;
}


