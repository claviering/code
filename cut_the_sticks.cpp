#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++)
    {
        cin >> arr[arr_i];
        if(arr[arr_i] <= 0)  n--;
    }
    cout << n << endl;
    sort (arr.begin(),arr.end());
    reverse (arr.begin(),arr.end());
    while(n)
    {
        for(int arr_i = 0; arr_i < n; arr_i++)
        {
            int cut = arr[n-1];
            arr[arr_i] -= cut;
            if(arr[arr_i] <= 0) 
            {
                n = arr_i;
                break;
            }
        }
        if(n > 0)
        cout << n << endl;
    }
    return 0;
}


