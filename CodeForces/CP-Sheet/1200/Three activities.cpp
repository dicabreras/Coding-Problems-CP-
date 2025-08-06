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
 //   ios::sync_with_stdio(false);
 //   cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<vector<pi>> a(3);
        vector<pi> v;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<n; j++){
                int x; cin >> x;
                v.pb({x, j});
            }
            sort(v.rbegin(), v.rend());
            for(int j = 0; j<3; j++){
                a[i].pb(v[j]);
            }
            v.clear();

        }
        int sum = 0, mx  = 0, a1, a2, a3, f2 = 0, f3 = 0;
        for(int i = 0; i<3; i++){
            a1 = a[0][i].ss;
            sum+=a[0][i].ff;
            for(int j = 0; j<3; j++){
                a2 = a[1][j].ss;
                if(a1 != a2){
                    sum+=a[1][j].ff;
                    f2 = 1;
                }
                else continue;
                for(int h = 0; h<3; h++){
                    a3 = a[2][h].ss;
                    if(a2 != a3 && a1 != a3){
                        sum+=a[2][h].ff;
                        f3 = 1;
                    }
                    else continue;
                    mx = max(mx, sum);
                    if(f3)sum-=a[2][h].ff;
                }
                if(f2)sum-=a[1][j].ff;
            }
            sum = 0;
        }
        cout<<mx<<ln;
        
    }
        
    return 0;
}