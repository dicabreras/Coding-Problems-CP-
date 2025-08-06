/*
Coded by Diego Cabrera
*/
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
        int n; cin >> n; 
        int a[n], b[n];
        ll c[n];
        for(int i = 0; i<n; i++) c[i] = 1;
        
        for(int i = 0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        for(int i = 0; i<n; i++) cin >> b[i];
        
        for(int i = 0; i<n; i++){
            int l = -1, r = n;
            while(l+1<r){
                int mid = l + (r-l)/2;
                if(a[mid]<=b[i]) l = mid;
                else r = mid;
            }
            c[i] = n-l-1;
        }

        sort(c, c+n);

        ll ans = 1;
        for(int i = 0; i<n; i++){
            ans*=(c[i]-i);
            ans%=M;
        }
        cout<<ans<<ln;
    }
        
    return 0;
}
