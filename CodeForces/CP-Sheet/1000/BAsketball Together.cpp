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
    
   
    ll n, d; cin >> n >> d;
    ll a[n];
    for(int i = 0; i<n; i++) cin>> a[i];
    sort(a, a+n);
    int r = n-1, l=0, ans = 0;
    while(l<=r){
        ll x = d/a[r];
        if(a[r]*x<=d)x++;
        l += x-2;
        if(l>=r) break;
        ans++;
        r--; 
        l++;
    }
    cout<<ans;

    return 0;
}