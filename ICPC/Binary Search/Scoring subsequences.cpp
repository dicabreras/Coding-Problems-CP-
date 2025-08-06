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

int f(int m, int k, int *a){
    if(a[m]<k-m+1) return 0;
    return 1;
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
        int a[n], ans[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        int k = 0;
        while(k<n){
            int l = 0, r = k;
            while(l<r){
                int m = l + (r-l)/2;
                if(f(m, k, a)) r = m;
                else l = m+1;
            }
            ans[k] = k-r+1;
            k++;
        }
        for(auto mx : ans) cout<<mx<<" ";
        cout<<ln;
    }

    return 0;
}