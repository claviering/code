#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int q;
    cin >> q;
    string sq[q];
    for (int i = 0; i < q; i++)
    {
        cin >> sq[i];
        int num = 0;
        for (int y = 0; y < n; y++)
        {
            if (sq[i] == s[y])
                num++;
        }
        cout << num << endl;
    }
    return 0;
}

