#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
    string s;
    cin >> s;
    sort (s.begin(),s.end());
    int len =s.size();
    int same_count = 1;
    int odd = 0;
    if (len % 2 > 0)
    {
        for (int i = 0, j = 1; j < len; j++)
        {
            if ( s[i] == s[j])  same_count++;
            else 
            {
                i = j;
                if (same_count % 2 > 0)
                    odd++;
                same_count = 1;
                if (odd > 1)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        cout << "YES" << endl;
    }
    else
    {
        for (int i = 0, j = 1; j < len; j++)
        {
            if ( s[i] == s[j])  same_count++;
            else 
            {
                i = j;
                if (same_count % 2 > 0)
                    odd++;
                same_count = 1;
                if (odd > 0)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}

