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
    
    ll w, h, n; cin>> w >> h >> n;
    ll l = 1, r=1, y = (r/w)*(r/h);
    while(y<n){
        r*=2;
        y = (r/w)*(r/h);
        if(r>2){
            l*=2;
        }
    }
    ll m = l + (r-l)/2;
    while(l+1<r){
        m = l + (r-l)/2;
        if((m/w)*(m/h)<n){
            l = m;
        }
        else r = m;
    }
    cout<<r;
    return 0;
}
// We go until l+1<r since when l+1>=r and l stores the limit of the interval of bad numbers
// then, that means r is the minimum good number.