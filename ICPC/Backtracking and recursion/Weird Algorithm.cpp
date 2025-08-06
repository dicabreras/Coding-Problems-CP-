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

int main(){
    ll n; cin>> n;
    vector<ll> v;
    v.pb(n);
    while(n>1){
        if(n%2==0){
            n/=2;
        }
        else{
            n*=3;
            n++;
        }
        v.pb(n);
    }
    for(auto i : v) cout<<i<<" ";

    return 0;
}