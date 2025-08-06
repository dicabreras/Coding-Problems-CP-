/*
Coded by Diego Cabrera
*/
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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

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
        int a[n], b[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<n; i++) cin >> b[i];
        int l = 0, r = 0, l_max = 0, r_max = 0;
        vector<pi> v;
        for(int i = 0; i+1<n; i++){        
            if(b[i+1]>=b[i]){
                r++;
            }
            else{
                v.pb({l, r});
                l = i+1;
                r = l;
            }
        }

        v.pb({l, r});
        
        for(auto p : v){
            int l = p.ff, r = p.ss;
            for(int i = l; i<=r; i++){
                if(a[i]!=b[i]){
                    if(r-l+1>=r_max-l_max+1){
                        l_max = l;
                        r_max = r;
                    }
                    break;
                }
            }
        }
        cout<<l_max+1<<" "<<r_max+1<<ln;
    }
    return 0;
}