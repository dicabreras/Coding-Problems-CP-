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
        ll n, x; cin>> n >> x;
        ll mx = 0, mn = 0;
        for(int i = 0; i<n; i++){
            ll num; cin>> num;
            if(num%x > 0) mx+=(num/x)+1;
            else mx+=(num/x);
            mn+=num;
        }
        if(mn%x>0)mn = mn/x + 1;
        else mn/=x;
        cout<<mn<<" "<<mx<<ln;
        
    }    
    return 0;
}