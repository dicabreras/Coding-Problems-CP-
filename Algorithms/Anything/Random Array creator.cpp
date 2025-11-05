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
    ll n; cin>> n; 
    ll A[n]; 
    
    for(ll i = 0; i<n; i++){
        A[i] =random(0,100);
    }    
    for(auto c : A) cout<<c<<" ";
    cout<<ln;
    return 0;
}