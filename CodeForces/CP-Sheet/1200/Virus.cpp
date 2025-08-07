/*
Coded by Diego Cabrera
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

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[m], d[m]; 
        for(int i = 0; i<m; i++) cin >> a[i];
        sort(a, a+m);
        for(int i = 0; i+1<m; i++){
            d[i] = abs(a[i+1]-a[i])-1;
        }
        d[m-1] = n-a[m-1]+a[0]-1;
        
        sort(d, d+m, greater<>());
        int saved = 0, dx = 0;
        for(int i = 0; i<m; i++){
            int x = d[i]-dx;
            dx+=2;
            if(x>1){
                x--;
                dx+=2;
            }
            if(x<=0) break;
            saved+=x;
        }
        int ans = n-saved;
        cout<<ans<<ln;
    }
    return 0;
}