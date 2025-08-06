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

#define between(a, b, c) (a<=b && b<=c)   //Validate position
int drX[]={-1,1,0,0}, drY[]={0,0,-1,1}; // drX hotizontal movements --> columns in a matrix
                                        // drY vertical movements --> rows in a matrix

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;


int visited[100005] = {};
vector<int> adj[100005];
int n, m;

void dfs(int i){
    vi v = adj[i];
    for(auto j : v){
        if(!visited[j]){
            visited[j] = 1;
            dfs(j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int h, k; cin >> h >> k;
        adj[h].pb(k);
        adj[k].pb(h);
    }
    int components = 0, prev = 0;
    vector<pi> edges;
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            visited[i] = 1;
            if(prev>0){
                edges.pb({prev, i});
            }
            dfs(i);
            components++;
            prev = i;
        }
    }
    cout<<components-1<<ln;
    for(auto p : edges){
        cout<<p.ff<<" "<<p.ss<<ln;
    }
    

    return 0;
}