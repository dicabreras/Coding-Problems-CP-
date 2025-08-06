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
        int n; cin>> n;
        int a[n], ans = 0;
        
        for(int i = 0; i<n; i++) cin>> a[i];
        bool flag = false;
        for(int i = 0; i<n; i++){
            if(a[i] == 0 && flag) flag = false;
            if(a[i]>0 && !flag){
                ans++;
                flag = true;
            }
            if(ans == 2)break;
        }
        cout<<ans<<ln;
        
    }
    return 0;
}