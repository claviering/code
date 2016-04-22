#include <iostream>
#include <cctype>
#include <cstdlib>

/*
*isdigit #include <cctype>
*Check if character is decimal digit
*
*atoi #include <cstdlib>
*Convert string to integer
*/

using namespace std;
int main()
{
    char s[] = "123456asdf"; 
    int n;
    if (isdigit (s[7]))
    {
        n = atoi (s);
        cout << n << endl;
    }
    return 0;
}

