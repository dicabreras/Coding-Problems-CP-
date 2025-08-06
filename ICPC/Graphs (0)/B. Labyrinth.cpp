#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ff first 
#define ss second
#define pb push_back

// https://cses.fi/problemset/task/1193
// Here the idea behind is to make a BFS applying a queue

#define between(a, b, c) (a<=b && b<=c)   //Validate position
int drX[]={-1,1,0,0}, drY[]={0,0,-1,1};

const int N = 1001;
const string moves = "UDLR"; // It is coherent with the way directions are defined in drX, drY
int n, m;
vector<string> grid;
char path[N][N] = {}; 
int visited[N][N] = {};
string coordinates = "";
int shortest_path = 0;

bool IsValid(int x, int y){
    if(!between(0, x, n-1) || !between(0, y, m-1) || visited[x][y] == 1 || grid[x][y]=='#')
        return false;
    
    else return true;
}

bool found(int x, int y){
    if(grid[x][y]=='B') return true;
    else return false;
}

void FindingPath(int x, int y){
    if(grid[x][y]=='A') return;
    if(path[x][y] == 'R'){
        coordinates+='R';
        shortest_path++;
        return FindingPath(x, y-1);
    }
    if(path[x][y] == 'L'){
        coordinates+='L';
        shortest_path++;
        return FindingPath(x, y+1);
    }
    if(path[x][y] == 'U'){
        coordinates+='U';
        shortest_path++;
        return FindingPath(x+1,y);
    }
    if(path[x][y] == 'D'){
        coordinates+='D';
        shortest_path++;
        return FindingPath(x-1, y);
    }
}

int main()
{
    cin>> n >>m; 
    grid.resize(n);
    memset(visited, 0, sizeof(visited)); // try to change the last parameter
    memset(path, '#', sizeof(path)); 
    pair<int, int> start, end;
    bool flag = false;

    for(int i = 0; i<n; i++){
        string s; cin>>s;
        if(!flag){
            for(int j = 0; j<m; j++){
                if(s[j] == 'A'){
                    start.ff=i; start.ss = j;
                    flag = true;
                }
            }
        }
        grid[i] = s;
    }

    queue<pair<int, int>> q; 
    q.push(start);
    visited[start.ff][start.ss] = 1;
    flag = true;
    while(!q.empty() && flag){
        pair<int, int> current = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int x = current.ff, y = current.ss;

            if(IsValid(x+drX[i], y+drY[i])){
                pair<int, int> nodo;
                nodo.ff = x+drX[i]; nodo.ss = y+drY[i];
                path[nodo.ff][nodo.ss] = moves[i];  //saving direction
                visited[nodo.ff][nodo.ss]=1;
                q.push(nodo);
                if(found(nodo.ff, nodo.ss)){
                    end.ff = nodo.ff; end.ss = nodo.ss;
                    flag = false;
                    break;
                }
            }
        }
    }
/*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(path[i][j] == ' ')cout<<'#';
            else cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    if(flag) cout<<"NO\n";
    else{
        FindingPath(end.ff, end.ss);
        cout<<"YES\n"<<shortest_path<<'\n';
        for(int i = shortest_path-1; i>=0; i--) cout<<coordinates[i];
    }
     
    return 0;
}
