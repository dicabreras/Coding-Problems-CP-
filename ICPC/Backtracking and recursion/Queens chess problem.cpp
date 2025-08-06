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

// in this problem it is required to mark the four diagonals, since the queens
// aren't placed in a certain order. 

const int M = 1e9+7;
int R, C;
int marked[9][9];
vector<vi> configurations;
vi positions(9);

void mark(int r, int c){
    // mark column
    for(int i = r; i > 0; i--){
        marked[i][c]++;
    }
    
    for(int i = r+1; i < 9; i++){
        marked[i][c]++;
    }

    // mark first diagonal
    for(int i = r-1, j = c-1; min(j, i) > 0; j--, i--){
        marked[i][j]++;
    }
    // mark second diagonal
    for(int i = r-1, j = c+1; j<9 && i>0; j++, i--){
        marked[i][j]++;
    }
    // mark third diagonal
    for(int i = r+1, j = c+1; i<9 && j<9; i++, j++){
        marked[i][j]++;
    }
    // mark fourth diagonal 
    for(int i = r+1, j = c-1; i<9 && j>0; i++, j--){
        marked[i][j]++;
    }

}

void deselect(int r, int c){
    // deselect column
    for(int i = r; i > 0; i--){
        marked[i][c]--;
    }
    
    for(int i = r+1; i < 9; i++){
        marked[i][c]--;
    }

    // deselect first diagonal
    for(int i = r-1, j = c-1; min(j, i) > 0; j--, i--){
        marked[i][j]--;
    }
    // deselect second diagonal
    for(int i = r-1, j = c+1; j<9 && i>0; j++, i--){
        marked[i][j]--;
    }
    // deselect third diagonal
    for(int i = r+1, j = c+1; i<9 && j<9; i++, j++){
        marked[i][j]--;
    }
    // deselect fourth diagonal 
    for(int i = r+1, j = c-1; i<9 && j>0; i++, j--){
        marked[i][j]--;
    }

}

void toPlaceDown(int r){
    if(r == 9){
        configurations.pb(positions);
        return;
    }
    
    for(int j = 1; j<9; j++){
        if(!marked[r][j]){
            mark(r, j);
            positions[j] = r;
            toPlaceDown(r+1);
            deselect(r, j);
        }
    }
    return;

}

void toPlaceUp(int r){
    if(r == 0){
        toPlaceDown(R+1);
        return;
    }
    
    for(int j = 1; j<9; j++){
        if(!marked[r][j]){
            mark(r, j);
            positions[j] = r;
            toPlaceUp(r-1);
            deselect(r, j);
        }
    }
    return;
    
}

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   /* 
    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        cin >> R >> C;
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                marked[i][j] = 0;
            }
        }
        positions[C] = R;
        mark(R, C);
        toPlaceUp(R-1);
        sort(configurations.begin(), configurations.end());
        
        printf("SOLN       COLUMN\n");
        printf(" #      ");
        for (int i = 1; i < 8; i++) {
            printf("%d ", i);
        }
        printf("8\n\n"); // Cambiar 'ln' por '\n' para salto de línea doble

        for (int i = 1; i <= (int) configurations.size(); i++) {
            if (i < 10) {
                printf(" %d      ", i);
            } 
            else {
                printf("%d      ", i);
            }
        for (int j = 1; j < 8; j++) {
            printf("%d ", configurations[i - 1][j]);
        }
        printf("%d\n", configurations[i - 1][8]); // Último número en la fila
        }
        if(t>=1) printf("\n"); // Salto de línea al final
        configurations.clear();   
    }
    return 0;
}


