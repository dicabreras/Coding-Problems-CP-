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
        int a[n]; 
        map<int, int> m;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]] = 1;
        }
        int f = 0;
        for(int i = 0; i<n; i++){
            int x1 = a[i] + k, x2 = a[i] - k;
            if(m.count(x1) || m.count(x2)){
                f = 1;
                break;
            }
        }
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;

    }
    return 0;
}