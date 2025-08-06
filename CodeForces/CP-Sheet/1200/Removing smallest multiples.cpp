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
        int n; cin >> n;
        string b; cin >> b;
        int a[n+1]={};
        for(ll i = 0; i<n; i++){
            if(b[i] == '0'){
                a[i+1] = 1;
            }
        }
        ll ans = 0;
        for(int i = 1; i<=n; i++){
            for(int j = i; j<=n; j+=i){
                if(!a[j])break;
                else if(a[j]==1){
                    ans+=i;
                    a[j]++;
                }
            }
        }
        cout<<ans<<ln;
    }
    return 0;
}