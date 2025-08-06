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
    ll pfx_sum[n+1] = {} , ans = 0; 
    ll modules[n] = {};
    modules[0]++;

    for(int i = 0; i<n; i++){
        ll x; cin >> x;
        pfx_sum[i+1] = pfx_sum[i] + x;
        if(pfx_sum[i+1]<0 && pfx_sum[i+1]%n!=0) modules[n+(pfx_sum[i+1]%n)]++;
        else modules[pfx_sum[i+1]%n]++;
        //int temp = pfx_sum[i+1]%n; 
        
    }
 
    for(auto i : modules){
        ll x = (i*(i-1))/2;
        ans+=x;
    }
    cout<<ans<<ln;
    return 0;
}