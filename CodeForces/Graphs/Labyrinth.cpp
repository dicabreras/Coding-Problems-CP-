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

int dx[] = {-1, 1, 0 , 0}, dy[] = {0, 0, 1, -1};


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
    int visited[n][m][4] = {}, ans = 1;
    vector<vi> g(n, vi (m));
    for(int i = 0; i<n; i++){
        string s; 
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] == '*'){
                g[i][j] = 1;
            }
        }
    }

    queue<vi> q;
    q.push({rw,cl,l,r});
    visited[rw][cl][0] = 1;

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
        int move[] = {L,R, 0, 0};
        q.pop();
        for(int i = 0; i<4; i++){
            if(valid(column + dx[i], row + dy[i])){
                if(visited[row + dy[i]][column + dx[i]][i]<move[i]){
                int op_l = L, op_r = R;
                if(i == 0){
                    op_l--;
                    if(op_l<0) continue;
                    visited[row + dy[i]][column + dx[i]][i] = op_l;
                }
                else if(i == 1){
                    op_r--;
                    if(op_r<0) continue;
                    visited[row + dy[i]][column + dx[i]][i] = op_r;
                }
                else{
                    visited[row + dy[i]][column + dx[i]][i] = 1;
                }
                q.push({row+dy[i], column+dx[i], op_l, op_r});
                int f = 0;
                for(int j = 0; j<4; j++){
                    if(visited[row+dy[i]][column+dx[i]][j]) f++;
                    cout<<visited[row+dy[i]][column+dx[i]][j]<<ln;
                    
                }
                if(f>1) continue;
                ans++;
            }
        }
    }
    

    cout<<ans;

    return 0;
    
}


