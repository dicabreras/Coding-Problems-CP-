#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(){
    int n; ll x; 
    cin>> n >> x;
    int a[n];   
    for(int i = 0; i<n; i++)cin>>a[i];

    ll l=0, r = 3e10, mn = 2e9, ans;
    while(l<=r){
        ll h = l + (r-l)/2;
        ll temp=x;
      //  cout<<"h: "<<h<<endl;
        for(int i = 0; i<n; i++){
            if(a[i]<h) temp-=(h-a[i]);
           // cout<<"water:  "<<temp<<endl;
            if(temp<0) break;
        }
        if(temp<=mn && temp>=0){
            if(temp==0) return h;
            else {
                ans = h;
                mn = temp;
            }
        }
        if(temp<0)r = h-1;
        else l = h+1;
    } 
    return ans;
}

int main()
{
    int t; cin>>t; 
    while(t--){
        ll ans = solve();
        cout<<ans<<'\n';
    }
    return 0;
}
