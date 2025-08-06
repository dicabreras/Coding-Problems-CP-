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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        ll r = 0;
        map<char, int> m; 
        for(int i = 0; i<n; i++){
            if(m.count(s[i])) r+=(n-i);
            m[s[i]] = 1;
        }
        ll ans = n*(n+1)/2 - r;
        cout<<ans<<ln;
    }
    return 0;
}