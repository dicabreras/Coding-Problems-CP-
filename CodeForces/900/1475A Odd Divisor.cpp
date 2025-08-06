#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long t, n; 
    bool flag = true;
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>n;
        for(long long p = 2; p<=n; p*=2){
            if(p == n){
                cout<<"NO\n";
                flag = false;
                break;
            }
        }
        if(flag == true){
            cout<<"YES\n";
        }
        flag = true;
    }   
    return 0;
}
