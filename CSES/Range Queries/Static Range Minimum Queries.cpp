/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
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

    int n, q;
    cin >> n >> q;  
    vector<vi> st;
    vi current; 
    for(int i = 0; i<n; i++){
        int x; 
        cin >> x;
        current.push_back(x);
    }
    st.push_back(current);
    
    // Building the sparse table
    for(int p = 1, i = 1; n-p>=0; p*=2, i++){
        current.clear();
        for(int j = 0; j+p<n-p+1; j++){
            int mn = min(st[i-1][j], st[i-1][j+p]);
            current.push_back(mn);
        }
        st.push_back(current);
    }
    while(q--){
        int l, r;
        cin >> l >> r; 
        int d = r-l+1, p = -1;
        while(d>0){
            p++;
            d = d>>1;
        }
        int ans = min(st[p][l-1] , st[p][r-(1<<p)]);
        // cout<<(1<<p)<<ln; This is a way to do 2^p;
        cout<<ans<<ln;
    }
    

    return 0;
}
