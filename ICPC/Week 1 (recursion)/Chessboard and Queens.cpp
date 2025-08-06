#include<bits/stdc++.h>
 
using namespace std;
 
int p[20], n = 8;
bool marked[20];
int bad[9][9];
 
bool check() { /// si la configuracion estaa bien
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(abs(i-j) == abs(p[i]-p[j])) {
                return false;
            }
        }
    }
    return true;
}
 
int ans;
void rec(int pos) { /// pos es en que posicion de la permutacion voy
    if(pos == n) { /// ya acabe de poner los elementos de la permutacion, caso base
        if(check()) ans++;
    } else { /// casos recursivo
        for(int i = 0; i < n; i++) {
            if(!marked[i] && !bad[pos][i]) { /// no esta marcado, lo puedo poner
                p[pos] = i;
                marked[i] = true;     
                rec(pos+1);             
                marked[i] = false;
            }
        }
    }
}
 
int main() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            if(c == '*')
                bad[i][j] = true;
        }
    }
 
    rec(0);
 
    cout << ans << endl;
}