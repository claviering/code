#include <iostream>
using namespace std;
template <typename T>
T fun(T a,T b)
{
    return a+b;
}
int main(){
    cout<< fun<double>(12.3,12.4) <<endl; 
    return 0;
}


