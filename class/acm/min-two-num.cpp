#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
    vector<int> vNum;
    queue<int> qNum;

    char s[256];
    cin.getline(s,256);

    int i = 0;
    do
    {
        int n = s[i] - '0';
        vNum.insert (vNum.begin(),n);
        i += 2;

    }while (s[i] >= '0');

    sort (vNum.begin(),vNum.end());

    while (!vNum.empty())
    {
        int first = vNum.front();
        vNum.erase(vNum.begin());
        if (!vNum.empty())
        {
            int second = vNum.front();
            vNum.erase(vNum.begin());
            int end = first + second;

            cout << first << " " << second << " " << end << endl;

            vNum.push_back(end);

            sort (vNum.begin(),vNum.end());
        }
    }
    return 0;
}

