#include <iostream>
using namespace std;
int main()
{
    const int big = 10000;
    int re[big][big];
    for (int n = 1; n < big; n++)
    {
        for (int m = n+1; m <= big; m++)
        {
            int ans= 0;
            for (int i = n; i <= m; i++)
            {
                int tmp = i;
                int num[10] = {0};
                bool ok = 1;
                while (tmp)
                {
                    if (num[tmp%10])
                    {
                        ok = 0;
                        break;
                    }
                    else
                    {
                        num[tmp%10]++;
                    }
                    tmp /= 10;
                }
                if (ok)
                    ans++;
            }
            re[n][m] = ans;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        int b;
        cin >> a >> b;
        cout << re[a][b] << endl;
    }
    return 0;
}

