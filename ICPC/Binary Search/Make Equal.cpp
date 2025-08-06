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

int f(int mid, int* a, int n){
    int u = 0;
    for(int i = 0; i<n; i++){
        if(a[i]>mid) u+=(a[i]-mid);
        else u-=(mid-a[i]);
        if (u<0) return 0;
    }
    if(u>=0) return 1;
}
 
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
        int a[n], sum = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
        }
        int l = 0, r = 2e9+7;
       // int l = 0, r = 10;
        while(l+1<r){
            int mid = l + (r-l)/2;
            if(f(mid, a, n)) l = mid;
            else r = mid;
        }
        if(l*n == sum) cout<<yes<<ln;
        else cout<<no<<ln;
    }

    return 0;
}