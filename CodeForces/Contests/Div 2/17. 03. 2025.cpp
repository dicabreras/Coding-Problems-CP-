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
        int n, m; cin >> n >> m;
        string a[n];
        int ones_r = 0, ones_c = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            int ones = 0;
            for(auto j : a[i]){
                if(j=='1') ones++;
            }
            ones_r+=(ones%2);
        }
        for(int j = 0; j<m; j++){
            int ones = 0;
            for(int i = 0; i<n; i++){
                if(a[i][j] == '1') ones++;
            }
            ones_c+=(ones%2);
        }
        cout<<max(ones_r, ones_c)<<ln;
    }
    return 0;
}

