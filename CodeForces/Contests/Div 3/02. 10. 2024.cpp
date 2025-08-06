#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    

    int t; cin>>t;
    while(t--){
        int n, m, k; cin>> n >> m >> k;
        int w; cin>>w; 
        priority_queue<int> pq;
        for(int i = 0; i<w; i++){
            int g; cin>>g;
            pq.push(g);
        }
        
        int grid[n][m] = {};
        for(int x = 0; x<n; x++){   // It moves first through the columns
            for(int y = 0; y<m; y++){
                int lbx = max(0, x-k+1), upx = min(x, n-k);
                int lby = max(0, y-k+1), upy = min(y, m-k);
                int numSq = (upx-lbx+1)*(upy-lby+1);
                grid[x][y] = numSq;
            }
        }

        priority_queue<int> pqK;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                pqK.push(grid[i][j]);
            }
        }
        ll ans = 0;
        while(!pq.empty()){
            ll currentG = pq.top();
            ll currentS = pqK.top();
            pq.pop(); pqK.pop();
            ans+=(currentG*currentS);
        }
        cout<<ans<<ln;
    }
    return 0;
}