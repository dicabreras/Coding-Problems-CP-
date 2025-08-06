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
        int mx=1;
        map<int, int> m;
        for(int i = 0; i<n; i++){
            int x, current = 0; cin>> x;
            m[x]++;
            current = m[x];
            mx = max(mx, current);
        }

        int k = n-mx, p = mx, y=0;
        for(int i = 1; p<n; i++){
            p*=2;
            y++;
        }
        cout<<k+y<<ln;
    
    }    
    return 0;
}