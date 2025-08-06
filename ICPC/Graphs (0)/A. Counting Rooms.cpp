#include <bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1192/

// Solving a Flood Fill problem, which means that are given an unexplicit
// graph, for example a grid.
int n, m;
vector<vector<bool>> visited;
vector<string> grid;

#define between(a, b, c) (a<=b && b<=c)  //technic for creating short functions


int i[] = {-1, 1, 0, 0};
int j[] = {0, 0, -1, 1};

void FloodFill(int x, int y){
    if(!between(0, x, n-1) || !between(0, y, m-1) || visited[x][y] || grid[x][y]=='#'){
        return;
    }
    visited[x][y]=1;

    for(int k = 0; k<4; k++) FloodFill(x+i[k], y+j[k]);
}


int main()
{
    cin>> n >> m;
    grid.resize(n);
    visited.resize(n, vector<bool>(m, false)); //really important
    //to define the vector variable type "vector<bool>(m "size", "variable type"vector<bool>(m "size", false "type"))"
    for(int i = 0; i<n; i++){
        cin>>grid[i];
    }

    int rooms = 0;
    for(int x = 0; x<n; x++){
        for(int y = 0; y<m; y++){
            if(!visited[x][y] && grid[x][y]!='#') {
                FloodFill(x, y);
                rooms++;
            }
        }
    }
    
    cout<<rooms;

    return 0;
}
