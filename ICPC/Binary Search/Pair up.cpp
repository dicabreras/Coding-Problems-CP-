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

int main() {
    // Abrir archivos para entrada y salida
    ifstream fin("pairup.in");  // Leer desde pairup.in
    ofstream fout("pairup.out"); // Escribir en pairup.out

    int n;
    fin >> n;  // Leer el número de líneas
    vector<pi> v; 

    for (int i = 0; i < n; i++) {
        int x, y; fin >> x >> y;
        v.pb({y,x});
    }

    sort(v.begin(), v.end());
    int mx = 0 , l = 0, r = n-1;
    while(l<r){
        pi p1 = v[l], p2 = v[r];
        if(p1.ss>p2.ss){
            p1.ss = p1.ss-p2.ss;
            v[l] = {p1.ff, p1.ss};
            r--;
        }
        else if(p1.ss<p2.ss){
            p2.ss = p2.ss -p1.ss;
            v[r] = {p2.ff, p2.ss};
            l++;
        }
        else{
            l++;
            r--;
        }
        mx = max(mx, p1.ff+p2.ff);
    }

    fout << mx << ln;  // Imprimir resultado en pairup.out

    // Cerrar los archivos
    fin.close();
    fout.close();

    return 0;
}