#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int t; cin>>t;
    int p[10][10] = {{1,1,1,1,1,1,1,1,1,1},
                 {1,2,2,2,2,2,2,2,2,1},
                 {1,2,3,3,3,3,3,3,2,1},
                 {1,2,3,4,4,4,4,3,2,1},
                 {1,2,3,4,5,5,4,3,2,1},
                 {1,2,3,4,5,5,4,3,2,1},
                 {1,2,3,4,4,4,4,3,2,1},
                 {1,2,3,3,3,3,3,3,2,1},
                 {1,2,2,2,2,2,2,2,2,1},
                 {1,1,1,1,1,1,1,1,1,1}};
    while (t--){
        char a[10][10];
        int s = 0;
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                cin>>a[i][j];
            }
        }
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                if(a[i][j]=='X')s+=p[i][j];
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
//https://codeforces.com/contest/1873
