#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    char r[] = {'a', 'b', 'c'};
    while (t--){
        char l[3];
        bool flag = true;
        for(int i = 0; i<3; i++){
            cin>>l[i];
        }
        char p[4][3] = {{l[0], l[1], l[2]},{l[1], l[0], l[2]},{l[2], l[1], l[0]}, {l[0], l[2], l[1]}};
        for(int i = 0; i<4; i++){
            flag = true;
            for(int j = 0; j<3; j++){
                if(p[i][j]!=r[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<"YES\n";
                break;
            }
        }
        if(!flag)cout<<"NO\n";
        
    }
    
    return 0;
}