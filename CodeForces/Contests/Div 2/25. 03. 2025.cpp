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
        int n; cin >>n;
        int sieve[n+1] = {};
        sieve[1] = 1;
        int x = sqrt(n);
        for(int i = 2; i<=x; i++){
            if(sieve[i] == 0){
                for(int j = i*2; j<=n; j+=i){
                    sieve[j]=1;
                }
            }
        }
        vector<ll> primes;
        for(int i = 1; i<=n; i++){
            if(sieve[i] == 0) primes.pb(i);
        }
        ll ans = 0;
        for(auto p : primes){
            ll y = n/p;
            ans+=y;
        }
        cout<<ans<<ln;
    }
    return 0;
}