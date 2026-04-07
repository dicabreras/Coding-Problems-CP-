/*
Coded by Diego Cabrera
Codeforces username: CaSala
Problem: https://codeforces.com/contest/1063/problem/B
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

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */

    int n, m, rw, cl, l, r;
    cin >> n >> m >> rw >> cl >> l >> r;
    rw--;
    cl--;
    int visited[n][m] = {}, ans = 1;
    vector<vector<pi>> state (n, vector<pi> (m));
    vector<vi> g(n, vi (m));
    for(int i = 0; i<n; i++){
        string s; 
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] == '*'){
                g[i][j] = 1;
            }
            state[i][j] = {-1, -1};
        }
    }

    queue<vi> q;
    q.push({rw,cl,l,r});
    visited[rw][cl] = 1;
    state[rw][cl] = {l, r};

    function<bool(int, int)> valid = [&](int x, int y){ //column, row
        if(!between(0,x,m-1) || !between(0, y, n-1) || g[y][x]){
            return false;
        }
        else{
           return true;
        }

    };

    while(!q.empty()){
        vi current = q.front();
        int row = current[0], column = current[1], L = current[2], R = current[3];
        q.pop();
        for(int i = 0; i<4; i++){
            if(valid(column + dx[i], row + dy[i]) && (state[row+dy[i]][column+dx[i]].ff < L || state[row+dy[i]][column+dx[i]].ss < R)){
                int op_l = L, op_r = R;
                if(i == 2){
                    op_l--;
                    if(op_l<0) continue;
                }
                else if(i == 3){
                    op_r--;
                    if(op_r<0) continue;
                }
                q.push({row+dy[i], column+dx[i], op_l, op_r});
                
                state[row + dy[i]][column + dx[i]].ff = op_l;
                state[row + dy[i]][column + dx[i]].ss = op_r;
                if(!visited[row + dy[i]][column + dx[i]]) ans++;
                visited[row+dy[i]][column+dx[i]] = 1;
            }
        }
    }

    cout<<ans;

    return 0;
    
}