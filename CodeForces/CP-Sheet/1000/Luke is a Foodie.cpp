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
        int n, x; cin >> n >> x;
        int a[n]; 
        for(int i = 0; i<n; i++) cin >> a[i];

        int l = a[0]-x, r = a[0]+x, ans = 0;

        for(int i = 1; i<n; i++){
            l = max(l, a[i]-x);
            r = min(r, a[i]+x);
            if(l>r){
                ans++;
                l = a[i] - x;
                r = a[i] + x;
            }
        }
        cout<<ans<<ln;
        
        
    }
    return 0;
}