#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        char word[26] = {0};
        bool ok = 0;
        cin >> a >> b;
        for (int i = 0; i < a.size(); i++)
        {
            if (word[a[i] - 'a'] == 0)
                word[a[i] - 'a']++;
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (word[b[i] - 'a'] == 1)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

