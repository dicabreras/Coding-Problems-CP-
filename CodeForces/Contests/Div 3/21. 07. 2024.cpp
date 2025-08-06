#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

int main(){
    int t; cin>> t;
    while(t--){
        ll n, x; cin>>n>>x;
        ll a[3] = {1, 1, 1};
        set<ll> S;
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            for(ll k = 0; k<3; k++)S.insert(a[k]);
            if(a[0]*a[1] + a[0]*a[2] + a[1]*a[2] <= n && a[0]+a[1]+a[2]<=x){
                if(S.size()==1) ans++;
                else if(S.size()==2) ans+=3;
                else ans+=6;
            }
            sort(a,a+3);
            a[2]++;
            S.empty();
        }
        cout<<ans<<ln;      
    }
    return 0;
}