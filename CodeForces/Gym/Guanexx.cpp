// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'

int visited[25007] = {};
vector<int> adj[25007];

void dfs(int node){
    for(auto i : adj[node]){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
        }
    }
}


int main() {
    int n, m; 
    cin >> n >> m;
    //vector<int> adj[n*m];
    string s[n];
    for(int i = 0; i<n; i++){
        cin >> s[i];
    }
    int solo = 0, num = 0;
    for(int i = 0, j = 0; i<n; i++){
        cout<<"j: "<<j<<ln;
        for(int k = 0; k<m; k++, j++){
            int f = 0;
            if(s[i][k] == '#') continue;
            if(i>0 && s[i-1][k] == '.'){
                // UP
                f = 1;
                adj[j].push_back(j-m);
            }
            if(k-1<m && s[i][k+1] == '.'){
                // RIGHT
                f = 1;
                adj[j].push_back(j+1);
            }
            if(i+1<n && s[i+1][k] == '.'){
                //DOWN
                f = 1;
                adj[j].push_back(j+m);
            }
            if(k-1>=0 && s[i][k-1] == '.'){
                //LEFT
                f = 1;
                adj[j].push_back(j-1);
            }
            if(!f) solo++;
            else num++;
        }
    }
    int components = 0;
    for(int i = 0; i<n*m; i++){
        if(!visited[i]){
            dfs(i);
            components++;
        }
    }
    int ans = 200*(num-components) + num*100 + solo*100;
    cout<<ans<<ln;

    /*
    for(int i = 0; i<n*m; i++){
        cout<<i<<": ";
        for(auto node : adj[i]){
            cout<<node<<" ";
        }
        cout<<ln;
    }
    */


    return 0;
}
