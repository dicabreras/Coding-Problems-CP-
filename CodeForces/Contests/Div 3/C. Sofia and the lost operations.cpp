#include <bits/stdc++.h>
using namespace std;

using ll = long long;


//https://codeforces.com/contest/1980/problem/C

int main()
{
    int t; cin>>t;
    while(t--){
        map<ll, int> mp;
        int n, m; cin>>n;
        ll a[n], b[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i];
        cin>>m;
        int d[m];
        for(int i = 0; i<m; i++){
            ll x;  
            cin>>x;
            d[i] = x;
            if(mp.count(x)>0) {
                //int current = mp[x];  
                mp[x]++;
            }
            else{
                mp.insert({x, 1});
            }
        }
        /*
        for (const auto& pair : mp) {
        cout << pair.first << ": " << pair.second <<endl;
        }
        */
        
       bool flag = true; 
       ll z = d[m-1];
        for(int i = 0; i<n; i++){
            ll current = b[i];
            if(current != a[i]){
                if(mp.count(current)>0 && mp[current]>0){
                    mp[current]--;
                  /*
                    for (const auto& pair : mp) {
                        cout << pair.first << ": " << pair.second <<endl;
                    }
                    */
                }
                else flag = false;

            }
            if(current == z) z = 0;
            if(i+1==n && z > 0) flag = false; 
        }
        
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}


