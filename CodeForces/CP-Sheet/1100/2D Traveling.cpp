/*
Coded by Diego Cabrera
*/
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
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll, ll>> v (n);
        pair<ll, ll> p1, p2;
        for(int i = 0; i<n; i++){
            pi p; cin >> p.ff >> p.ss; 
            if(i+1 == a) p1 = p;
            if(i+1 == b) p2 = p;
            v[i] = p;
        }

        //for(auto p : v) cout<< p.ff << " -- " << p.ss<<ln;
         
        ll mn1 = 4*1e9 + 7, mn2 = mn1;
        if(a<=k) mn1 = 0;
        if(b<=k) mn2 = 0;
        for(int i = 0; i<k; i++){
            if(i+1 != a && i+1 != b){
                mn1 = min(mn1, abs(p1.ff - v[i].ff) + abs(p1.ss - v[i].ss));
                mn2 = min(mn2, abs(p2.ff - v[i].ff) + abs(p2.ss - v[i].ss));
            }
        }
        ll d = abs(p1.ff - p2.ff) + abs(p1.ss - p2.ss);
        d = min(d, mn1 + mn2);
        cout<<d<<ln;
    }
    return 0;
}