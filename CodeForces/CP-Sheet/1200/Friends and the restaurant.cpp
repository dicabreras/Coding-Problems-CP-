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
    freopen("output.txt", "w", stdout);
    #endif
    */

    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n], b[n], c[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<n; i++) cin >> b[i];
        for(int i = 0; i<n; i++){
            c[i] = b[i]-a[i];
        }
        sort(c, c+n);
        int l = 0, r = n-1, ans = 0;
        while(c[l]<0){
            if(c[r]+c[l]>=0){
                r--;
                l++;
                ans++;
            }
            else{
                l++;
            }
        }
        ans+=(r-l+1)/2;
        cout<<ans<<ln;
    }
    return 0;
}