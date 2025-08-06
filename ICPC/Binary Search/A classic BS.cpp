#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> a;

void solve(ll n, ll x){
    ll l=0, r=n-1; 
    while(l<=r){
        ll k = (l+r)/2;
        if((a[k]==x && k==0)|| (a[k]==x && a[k-1]!=x)) {          
            cout<<k<<'\n';
            return;
        }        
        if(a[k]>x || (a[k]==x && a[k-1]==x)) r=k-1;
        else l=k+1;
    }
    cout<<-1<<'\n';
    return;
}

int main()
{
    ll n, q;
    cin>>n>>q;
    a.resize(n);
    for(ll i = 0; i<n; i++)cin>>a[i];
    while(q--){
        ll x; cin>>x;
        solve(n, x);
    }
    return 0;
}

