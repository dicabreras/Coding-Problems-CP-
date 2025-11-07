/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
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
    freopen("output.txt", "w", stdout);
    #endif
    */

    int t; 
    cin >> t;
    while(t--){
        ll k, x, y, p = 1; 
        cin >> k >> x;
        for(int i = 0; i<=k; i++) p*=2;
        y = p-x;
        vi ans;
        while(y*2 != p && x*2 != p){
            if(x*2>p){
                x-=y;
                y*=2;
                ans.pb(2);
            }
            else{
                y-=x;
                x*=2;
                ans.pb(1);
            }
        }
        reverse(ans.begin(), ans.end());
        ll N = ans.size();
        cout<<N<<ln;
        for(auto i : ans) cout<<i<<" ";
        cout<<ln;
    } 

    return 0;
}
