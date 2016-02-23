#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0; width_i < n; width_i++)
    {
        cin >> width[width_i];
    }
    while(t--)
    {
        int i;
        int j;
        cin >> i >> j;
        int largest = width[i];
        while(i < j)
        {
            if(width[++i] < largest)  largest = width[i];
        }
        cout << largest << endl;
    }
    return 0;
}


