#include <iostream>
#include <vector>

using namespace std;
int main(){
    int t;
    cin >> t;
    vector<int> ans(t);
    int index = 0;
    int num = t;
    while(t--)
    {
        int n;
        cin >> n;
        int divisble = 0;
        while(n / 10)
        {
            if((n % 10) > 0) divisble++;
            n /= 10;
        }
        if(n > 0) divisble++;
        ans[index] = divisble;
       index++;
    }
    for(int i = 0; i < num; i++)
        cout << ans[i] << endl;
    return 0;
}


