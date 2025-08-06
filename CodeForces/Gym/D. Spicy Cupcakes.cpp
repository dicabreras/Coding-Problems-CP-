#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ll n, a, b;
    cin>> n >> a >> b; 
    ll s[n];
    for(int i = 0; i<n; i++) cin>>s[i];
 
    if(a<0) sort(s, s+n, greater<ll>());
    else sort(s, s+n);
    ll ans=0;
    for(int j = 0; j<n; j++){
        ans+=((j+1)*((a*s[j]+b)));
    }
    cout<<ans;
    return 0;
}
