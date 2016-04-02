#include <iostream>
#include <cmath>
using namespace std;

int addDigit(int p)
{
    int re = 0;
    while (p)
    {
        re += p % 10;
        p /= 10;
    }
    return re;
}

long long tailDigitNumber(int k)
{
    int tailNumber = 0;
    while (k)
    {
        tailNumber++;
        k /= 10;
    }
    return tailNumber;
}

int main()
{
    long long n;
    int t;
    int cas = 0;
    while (cin >> n >> t && n > 0)
    {
        cas++;
        while (t--)
        {
            int tail = addDigit(n);
            long long tailN = tailDigitNumber(tail);
            n *= pow (10,tailN);
            n += tail;
        }
        int mod = n % 11;
        cout << n << endl;
        if (!mod)
            cout << " Yes" << endl;
        else
            cout << " No" << endl;
    }
    return 0;
}

