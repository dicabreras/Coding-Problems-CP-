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
        int n, k; cin>> n >> k;
        int a[n*k+1]; 
        for(int i = 1; i<=(n*k); i++) cin>>a[i];
        int idx;
        if(n%2>0) idx = n/2 + 1;
        else idx = n/2;
        ll sum = 0;
        int stp = n-idx;
        for(int i = n*k -stp; k>0; i-=(stp+1), k--){
            sum+=a[i];
        }
        cout<<sum<<ln;
        
    }    
    return 0;
}