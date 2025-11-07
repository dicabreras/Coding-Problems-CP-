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
        ll n, rk, ck, rd, cd;
        cin >> n >> rk >> ck >> rd >> cd;
        ll ans; 
        if(rk == rd && ck==cd){
            cout<<0<<ln;
            continue;
        }
        if(rk == rd){
            if(ck<cd){
                ans = cd;
            }
            else{
                ans = n-cd;
            }
        }
        else if(cd == ck){
            if(rk<rd){
                ans = rd;
            }
            else ans = n-rd;
        }
        else if(ck < cd && rk < rd){
            ans = max(rd, cd);
        }
        else if(ck < cd && rk > rd){
            ans = max(n-rd, cd);
        }
        else if(ck > cd && rk > rd){
            ans = max(n-rd, n-cd);
        }
        else if(ck > cd && rk < rd){
            ans = max(rd, n-cd);
        }
        cout<<ans<<ln;
    }


    return 0;
}
