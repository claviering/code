//Test from www.hackerrank.com/challenges/the-grid-search
#include <iostream>
#include <string>
using namespace std;
int main(){
    int time;
    cin>>time;
    for(int i=0;i<time;i++){
        int R,C;
        cin>>R>>C;
        string bigGrid[R];
        for(int j=0;j<R;j++){
            cin>>bigGrid[j];
        }
        int r,c;
        cin>>r>>c;
        string smallGrid[r];
        for(int j=0;j<r;j++){
            cin>>bigGrid[j];
        }
        bool ok=1;
        for(int k=0,s=0;k<R;k++){
            size_t found=bigGrid[k].find(smallGrid[s]);
            if(found != string::npos){
                for(int y=0;y<r;y++,k++,s++){
                    size_t nextFound=bigGrid[k].find(smallGrid[s]);
                    if(nextFound == string::npos){
                        ok=0;
                        break;
                    }
                }
            }
            else ok=0;
        }
        if(ok)  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}


