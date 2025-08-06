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

int main(){
    ll t; cin>> t;
    while(t--){
        ll a, b; cin>> a >> b;
        if(max(a,b)> 2*min(a,b)) cout<<no<<ln;
        else if((a+b)%3==0) cout<<yes<<ln;
        else cout<<no<<ln;
    }
    
    return 0;
}
