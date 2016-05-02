#include <iostream>
using namespace std;
int main()
{
    int a;
    int b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int n = 1;
        int countZore = 0;
        while (i >= n)
        {
            int tmp = (i & n);
            if (!tmp)
                countZore++;
            n <<= 1;
        }
        if (countZore >= 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

