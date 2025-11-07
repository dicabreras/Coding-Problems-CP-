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
    string a[n];
    int pfx_sum[n][n] = {};
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i+1<n; i++){
        for(int j = 0; j+1<n; j++){
            if(a[i][j] == '.' && a[i+1][j] == '.' && a[i][j+1] == '.' && a[i+1][j+1] == '.'){
                if(j==0){
                    pfx_sum[i][j] = 1;       
                }
                else{
                    pfx_sum[i][j] = pfx_sum[i][j-1]+1;
                }
            }
            else{
                pfx_sum[i][j] = (j>0)*pfx_sum[i][j-1];
            }
        }
        pfx_sum[i][n-1] = pfx_sum[i][n-2];
    }
    while(q--){
        int u, d, l, r; 
        cin >> u >> d >> l >> r;
        u--;
        d--;
        r--;
        l--;
        int ans = 0;
        for(int i = u; i<d; i++){
            ans+=(pfx_sum[i][r-1]- (l>0)*pfx_sum[i][l-1]);
        }
        cout<<ans<<ln;
    }

    return 0;
}
