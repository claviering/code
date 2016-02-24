#include <iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int num = n;
        int divisble = 0;
        while(num)
        {
            int curDigit = num % 10;
            if(curDigit > 0 && n % curDigit == 0) divisble++;
            num /= 10;
        }
        cout << divisble << endl;
    }
    return 0;
}


