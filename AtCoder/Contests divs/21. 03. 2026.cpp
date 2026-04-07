    /*
Coded by Diego Cabrera
Codeforces username: CaSala
Problem: https://atcoder.jp/contests/abc449/tasks/abc449_c
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
#define between(a, b, c) (a<=b && b<=c)

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

int g[1005][1005] = {};
int visited[1005][1005] = {};
int h, w;
bool f;

bool valid(int r, int c){
    if(between(0, r, h) && between(0, c, w) && g[r][c]){
        return true;
    }
    else return false;
}

bool dfs(int r, int c){
    for(int i = 0; i<4; i++){
        if(valid(r+dy[i], c + dx[i]) && !visited[r+dy[i]][c+dx[i]]){
            visited[r+dy[i]][c+dx[i]] = 1;
            f = dfs(r+dy[i], c+dx[i]);          
        }
        if(r == 0 || r == h-1 || c == 0 || c == w-1){
           f = false;
        }
    }
    return f;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    cin >> h >> w;
    queue<pi> white;
    for(int i = 0; i<h; i++){
        string s;
        cin >> s;
        for(int j = 0; j<w; j++){
            if(s[j] == '.'){
                g[i][j] = 1;
                white.push({i, j});
            }
        }
    }
    int ans = 0;
    while(!white.empty()){
        pi current = white.front();
        white.pop();
        if(visited[current.ff][current.ss] || !valid(current.ff, current.ss)) continue;
        visited[current.ff][current.ss] = 1;
        f = true;
        f = dfs(current.ff, current.ss);
        if(f) ans++;
    }
    cout<<ans;

    return 0;
}