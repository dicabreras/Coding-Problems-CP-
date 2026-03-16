/*
Coded by Diego Cabrera
Codeforces username: CaSala
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

int n, a[200007];
vector<vi> g (200007);
set<int> s, ans;
int visited[200007] = {}, f = 0;


void dfs(int node){
    for(auto u : g[node]){
        int temp = a[u];
        
        if(visited[u]) continue;
        if(f>0) ans.insert(u);
        if(s.count(a[u])){
            ans.insert(u);
            f = u;
        }
        s.insert(a[u]);
        visited[u] = 1;
        dfs(u);
        s.erase(a[u]);
        if(f == u) f = 0;
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
    
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i<n-1; i++){
        int u, v; 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
   // cout<<"tes"<<ln;

    for(int i = 1; i<=n; i++){
        sort(g[i].begin(), g[i].end());
    }
    /*
    for(int i = 0; i<=n; i++){
        cout<<"node "<<i<<": ";
        for(auto j : g[i]){
            cout<<j<<" ";
        }
        cout<<ln;
    }*/
    s.insert(a[1]);
    visited[1] = 1;
    dfs(1);
    for(int i = 1; i<=n; i++){
        if(ans.count(i)) cout<<"Yes"<<ln;
        else cout<<"No"<<ln;
    }

   

    return 0;
}