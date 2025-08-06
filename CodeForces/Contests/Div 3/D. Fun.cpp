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

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        ll ans = 0;
        ll n, x; cin>> n >> x;
        for(ll a = 1; a<=n; a++){
            for(ll b = 1; b<=n/a; b++){
                ll c = min((n-a*b)/(a+b), x-a-b);
                if(c>0)ans+=c;
            }
        }
        cout<<ans<<ln;
    }
    return 0;
}

/*
int main(){
    int tc;
    cin >> tc;

    while (tc--){
        int n, x;
        cin >> n >> x;

        long long ans = 0;
        
        for (int a = 1; a <= min(n, x); a++){  assure that the two equations are satisfied
            for (int b = 1; a * b <= n and a + b <= x; b++){       this way you are sure that n-a*b>=0 and x-a+b>=0
                int highestC = min((n - a * b) / (a + b), x - (a + b));
                ans += highestC;
            }
        }
        cout << ans << "\n";
    }
}

*/

//https://codeforces.com/contest/1996/problem/D