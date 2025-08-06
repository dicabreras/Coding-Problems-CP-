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

int main(){
    int t; cin>> t;
    while(t--){
        ll n, k, x; cin>> n >> k >> x;
        ll mn = (k*(k+1))/2, mx = (n*(n+1))/2 - ((n-k)*(n-k+1))/2;
        if(x>=mn && x<=mx)cout<<yes<<ln;
        else cout<<no<<ln;
    }

    return 0;
}