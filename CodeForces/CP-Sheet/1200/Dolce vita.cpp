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
        ll n, x; 
        cin >> n >> x;
        ll a[n], sum = 0;
        for(ll i = 0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        sort(a, a+n);
        ll ans = 0, f = 1;
        for(ll i = n-1; i>=0; i--){
            if(x-sum<0 && f){
                sum-=a[i];
                continue;
            }
            else{
                x-=sum;
                ans+=i+1;
                f = 0;
            }
            ll t = x/(i+1);
            x-=(i+1)*t;
            ans+=n*t;
        }
        cout<<ans<<ln;
    }


    return 0;
}
*/