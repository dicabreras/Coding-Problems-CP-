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
        int a[n], pfx_sum_l[n+1] = {}, pfx_sum_r[n+1] = {};
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<n; i++){
            pfx_sum_l[i+1] = pfx_sum_l[i] + a[i];
            pfx_sum_r[n-i-1] = pfx_sum_r[n-i] + a[n-i-1];
        }
        int mx = 0, l = 0, r = n;
        while(l<=r){
            if(pfx_sum_l[l]>pfx_sum_r[r]) r--;
            else if(pfx_sum_l[l]<pfx_sum_r[r])l++;
            else{
                mx = l+n-r;
                r--;
                l++;
            }
        }
        cout<<mx<<ln;
    }
    return 0;
}