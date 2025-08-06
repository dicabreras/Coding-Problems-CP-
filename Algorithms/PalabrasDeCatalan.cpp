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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

vector<vi> palabras;

void PalabrasCatalan(vi a, int i, int n, int x){
    if(i == n){
        for(int j = 1; j<=x+1; j++){
            a.pb(j);
            palabras.pb(a);
            a.pop_back();
        }
        return;
    }
    for(int j = 1; j<=x+1; j++){
        a.pb(j);
        PalabrasCatalan(a, i+1, n, j);
        a.pop_back();
    }
    return;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n = 5;
    vi a; 
    a.pb(1);
    PalabrasCatalan(a, 2, n, 1);
    
    for(auto i: palabras){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<ln;
    }
    cout<<"Cantidad de palabras de Catalan de longitud "<<n<<" :  "<<palabras.size()<<ln;
    return 0;

}