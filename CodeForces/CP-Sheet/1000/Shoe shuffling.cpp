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
        int a[n+1], f = 1;
        vi v;
        for(int i = 1; i<=n; i++) cin >> a[i];
        for(int i = 1; i<=n; i++){
            int j = i+1;
            while(j<=n){
                if(a[i] != a[j]) break;
                j++;
            }
            if(j-i==1){
                f = 0;
                break;
            }
            
            v.pb(j-1);
            for(int k = i; k<j-1; k++){
                v.pb(k);
            }
            i = j-1;
        }

        if(f){
            for(auto p : v) cout<<p<<" ";
            cout<<ln;
        }
        else cout<<-1<<ln;    
    }
    return 0;
}