#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int n = gcd(4,6); 
    cout << n << endl;
    return 0;
}

