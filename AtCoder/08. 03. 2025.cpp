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
 
const int M = 1e9+7;
ll mn = LONG_LONG_MAX;
ll a[10][10];
int visited[10];
//vi P;


void DFS(int node, int n, ll w){ 
    if(node == n-1){
        mn = min(mn, w);
       // if(mn == w) P=p;
        return;
    }
    for(int i = 0; i<n; i++){
        if(a[node][i]>=0 && !visited[i]){
            w^=a[node][i];
            visited[i] = 1;
            //p.pb(i+1);
            DFS(i, n, w);
            w^=a[node][i];
            visited[i] = 0;
            //p.pop_back();
        }
    }
}
    
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n, m; cin >> n >> m;
    memset(a, -1, sizeof(a));
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i<m; i++){
        ll u, v, w; cin >> u >> v >> w; 
        a[u-1][v-1] = w;
        a[v-1][u-1] = w;
    }
    visited[0] = 1;
   // P.pb(1);
    DFS(0, n, 0);
    cout<<mn<<ln;
    //for(auto i: P) cout<<i<<" ";
    return 0;
}