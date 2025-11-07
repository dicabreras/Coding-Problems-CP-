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
        ll n;
        cin >> n;
        ll a[n];
        map<ll, int> m;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        sort(a, a+n);
        vector<ll> odd;
        ll sum = 0, k = 0;
        for(auto [i, cnt] : m){
           // cout<<i<<ln;
            sum+=i*cnt;
            k+=cnt;
            if(cnt%2){
                sum-=i;
                odd.pb(i);
                k--;
            }
        }
        int N = odd.size(), f = 0;
        for(int i = N-1; i-1>=0; i--){
            if(sum + odd[i-1] > odd[i]){
                sum+=odd[i-1]+odd[i];
                k+=2;
                f = 1;
                break;
            }
        }
        if(!f){
            for(int i = N-1; i>=0; i--){
                if(sum>odd[i]){
                    k++;
                    sum+=odd[i];
                    break;
                }
            }
        }
        if(k<3) sum = 0;
        cout<<sum<<ln;
    }

    return 0;
}
