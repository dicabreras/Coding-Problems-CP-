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
        int n, m; cin >> n >> m;
        int a[n], b[m], flag = 1;

        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<m; i++) cin >> b[i];
        sort(b, b+m);
        a[0] = min(a[0], b[0]-a[0]);

        for(int i = 1; i<n; i++){
            int l = 0, r = m-1;
            while(l<r){
                int mid = l + (r-l)/2;
                if(f(a, i, b[mid])) r = mid;
                else l = mid+1;
            }
            int mn = min(a[i], b[r]-a[i]), mx = max(a[i], b[r]-a[i]);
            if(a[i-1]>mn){
                if(a[i-1]>mx) flag = 0;
                else a[i] = mx;
            }
            else a[i] = mn;
            
        }
        
        if(flag) cout<<yes<<ln;
        else cout<<no<<ln;
    }
        
    return 0;
}