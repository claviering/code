#include <iostream>
using namespace std;

int calcLcm(int a,int b)
{
    int m,n;
    while (m != n)
    {
        if (m < n)
            m += a;
        else
            n +=b;
    }
    return m;
}

int calcGcd(int a, int b)
{
    return b == 0 ? a : calcGcd(b, a % b);
}

int main()
{
    const int mod = 258280327;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sn = 0;
        for (int p = 1; p <= n; p++)
        {
            int fn = 0;
            for (int i = 1; i <= p; i++)
            {
                for (int j = 1; j <= p; j++)
                {
                    int lcm = calcLcm(i,j);
                    int gcd = calcGcd(i,j);
                    int total = lcm + gcd;
                    if (total >= p)
                        fn++;
                }
            }
            sn += fn;
        }
        cout << sn % mod << endl;
    }
    return 0;
}

