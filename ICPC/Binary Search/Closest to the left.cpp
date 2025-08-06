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
    
    int n, k; cin >> n;
    int a[n+2];
    a[0] = -(1e9+7);
    a[n+1] = 1e9+7;
    for(int i = 1; i<=n; i++) cin>> a[i];
    sort(a, a+n+2);
    cin>> k;
    while(k--){
        int L, R; cin>> L >> R;
        int l = 0, r = n+1, x;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(a[m]<L) l = m;
            else r = m;
        }
        x = r;
        l = 0, r = n+1;
        while(l+1<r){
            int m = l + (r-l)/2;
            if(a[m]<=R) l =m;
            else r = m;
        }
        
        int ans = l-x+1;
        cout<<ans<<" ";
    }
    cout<<ln;
    return 0;
}