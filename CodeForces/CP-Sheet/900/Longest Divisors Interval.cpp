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

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin>> t;
    while(t--){
        ll n; cin>> n;
        if(n%2==1) cout<< 1 <<ln;
        else{
            ll ans = 2;
            for(ll i = 3; i<=n/2; i++){
                if(n%i==0)ans++;
                else break;
            }
            cout<<ans<<ln;
        }
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1855/B