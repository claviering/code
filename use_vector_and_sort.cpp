#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    vector<int> arr(5);
    for(int num = arr.size(), i = 0; num >= 0; num--, i++)
    {
        arr[i] = num;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < 5; i++)  cout << arr[i] << endl;
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < 5; i++)  cout << arr[i] << endl;
    return 0;
}


