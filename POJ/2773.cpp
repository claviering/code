#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int time = 1;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int k = 1; k <= n; k++)
        {
            int tmp = (1 + k + 1) * (k + 1) / 2;
            sum += k * tmp;
        }
            cout << time << " " << n << " " << sum << endl;
            time++;
    }
    return 0;
}

