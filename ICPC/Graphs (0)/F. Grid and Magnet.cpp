#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc351/tasks/abc351_d
// time complexity of this algorithm is O(n*m)

#define between(a, b, c) (a<=b && b<=c)
#define ff first
#define ss second

using ll = long long;
const int N = 1010;

// Moving in cicle from left to right
int drX[] = {0, -1, 0, 1};  //it defines moves on the rows, i.e., up and donwn (U&D)
int drY[] = {-1, 0, 1, 0};  // It defines moves on the columns, i.e., left and right (L&R)


int n, m;
vector<string> grid;
int marked[N][N];


bool IsValid(int x, int y){
    if(!between(0, x, n-1) || !between(0, y, m-1)){
        return false;
    }
    else return true; 
}

bool CanMove(int x, int y){  
    for(int i = 0; i<4; i++){
        int k = x+drX[i], h = y+drY[i];
        if(IsValid(k, h) && grid[k][h] == '#') return false;
    }
    return true;
}


int main()
{
    cin>> n >> m;
    grid.resize(n);

    int ans = 1;
    memset(marked, 0, sizeof(marked));
    for(int i = 0; i<n; i++)cin>>grid[i];
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] != '#'){
                int visited[n][m];
                memset(visited, 0, sizeof(visited));
                visited[i][j]=1;
                int squares = 1; 
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    pair<int, int> current = q.front();
                    q.pop();
                    int x = current.ff, y = current.ss; 
                    if(CanMove(x, y)){
                        for(int k = 0; k<4; k++){
                            pair<int, int> node;
                            node.ff = x+drX[k]; node.ss = y+drY[k];
                            if(visited[node.ff][node.ss] == 0 && IsValid(node.ff, node.ss)){
                                q.push(node); 
                                squares++;
                                visited[node.ff][node.ss] = 1;
                            } 
                        }
                    }
                    else{
                        marked[x][y]=1; // can not do any move
                        if(!visited[x][y]){
                            squares++;
                            visited[x][y]=1;
                        }
                    } 
                }
                if(squares>ans) ans = squares;
            }
        }
    }
    cout<<ans;

    
    return 0;
}
