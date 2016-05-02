#include <iostream>
#include <vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cin >> n >> k;
        vector<int> a(n);
        int hold = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] <= 0)
            {
                hold++;
            }
        }
        if(hold < k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}


