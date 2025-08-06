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
        int odds = 0, even = 0;
        ll mx = 0, sum = 0;
        for(int i = 0; i<n; i++){
            ll x; cin >> x;
            if(x%2 == 1) odds++;
            else even++;
            mx = max(x, mx);
            sum+=x;
        }
        if(!even || !odds){
            cout<<mx<<ln;
        }
        else{
            odds--;
            sum-=odds;
            cout<<sum<<ln;
        }
    }
    return 0;
}