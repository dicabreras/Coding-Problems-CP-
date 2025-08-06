#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t; cin>>t;
    while(t--){
        int ans = 0; 
        string s; cin>>s;
        if(s=="10"){
            cout<<2<<"\n";
            continue;
        }
        int c = s[0];
        for(char i: s){
           if(i!=c) {
            c=i;
            ans++;
            }
        }
        if(ans == 0) ans++;
        cout<<ans<<"\n";
    }
    return 0;
}