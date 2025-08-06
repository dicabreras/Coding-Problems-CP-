#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;


// In this problem it is applied the small Fermats Theorem to avoid the division with
// modul, which does not hold for the equality --> (a/b)%n != (a%n) / (b%n);



/*
void f(){
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i<=1000000; i++){
        factorial[i] = factorial[i-1]*i;
        factorial[i]%=M;
    }  
} 
*/ 

/*

// This is a way to calculate a^b in O(log_{2} b) complexity. Quite usefull
ll modularBinaryExponentiation(ll a, ll x){
    if(x == 0) return 1;
    ll result = modularBinaryExponentiation(a, x/2);
    if(x/2 == 1){
        return (((result*result) % M) * a) % M;
    }
    else{
        return (result*result) % M;
    }
}
*/


struct Factorial{

    vector<ll> factorial;
    vector<ll> inverseFactorial;
    int modulo;
    // Method of the class
    // Declaring this method at this point of the class is strictly necessar due to its
    // use forward in the code when calculating the inverse factorial values
    // This is also a way to calculate a^b in O(log_{2} b) complexity. Quite usefull!!!
    ll modularBinaryExponetiation(int base, int exponent){
        if(exponent == 0){
            return 1;
        }
        ll result = modularBinaryExponetiation(base, exponent/2);
        if(exponent%2 == 1){
            return ((result*result)%modulo * base) % modulo;
        }
        else{
            return (result*result)%modulo;
        }
    }
    //This is the constructor of the class
    Factorial(int n, int _modulo){
        factorial.resize(n+1); 
        inverseFactorial.resize(n+1);
        modulo = _modulo;
        factorial[0] = 1;
        inverseFactorial[0] = 1; 
        // builinding the facotrial values
        // Moreover, the inverse factorial values are calculated taking into account the 
        // observarion of the small Fermat's Theorem
        for(int i = 1; i<=n; i++){
            factorial[i] = (factorial[i-1]*i) % modulo;
            inverseFactorial[i] = modularBinaryExponetiation(factorial[i], modulo-2);
        }
    }
    // Methods for obtaining the interested values
    // However these are never called in the main function or other methos inside the class
    int factorialOf(int x){
        return factorial[x];
    }
    int inverseFactorialOf(int x){
        return inverseFactorial[x];
    }
    int binomialCoefficientOf(int a, int b){
        return (((factorial[a]*inverseFactorial[a-b]) % modulo) * inverseFactorial[b]) % modulo;
    }

};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   /* #if LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    */

    int n; cin >> n;
    //It crates the object Factorial that is required to answer to all the queries
    Factorial fc = Factorial(1e6, 1e9+7); 
    while(n--){
        ll a, b; cin >> a >> b;
        cout<<fc.binomialCoefficientOf(a, b)<<ln;
    }   
    
    return 0;
}