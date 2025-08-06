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
    
    int t; cin>> t;
    while(t--){
        ll n, m; cin >> n;
        m = n;
        int f = 0;
        while(!f){
            while(m>0){
                ll x = m%10;
                if(x>0 && n%x>0) break;
                m/=10;
            }
            if(m == 0) f = 1;
            n++;
            m = n;
        }
        cout<<n-1<<ln;
    }

    return 0;
}