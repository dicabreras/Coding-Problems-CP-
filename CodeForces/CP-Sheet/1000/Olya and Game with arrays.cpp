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
        vector<vector<int>> vec;
        vector<int> mns(n);
        int mnabs = 1e9+7;
        for(int i = 0; i<n; i++){
            int m; cin>> m;
            int mn = 1e9 + 7;
            vector<int> v(m);
            for(int j = 0; j<m; j++){
                int x; cin>> x;
                v[j]=x; 
                mn = min(mn, v[j]);
            }
            mnabs = min(mnabs, mn);
            mns[i] = mn;
            vec.pb(v);
        }
        int smnabs = 1e9+7;
        ll ans = mnabs;
        for(int i = 0; i<n; i++){
            int mn = mns[i];
            int smnc= 1e9+7;
            bool flag = false;
            for(auto a : vec[i]){
                if(a==mn && !flag){
                    flag = true;
                    continue;
                }
                smnc = min(smnc, a);
            }
            smnabs = min(smnabs, smnc);
            ans+=smnc;
        }
        ans-=smnabs;
        cout<<ans<<ln;
             
    }   
    return 0;
}