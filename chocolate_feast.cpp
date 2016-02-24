#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int num = n / c;
        int wrappers = num;
        while(wrappers >= m)
        {
            num += wrappers / m;
            int ate = wrappers / m;
            wrappers %= m;
            wrappers += ate;
        }
        cout << num << endl;
    }
    return 0;
}

