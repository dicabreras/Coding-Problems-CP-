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


int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int marked[8][8]={}, moves[8][8];
int f = 0;    

bool isValid(int x, int y){
    return between(0, x, 7) && between(0, y, 7) && !marked[x][y];
}

int knightMoves(int r, int c, int current){
    if(current == 64){
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++) {
                cout<<marked[i][j]<<" ";
        }
            cout<<ln;
        }
        //f = 1;
        return 1;
    }
    /*
    if(current == 63){
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++) {
                cout<<marked[i][j]<<" ";
        }
            cout<<ln;
        }
        cout<<"casi"<<ln;
    }
    */
    for(int i = 0; i<8 && !f; i++){
        int row = r+dy[i], column = c+dx[i];
        if(isValid(row, column)){
            marked[row][column] = current+1;
            if(knightMoves(row, column, current+1)) return 1;
            else marked[row][column] = 0;
        }
    }
    return 0;
}

int main(){
    int r, c; cin >> c >> r;
    r--;
    c--;
    
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            marked[i][j] = 0;
        }
    }
    marked[r][c] = 1;
    knightMoves(r, c, 1);

    return 0;
    
}