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
    
    int t; cin>> t;
    while(t--){
        int n; cin >> n;
        int a[n], pfx_sum[n+1] = {}, pfx_sum2[n+1]={};
        for(int i = 0, j = 1; i<n; i++, j++){
            cin >> a[i];
            pfx_sum[j] = pfx_sum[j-1]+a[i];
            pfx_sum2[j] = pfx_sum2[j-1] + pfx_sum[j];

        }
        /*
        for(int i = 1; i<=n; i++){
            pfx_sum2[i] = pfx_sum2[i-1] + pfx_sum[i];
        }*/
        int q; cin >> q;
        while(q--){
            ll l, r; cin >> l >> r;
            for(int i = l+1; i<r+1; i++){

            }

        }


    }

    return 0;
}