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

// In this code, the queens are placed by the rows order

string board[8];
int marked[8][8];
//vi pos(8);
int ans = 0;

void mark(int r, int c){
    // mark column
    /*
    for(int i = r; i>=0; i--){
        marked[i][c]++;
    }
    */
    for(int i = r; i<8; i++){
        marked[i][c]++;
    }

    /*
    // mark first diagonal 
    for(int i = r-1, j = c-1; min(i, j)>=0; i--, j--){
        marked[i][j]++;
    }
    // mark second diagonal
    for(int i = r-1, j = c+1; i>=0 && j<8; i--, j++){
        marked[i][j]++;
    }
    */
    // mark third diagonal
    for(int i = r+1, j = c+1; max(i, j)<8; i++, j++){
        marked[i][j]++;
    }
    // mark fourth diagonal
    for(int i = r+1, j = c-1; i<8 && j>=0; i++, j--){
        marked[i][j]++;
    }

}

void deselect(int r, int c){
    /*
    // deselect column
    for(int i = r; i>=0; i--){
        marked[i][c]--;
    }
    */
    for(int i = r; i<8; i++){
        marked[i][c]--;
    }
    /*
    // deselect first diagonal 
    for(int i = r-1, j = c-1; min(i, j)>=0; i--, j--){
        marked[i][j]--;
    }
    // deselect second diagonal
    for(int i = r-1, j = c+1; i>=0 && j<8; i--, j++){
        marked[i][j]--;
    }
    */
    // deselect third diagonal
    for(int i = r+1, j = c+1; max(i, j)<8; i++, j++){
        marked[i][j]--;
    }
    // deselect fourth diagonal
    for(int i = r+1, j = c-1; i<8 && j>=0; i++, j--){
        marked[i][j]--;
    }
}

void toPlaceQueen(int r){
    if(r == 8){
        //for(auto i : pos) cout<<i<<' ';
        //cout<<ln;
        ans++;
        return;
    }
    for(int i = 0; i<8; i++){
        if(!marked[r][i]){
            mark(r, i);
            //pos[r] = i; 
            toPlaceQueen(r+1);
            deselect(r, i);
            //pos[r] = 0;
        }
    }
    return;
    
}
    

int main(){

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            marked[i][j] = 0;
        }
    }


    for(int i = 0; i<8; i++){
        cin >> board[i];
        for(int j = 0; j<8; j++){
            if(board[i][j]== '*'){
                marked[i][j]++;
            }
        }
    }

    for(int i = 0; i<8; i++){
        if(!marked[0][i]){
            mark(0, i);
           // pos[0] = i; 
            toPlaceQueen(1);
            deselect(0, i);
        }
    }
    cout<<ans<<ln;

    return 0;
    
}