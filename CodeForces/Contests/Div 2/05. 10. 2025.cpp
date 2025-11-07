/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
*/
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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int a[n]; 
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        int f = 2, g = 0, h = 1;
        for(int i = 1; i<n; i++){
            if(abs(a[i]-a[i-1]) > 1){
                h = 0;
                break;
            }
            else if(a[i] < a[i-1] && !g) f = -1;
            else if(a[i]>a[i-1] && !g) f = 1;
            else if(a[i] == a[i-1] && !g) g = 1;
            else if(a[i]<a[i-1] && g && f == -1){
                h = 0;
                break;
            } 
            else if(a[i]>a[i-1] && g && f == 1){
                h = 0;
                break;
            }
        }
        if(h){
            int prev = 0, ans = 2;
            for(int i = 0; i<n; i++){
                if(a[i]<a[i+1] && (prev == 0 || prev == 1)) prev = 1;
                else if(a[i]>a[i+1] && (prev == 0 || prev == -1)) prev = -1;
                else if(a[i]!=a[i+1]){
                    ans = 1;
                    break;
                }
            }
            if(prev == 0) ans = 2;
            cout<<ans<<ln;
        }
        else cout<<0<<ln;

        
        
    }


    return 0;
}
