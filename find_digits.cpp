#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
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
        cout << divisble << endl;
    }
    return 0;
}


