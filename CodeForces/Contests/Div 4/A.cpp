#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        bool ans = false;
        for(int i = 0, j=1; j<s.size(); i++, j++){
            if(s[i]!=s[j]) ans = true; 
        }
        if(ans){
            cout<<"YES\n";
            cout<<s[s.size()-1];
            for(int i = 0; i<s.size()-1; i++){
                cout<<s[i];
            }
            cout<<"\n"; 
        }
        else cout<<"NO\n";
    }
    return 0;
}