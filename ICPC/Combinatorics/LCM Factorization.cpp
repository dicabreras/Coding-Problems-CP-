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
const ll M1 = 998244353;

ll fac[300010] = {}, inverses[300010]={};


// Binary exponentiation 
ll modinv(ll a, ll mod){
    ll res = 1, p = mod - 2;
    while(p){
        if(p&1) res = res * a%mod; // p&1 verifica si p es impar
        // si p es impar entonces result debe multiplicarse por 'a' una vez más 
        // sin importar la paridad de p, siempre estamos elevando el a (actual) al cuadrado
        a = a*a % mod;
        p>>=1;
    }
    return res;
}


ll factorial(ll n){
    if(n<0) return 1;
    if(fac[n]>0) return fac[n];
    fac[0] = 1;
    for(ll i = 1; i<=n; i++){
        if(!fac[i]){
            fac[i] = fac[i-1]*i;
            fac[i]%=M1;
        }
    }
    return fac[n];
}

ll comb(ll n, ll k){ 
    if(k>n) return 0;
    //ll p = fac[n], q0 = modinv(fac[k], M1), q1 = modinv(fac[n-k], M1);
    ll p = fac[n], q0 = inverses[fac[k]], q1 = inverses[fac[n-k]];
    p*=q0;
    p%=M1;
    p*=q1;
    p%=M1;
    return p;
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    factorial(3*1e5);
    for(ll i = 1; i<=3*1e5; i++){
        inverses[i] = modinv(i, M1);
    }
    // seeking primes until n; 
    int sieve[300007] = {}; 
    sieve[1] = 1; 
    for(int i = 2; i<=3*1e5; i++){
        if(!sieve[i]){
            for(int j = i+i; j<=3*1e5; j+=i){
                sieve[j] = 1; 
            }
        }
    }
    vector<ll> primes;
    for(ll i = 2; i<=3*1e5; i++){
        if(!sieve[i]) primes.pb(i);
    }
    while(t--){
        ll n, k; cin >> n >> k;
        ll a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        } 
       // vector<pair<ll, ll>> Np;
        map<ll, ll> Np; 
        
        for(auto i : a){
            ll x = sqrt(i), j = 0, f = 0;
           // cout<<"ai:  "<<i<<ln;
            //cout<<"raiz de ai:   "<<x<<ln;
            while(primes[j]<=x){
              //  cout<<"primo:  "<<primes[j]<<ln;
                if(i%primes[j] == 0){
                    Np[primes[j]]++;
                    f = 1;
                }
                j++; 
            }
            if(!f && i>1) Np[i]++; // ai was a prime
        }

        int N = Np.size();
        //ll nf = factorial(n), kinv = modinv(k, M1), kninv = modinv(n-k, M1);
        //ll total_sub = nf*kinv*kninv;
        ll total_sub = comb(n, k);
        total_sub%=M1;
        ll ans = 0; 
        for(auto [p, cnt] : Np){
            //ll p = Np[i].ff, np = Np[i].ss;
            //ll q = modinv(n-np-k, M1)%M1;
            //ll temp = factorial(n-np)/q;
            //cout<<"prime:   "<<p<<"    cnt:   "<<cnt<<ln;
            ll temp = comb(n-cnt, k);
            temp%=M1;
            ll y = total_sub - temp;
            ans+=(y*p)%M1;
            ans%=M1;
        }
        cout<<ans<<ln;
    }
    return 0;
}