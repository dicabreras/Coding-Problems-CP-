#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"
 
const int M = 1e9+7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int t; cin >> t;
    while(t--){
        ll n, k, b, s; cin >> n >> k >> b >> s;
        ll q = s/k, r = s%k;
        int f = 1;
        vector<ll> v;
        if(q<b) f = 0;
        if(n<2 && q>=b && r>0) f = 0;
        if(k==1 && b!=s) f=0;
        else if(f){
            ll d = q-b, additional;
            if(d == 0){
                v.pb(s-r);
                if(n>1) v.pb(r);
                for(int i = 2; i<n; i++) v.pb(0);    
            }
            else{
                additional = (d-1)*k + r + 1;
                v.pb(s-additional);
                if(additional<k){
                    v.pb(additional);
                    for(int i = 2; i<n; i++) v.pb(0);
                }
                else{
                    ll blocks = additional/(k-1), rb=additional%(k-1);
                    if(rb>0) blocks++;
                    if(n-1-blocks<0) f = 0;
                    else{
                        for(int i = 0; i<blocks-1; i++) v.pb(k-1);
                        if(rb>0) v.pb(rb);
                        else v.pb(k-1);
                        for(int i = 0; i<n-1-blocks; i++) v.pb(0);
                    }
                }
            }

        }
        if(f){
            for(auto a : v){
                cout<< a << " ";
            }
            cout<<ln;
        }
        else{
            cout<<-1<<ln;
        }
        
    }
    return 0;
}