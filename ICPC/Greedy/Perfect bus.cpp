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
    
    int n; cin >> n;
    ll sum = 0, mn = 0;
    for(int i = 1; i<=n; i++){
        ll x; cin >> x;
        sum+=x;
        mn = min(mn, sum);
    }
    sum-=mn;
    cout<<sum;
    return 0;
}