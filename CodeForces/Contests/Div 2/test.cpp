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

    int n, m;
    cin >> n >> m;
    int g[n+1][n+1] = {}, visited[n+1];
    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;

    }
    memset(visited, -1, sizeof(visited));
    int ans = 0;

    
    for(int i = 1; i<=n; i++){
        if(visited[i]>=0) continue; // checking componenets
        visited[i] = 0;
        queue<int> q, level;
        q.push(i);
        level.push(0);
        while(!q.empty()){
            int current = q.front(), l = level.front();
            q.pop();
            level.pop();

            for(int j = 1; j<=n; j++){
                if(g[current][j] && visited[j] == -1){
                    q.push(j);
                    level.push(l+1);
                    visited[j] = l+1;
                }
                else if(g[current][j] && (visited[j] + l+1)%2){
                    ans++;
                }
            }
        }
    }
    cout<<ans/2;

    return 0;
}
