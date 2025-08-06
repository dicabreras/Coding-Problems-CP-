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
    
    int t; cin>>t;
    while(t--){
        int n; cin>> n;
        ll a[n], mx=1, ans;
        for(int i = 0; i<n; i++) cin>> a[i];

        
        if(n%2==0){
            for(int i = 0, j=1; j<n; i+=2, j+=2){
                mx = max(mx, a[j]-a[i]);   
            }
            ans = mx;
        }
        else{
            vector<ll> vmx;
            for(int i = 0; i<n; i+=2){
                mx = 1;
                for(int j = 0, k = 1; k<n; j+=2, k+=2){
                    if(j == i){
                        j++;
                        k++;
                    }
                    mx = max(mx, a[k]-a[j]);
                }
                vmx.pb(mx);
            }
            ans = 1e18+7;

            for(auto x : vmx) ans = min(ans, x);
        }
        cout<<ans<<ln;
        
    }   
    return 0;
}
