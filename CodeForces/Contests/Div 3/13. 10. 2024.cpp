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
        int n, r; cin>> n >> r;
        int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];

        int ans = 0, x = 0;

        for(int i = 0; i<n; i++){    
            r-=(a[i]/2);
            if(a[i]%2==0) ans+=a[i];
            else {
                ans+=a[i]-1;
                x++;
            } 
        }
        int y = r-x;
        if(y<0){
            int notH = 2*y;
            x+=notH;
            ans+=x;
        }
        else ans+=x;
        cout<<ans<<ln;
    }
    return 0;
}