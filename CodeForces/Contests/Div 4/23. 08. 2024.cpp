#include <bits/stdc++.h>
#include <random>
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

const int M = 1e9+7;


ll random(ll a, ll b){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dristrib(a,b);
    ll random_value = dristrib(gen);
    return random_value;
}




int main(){
    ll n, a, b; cin>> n >> a >> b; 
    ll A[n]; 
    ll mx = -1;
    
    for(ll i = 0; i<n; i++){
        A[i] =random(a,b);
        if(A[i]>mx) mx=A[i];
    }    
    
    ll C[mx+1]={}; //Initialize all vales equal 0
    
    for(int i = 0; i<n; i++) C[A[i]]++;
    
    for(int i = 0, j = 1; j<=mx; i++, j++) C[j]+=C[i]; // prefix sums
    
    ll B[n];
    for(int i = n-1; i>=0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    } 

    for(auto num : B) cout<< num << " ";
    cout<<"\n";

    return 0;
}