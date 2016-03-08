#include <stdio.h>
int main()
{
    while (1)
    {
        char s[256];
        gets (s);
        int sum = 0;
        int i = 0;
        if (s[i] == '#')
            return 0;
        while (s[i] != '\0')
        {
            int dce = (int)s[i] - 64;
            if (dce < 0)
                dce = 0;
            i++;
            sum +=i*dce;
        }
        printf ("%d\n",sum);
    }
    return 0;
}


