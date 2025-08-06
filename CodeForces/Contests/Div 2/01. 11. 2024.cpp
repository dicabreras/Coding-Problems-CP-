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
        int n; cin>>n;
        int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        sort(a, a+n);
        int mx = 0;
        for(int i = 0; i+1<n; i++){
            int l = i+2, r=n-1;
            int idx;
            while(l<r){
                int mid = l + (r-l)/2;
                if(a[i]+a[i+1]>a[mid]){
                    l = mid+1;
                }
                else r = mid-1;
                idx = mid;
            }
            int current = idx-i;
            mx = max(mx, current);
        }
        cout<<n-mx<<ln;


            

        
    }   
    return 0;
}