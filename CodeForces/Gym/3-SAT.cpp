#include  <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int n, int m){
    ll a[n] = {};
    for(ll i = 0; i<m; i++){
        for(ll j = 0; j<3; j++){
            ll x; cin>>x;
            a[x-1]++;
        }
    }
   // for(int i : a)cout<<i<<" ";
   // cout<<endl;
    if(m%2==0){
        for(ll i = 0; i<n; i++){
            if(a[i]%2!=0)return i;
        }
        return 0;       
    }
    else{
        return -1;
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        ll n, m; cin>> n >> m;
        ll ans = solve(n, m);
        //Printing answer
        if(ans == 0) cout<<"NO\n";
        else{
            cout<<"YES\n";
            if(ans==-1){
                for(ll i = 0; i<n; i++){
                    cout<<1<<" ";
                    }
                    cout<<"\n";
            }
            else{
                for(ll i = 0; i<n; i++){
                    if(i!=ans)cout<<1<<" ";
                    else cout<<0<<" ";
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}
