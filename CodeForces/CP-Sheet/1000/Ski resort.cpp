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
        int n, k, q; cin>> n >> k >> q;
        ll ans = 0, cnt = 0;
        for(int i = 1; i<=n; i++){
            int x; cin>> x;
            if(x <= q){
                cnt++;
            }
            if(x>q){
                if(cnt >= k){
                    ll num = (cnt+1)*(cnt) - k*(k-1);
                    num/=2;
                    ll nnum = (cnt-k+1)*cnt;
                    ans+=(nnum+cnt-k+1-num);
                }
                cnt = 0;
            }
        }
        if(cnt >= k){
            ll num = (cnt+1)*(cnt) - k*(k-1);
            num/=2;
            ll nnum = (cnt-k+1)*cnt;
            ans+=(nnum+cnt-k+1-num);
        }

        cout<<ans<<ln;
               
    }   
    return 0;
}