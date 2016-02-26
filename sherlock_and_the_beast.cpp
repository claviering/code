#include <iostream>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool bo = 1;
        for(int i = 0; i <= n; i++)
        {
           int num_5 = (n - i) % 3; 
           int num_3 = i % 5; 
           if (num_5 == 0 && num_3 == 0)
           {
               for (int p = 0; p < n - i; p++)  cout << "5";
               for (int p = 0; p < i; p++)  cout << "3";
               cout << endl;
               bo = 0;
               break;
           }
        }
        if (bo)
        cout << "-1" << endl;
    }
    return 0;
}

