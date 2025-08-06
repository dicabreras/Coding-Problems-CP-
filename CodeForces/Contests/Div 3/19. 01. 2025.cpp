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
        int n, k; cin >> n >> k;
        map<int, int> m;
        set<int> s;
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            m[x]++;
            s.insert(x);
        }
        int ans = 0;
        for(auto p : m){
            int x = k-p.ff;
            if(s.count(x) && s.count(p.ff)){
                if(x==p.ff){
                    ans+=(p.ss/2);
                    continue;
                }
                ans+=min(m[x], p.ss);
                s.erase(x);
                s.erase(p.ff);
            }
            else if(s.count(p.ff)){
                s.erase(p.ff);
            }
        }
            
        cout<<ans<<ln;
    }
    return 0;
}