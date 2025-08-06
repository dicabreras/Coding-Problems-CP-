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


int adj[1000][1000] = {};
char pos[1000][1000];
int n, m;

int f(){

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
    string c; 
    pi s, e;
    for(int i = 0; i<n; i++){
        cin >> c;
        for(int j = 0; j<m; j++){
            if(c[j] == '#') adj[i][j] = -1;
            if(c[j] == 'A'){
                s.ff = i;
                s.ss = j;
                adj[i][j] = 1;
            }
            if(c[j] == 'B'){
                e.ff = i;
                e.ss = j;
                //adj[i][j] = 2;
            }
        }
    }
    int len = 0;
    queue<pi> q;
    queue<int> lvl;
    q.push(s);
    lvl.push(1);
    while(!q.empty()){
        pi current = q.front();
        int l = lvl.front();
        q.pop();
        lvl.pop();
        int x = current.ss, y = current.ff;
        for(int i = 0; i<4; i++){
            // k columns ; h rows;
            int k = drX[i], h = drY[i];

            if(between(0, x+k, m-1) && between(0, y+h, n-1) && adj[y+h][x+k] == 0){
                q.push({y+h, x+k});
                lvl.push(l+1);
                char mov;
                if(i == 0) mov = 'L';
                else if(i == 1) mov = 'R';
                else if(i == 2) mov = 'U';
                else mov = 'D';
                pos[y+h][x+k] = mov;
                adj[y+h][x+k] = 1;
            }

            if(y+h == e.ff && x+k == e.ss){
                len = l;
                while(!q.empty()) q.pop();
                break;
            }
        }
        
    }
    if(len>0){
        string path = "";
        int f = 0, y = e.ff, x = e.ss;
        while(f<len){
            char mov = pos[y][x];
            if(mov == 'U') y++;
            else if(mov == 'D') y--;
            else if(mov == 'L') x++;
            else x--;
            path.pb(mov);
            f++;
        }
        reverse(path.begin(), path.end());
        cout<<yes<<ln;
        cout<<len<<ln;
        cout<<path;
    }
    else{
        cout<<no;
    }
    return 0;
}