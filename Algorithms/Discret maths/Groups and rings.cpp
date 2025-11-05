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

const int M = 1e9+7;

vi eratosthenes_sieve, n_primes;
vector<pi> n_factorization;


int n_square(int n){
    int l = 0, r = n;
    while(l+1<r){
        int mid = l + (r-l)/2;
        if(mid*mid<=n) l = mid;
        else r = mid;
    }
    return l;
}


void primes(int n){
    int sq = n_square(n);
    eratosthenes_sieve.resize(sq+1, 0);
    for(int i = 2; i<sq+1; i++){
        if(eratosthenes_sieve[i] == 0){
            n_primes.push_back(i);
            for(int j = i; j<sq+1; j+=i){
                eratosthenes_sieve[j] = 1;
            }
        }
    }
}

void factorization(int n){
    primes(n);
    for(auto p : n_primes){
        if(n%p>0) continue; 
        int ex = 0;
        while(n%p == 0){
            n/=p;
            ex++;
        }
        n_factorization.push_back({p, ex});
    }
    if(n>1) n_factorization.push_back({n, 1});
}


int main()
{
    int entero, mx = 0;
    cout<<"Ingresar un entero n para obtener el número automorifismos de Z_n (salvo isomorfismos)"<<endl;
    cin>>entero;
    factorization(entero);
    vi exponents;
    cout<<"Factorización del entero n = "<< entero<<ln;
    for(auto p : n_factorization){
        exponents.push_back(p.ss);
        mx = max(mx, p.ss);
        cout<<p.ff<<"^"<<p.ss<<",  ";
    }
    cout<<ln;
    ll suma=0;
    ll a[mx+1][mx+1];
    ll particiones = 0;

    for(int i=0; i<mx+1;i++){
        for(int j=0; j<mx+1;j++){
            a[i][j]=0;
        }
    }

    a[0][0]=1;
    for (int i=1; i<=mx; i++){
       // particiones=0;
        for (int j=0; j<i; j++){
            for(int k=0; k<j+1; k++){
                suma+=a[i-j-1][k];
            }
            a[i][j]=suma;
            suma=0;
        }
    }
    
    for (int i=0; i<mx+1;i++){
        for(int j=0;j<i+1;j++){
            cout<<a[i][j]<<" ";
            
        }
        cout<<endl;
    }
    
    ll auotmorfismos = 1;

    for(auto ex : exponents){
        particiones = 0;
        for(int i = 0; i<ex; i++){
            particiones+=a[ex][i];
        }
        auotmorfismos*=particiones;
    }
    if(exponents.size()>1) auotmorfismos++;

    /*
    for (int i=0; i<entero; i++){
        particiones+=a[entero][i];
    }
    cout<<"El número de particiones del entero "<<entero<<" es: "
    <<particiones;
    */
    cout<<"El número de automorfismos de Z_"<<entero<<" son: "<<auotmorfismos<<ln;   

    return 0;
}