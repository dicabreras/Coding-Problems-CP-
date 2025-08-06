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
    int t; cin >> t;
    while(t--){
        ll w, h, k1, k2, k3, k4; cin >> w >> h;
        cin >> k1;
        ll x1[k1];
        for(int i = 0; i<k1; i++) cin>> x1[i];

        cin >> k2;
        ll x2[k2];
        for(int i = 0; i<k2; i++) cin>> x2[i];

        cin >> k3;
        ll y1[k3];
        for(int i = 0; i<k3; i++) cin>> y1[i];

        cin >> k4;
        ll y2[k4];
        for(int i = 0; i<k4; i++) cin>> y2[i];

        ll mx_X = max(x1[k1-1]-x1[0], x2[k2-1]-x2[0]), mx_Y = max(y1[k3-1]-y1[0], y2[k4-1]-y2[0]);


        ll ans = max(mx_X*h, mx_Y*w);

        cout<<ans<<ln;      
    }
    return 0;
}