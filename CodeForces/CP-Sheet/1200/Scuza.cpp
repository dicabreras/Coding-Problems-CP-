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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q; 
        ll a[n], k[q], pos[q], pfx_sum[n+1] = {};

        for(int i = 0; i<n; i++){
            cin >> a[i];
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        for(int i = 0; i<q; i++){
            cin >> k[i];
            pos[i] = k[i];
        }
        sort(k, k+q);
        int i = 0, l = 0;
        map<int, int> m;
        while(l<q){
            while(k[l]>=a[i] && i<n){
                i++;
            }
            m[k[l]] = i;
            l++;
        }

        for(auto x : pos){
            int j = m[x];
            ll d = pfx_sum[j];
            cout<<d<<" ";
        }
        cout<<ln;
    }
    return 0;
}