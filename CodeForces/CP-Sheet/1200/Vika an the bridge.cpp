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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        map<int, vi> m1; 
        for(int i = 0; i<n; i++){
            int x;
            cin >> x;
            if(!m1.count(x)) m1[x].pb(-1);
            m1[x].pb(i);
        }
        map<int, pi> m2;
        for(auto x : m1){
            x.ss.pb(n); // last plank
            int N = x.ss.size();
            vi temp = x.ss, d;
            for(int i = 0; i+1<N; i++){
                d.pb(temp[i+1]-temp[i]);
            }
            sort(d.rbegin(), d.rend());
            m2[x.ff].ff = d[0];  // first max
            m2[x.ff].ss = d[1];  // second max
        }
        int mn = 1e6; 
        for(auto x : m2){
            pi p = x.ss;
            if(p.ff%2) p.ff++;
            int i = max(p.ss-1, p.ff/2-1);
            mn = min(mn, i);
        }
        cout<<mn<<ln;
    }
    return 0;
}