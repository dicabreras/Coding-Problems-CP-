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
        int n, x; 
        ll sum = 0, mx = 1;
        cin>> n >> x;
        int a[n];
        for(int i = 0; i<n; i++) {
            cin>>a[i];
            sum+=a[i];
            if(a[i] > mx) mx = a[i];
        }
        if(sum%x==0) sum/=x;
        else sum = (sum/x)+1; 
        ll ans = max(mx, sum);
        cout<<ans<<ln;

    }
    return 0;
}