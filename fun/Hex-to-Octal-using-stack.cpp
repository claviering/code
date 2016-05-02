#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    stack <int> st;

    cin >> n;
    while (n)
    {
        st.push (n%8);
        n /= 8;

    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    cout << endl;
    return 0;
}

