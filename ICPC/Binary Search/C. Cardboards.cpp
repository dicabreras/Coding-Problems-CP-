#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

ll solve(ll a[], int n, ll c){
    ll l = 1, r = 1e9;
    while(l<=r){
        ll k = l + (r-l)/2;
        ll sum = c;
        for(int i = 0; i<n; i++){
            ll x = ((a[i]+(2*k))*(a[i]+(2*k)));
            sum-=x;
            if(sum<0)break;
        }
        if(sum==0)return k;
        if(sum<0) r=k-1;
        else l = k+1;
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n; ll c;
        cin>> n >> c; 
        ll a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        ll ans = solve(a, n, c);
        cout<<ans<<'\n'; 
    }
    return 0;
}
