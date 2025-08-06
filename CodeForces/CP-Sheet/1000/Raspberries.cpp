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
        int n, k; cin>> n >> k;
        int mx = 0 , ans, cnt = 0;
        bool flag = false;
        
        for(int i = 0; i<n; i++){
            int x; cin>> x;
            mx = max(mx, x%k);
            if(x%2 == 0) cnt++;
            if(x%k == 0) flag = true;
        }
        if(cnt>2) cnt = 2;
        
        if(flag) cout<<0<<ln;
        else{
            if(k==4) ans = min(2-cnt, k-mx);
            else ans = k-mx;
            cout<<ans<<ln;
        }
             
    }   
    return 0;
}