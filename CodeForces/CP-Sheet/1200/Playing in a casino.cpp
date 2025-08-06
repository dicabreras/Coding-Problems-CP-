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
        int n, m; cin >> n >> m;
        ll a[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin >> a[i][j];
            }
        }
        ll sum = 0;
        for(int j = 0; j<m; j++){
            ll temp[n] = {};
            for(int i = 0; i<n; i++){
                temp[i] = a[i][j];
            }
            sort(temp, temp+n);
            for(ll i = 1; i<n; i++){
                ll x = temp[i]-temp[i-1];
                sum+=(i*(n-i)*x);
            }
        }
        cout<<sum<<ln;
        
    }
    return 0;
}