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
        int n; cin >> n;
        int a[n];
        map<int, int> m;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]] = max(m[a[i]], i);
        }
        int mx = 0;
        for(auto p : m){
            for(auto q : m){
                if(gcd(p.ff, q.ff) == 1){
                    mx = max(mx, p.ss + q.ss);
                }
            }
        }
        if(!mx) cout<<-1<<ln;
        else cout<<mx+2<<ln;
    }
    return 0;
}