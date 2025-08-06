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

int f(int* a, int i, int b){
    if(a[i-1]<=b-a[i]) return 1;
    return 0;
}
 
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
        int a[n], pfx_sum[n+1] = {};
        vector<pi> v;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            pfx_sum[i+1] = pfx_sum[i] + a[i];
        }
        int f = abs(a[0]%2), l=0, r = l;
        for(int i = 1; i<n; i++){
            if(abs(a[i]%2) && !f){
                f = 1;
            }
            else if(!(a[i]%2) && f){
                f = 0;
            }
            else{
                v.push_back({l, r});
                l = r+1;
                f = abs(a[i]%2);
            }
            r++;
        }
        v.push_back({l, r});
        int m = v.size(), mx = -(1e9+7);
        for(int i = 0; i<m; i++){
            pi p = v[i];
            int L = p.ff, R = p.ss, l = L, r = L+1;
            while(r<=R+1){
                int current = pfx_sum[r] - pfx_sum[l];
                mx = max(mx, current);
                if(current < 0){
                    l = r;
                } 
                r++;
            }
        }
        cout<<mx<<ln;
    }    
    return 0;
}