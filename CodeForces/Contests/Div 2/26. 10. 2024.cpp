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
    
    int t; cin>>t;
    while(t--){
        int n; cin>> n;
        ll a[n], mx = 0; 
        map<ll, ll> MP;
        map<ll, ll> MP2;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            ll num = a[i] + i;
            MP[num]++;
            mx = max(mx, MP[num]);
        }
        ll ans = 0;
        ll current = mx;
        while(MP.count(current)){
            ans+=MP[current];
            cregex_iterator
            current = 

        }
        

        
    }    
    return 0;
}