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
        int n, r, b; cin >> n >> r >> b;
        int q = r/(b+1), R = r%(b+1);
        q++;
        string s;
        /*
        if(b == 1){
            for(int i = 0; i<n; i++){
                if(i == n/2) s.pb('B');
                else s.pb('R');
            }
            cout<<s<<ln;
            continue;
        }
        */
        for(int i = 1; i<=n; i++){
            if(i%q > 0){
                s.pb('R');
            }
            else{
                if(R>0){
                    s.pb('R');
                    R--;
                    n--;
                }
                s.pb('B');
            }
        }
        cout<<s<<ln;
        
    }
    return 0;
}