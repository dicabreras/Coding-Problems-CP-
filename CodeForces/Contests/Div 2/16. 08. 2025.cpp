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

    int n, m; cin >> n >> m;
    vector<int> adj [n+1];
    for(int i = 0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    /*
    for(auto x : adj){
        for(auto u : x) cout<<u<<" ";
        cout<<ln;
    }
    */
    queue<int> q;
    vector<set<int>> visited(n+1);
    queue<int> lvl;
    int ans[n] = {};
    q.push(1);
    lvl.push(0);
    while(!q.empty()){
        int u = q.front();
        int l = lvl.front();
        q.pop();
        lvl.pop();
        for(auto i : adj[u]){
            if(visited[u].count(i)) continue;
            if(i == n){
                ans[l+1]++;
                continue;
            }
            q.push(i);
            lvl.push(l+1);
            visited[u].insert(i);
        }
    }
    for(int i = 1; i<n; i++) cout<<ans[i]<<" ";
}