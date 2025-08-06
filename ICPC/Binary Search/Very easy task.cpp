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
ll x, y, n;
bool f(ll m){
    ll mx = max(x, y), mn = min(x, y);
    return (m-mn)/mx + m/mn >=n;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> n >> x >> y;
    ll l=0, r=n*max(x,y);
    while(l+1<r){
        ll m = l + (r-l)/2;
        if(f(m)) r = m;
        else l = m;
    }
    cout<<r;
    
    return 0;
}