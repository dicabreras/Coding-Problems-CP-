#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    int n, x; cin>> n >> x;
    int A[n];
    int pfx_sums[n+1];
    memset(pfx_sums, 0, n+1);
    for(int i = 0; i<n; i++)cin>>A[i];
    for(int i = 1; i<n+1; i++) pfx_sums[i] = pfx_sums[i-1]+A[i-1];
    
    int ans = 0;
    for(int l = 1;  l<n+1; l++){
        for(int r = l; r<n+1; r++){
            if(pfx_sums[r]-pfx_sums[l-1]==x) ans++;
        }
    }
    cout<<ans;

    return 0;
}