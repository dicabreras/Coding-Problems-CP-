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
        string s; cin >> s;
        ll n = s.size();
        ll l = 0, r = 0, mx = 0, f = 1;
        for(auto i : s){
            if(i == '0') f = 0;
        }
        if(f){
            cout<<n*n<<ln;
            continue;
        }
        else{
            for(int i = 0; i<n*2; i++){
                int j = i%n;
                if(s[j]=='1'){
                    r++;
                    mx = max(mx, r-l);
                }
                else{
                    l = i+1;
                    r = i+1;
                }
            }
        }
        mx++;
        ll q1 = mx/2, q2 = q1;
        if(q1*2<mx) q2++;
        ll ans = q1*q2;
        cout<<ans<<ln;
    }
    return 0;
}