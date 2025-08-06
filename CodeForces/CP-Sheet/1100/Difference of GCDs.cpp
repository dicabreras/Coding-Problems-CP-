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
        int n, l, r, f = 1; cin >> n >> l >> r;
        int a[n];
        for(int i = 1; i<=n; i++){
            int q = (l-1)/i + 1, m = q*i;
            if(m>r){
                f = 0;
                break;
            }
            a[i-1] = m;
        }
        if(f){
            cout<<yes<<ln;
            for(auto i : a) cout<<i<<" ";
            cout<<ln;
        }
        else cout<<no<<ln;
    }
    return 0;
}