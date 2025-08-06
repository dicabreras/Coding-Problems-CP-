#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t; cin>>t;
    while(t--){
        ll n, k, q;
        cin>>n>>k>>q;
        vector<ll>t(q);
        ll a[k+1], b[k+1], v[k];
        a[0]=0; b[0]=0;
        for(ll i = 1; i<k+1;i++)cin>>a[i];
        for(ll i = 1; i<k+1;i++)cin>>b[i];
        for(ll i = 0, j = 1; j<k; i++, j++){
            ll g = (a[j]-a[i])/(b[j]-b[i]);
            cout<<"velocidad:  "<<g<<endl;
            v[i] = g;
        }

        for(ll i = 0; i<k+1;i++)cout<<a[i]<<" ";
        cout<<endl;

        for(ll i = 0; i<k;i++)cout<<v[i]<<" ";
        cout<<endl;

        for(ll i = 0; i<q; i++){
            ll p; cin>>p;
            ll ans = 0;
            for(int i = 0, j = 1; j<k+1; i++, j++){
                cout<<"entre\n";
                ans+=((a[j]-a[i])/v[i]);
                cout<<"ans: "<<ans <<endl;
                p-=(a[j]-a[i]);
                if(a[i]>=p)break;
            }
            t.push_back(ans);
        }
        for(ll i = 0; i<q; i++)cout<<t[i]<<" ";
        cout<<"\n";
    }
    return 0;
}