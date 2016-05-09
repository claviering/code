#include <iostream>
#include <queue>
using namespace std;

class Text
{
    public:
        int n;
        friend Text operator - (Text &a,Text &b); 
        Text operator + (Text &a)
        {
            Text tmp;
            tmp.n = n - a.n;
            return tmp;
        }
};
Text operator - (Text &a,Text &b)
{
    Text tmp;
    tmp.n = a.n * b.n;
    return tmp;
}
int main()
{
    Text one,two,three;
    one.n = 9;
    two.n = 8;
    three = one - two;
    cout << three.n << endl;
    return 0;
}

