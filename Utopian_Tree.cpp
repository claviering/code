#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int height = 1;
        for(; n >= 2; n -= 2)
        {
            height <<= 1;
            height += 1;
        } 
        if(n > 0)   height <<= 1;
        cout << height << endl;
    }
    return 0;
}


