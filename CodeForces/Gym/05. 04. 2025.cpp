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
        int n, k, f = 1; cin >> n >> k; 
        if(k == 1 && n!=1){
            int x = sqrt(n);
            int sieve[x+1] = {};
            sieve[1] = 1;
            for(int i = 2; i<=x; i++){
                if(sieve[i]) continue;
                for(int j = i*2; j<=x; j+=i){
                    sieve[j] = 1;
                }
            }
            for(int i = 2; i<=x; i++){
                if(!sieve[i] && n%i == 0) f = 0;
            }
        }
        else if(n==1 && k==2) f = 1;
        else f = 0;
 
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;
    }
    return 0;
}