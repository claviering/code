#include <iostream>
#include <string>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    if(k > 26)
        k %= 26;
    for(int i = 0; i < n; i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
        {
            int asc =int(s[i]) + k;
            if(asc > 122)
                asc =asc % 122 + 96; 
            s[i] = char(asc);
        }
        else if('A' <= s[i] && s[i] <= 'Z')
        {
            int asc =int(s[i]) + k;
            if(asc > 90)
                asc =asc % 90 + 64; 
            s[i] = char(asc);

        }
    }
    cout << s << endl;
    return 0;
}

