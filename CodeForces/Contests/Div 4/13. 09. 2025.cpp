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
        int n, k; 
        cin >> n >> k;
        int a[n];
        map<int, int> m, mx;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            m[a[i]]++;
        }
        int f = 1;
        for(auto [x, cnt] : m){
            if(cnt%k > 0) f = 0;
            mx[x] = cnt/k;
        }
        if(f){
            ll ans = 0;
            int l = 0, r = 0;
            map<int, int> aux;
            while(r<n && l<=r){
                int current = a[r];
                aux[current]++;
                while(aux[current]>mx[current]){
                    aux[a[l]]--;
                    l++;
                }
                // This way we count form a[l, l], a[l, l+1], ..., a[l, r-1] and a[l, r-1], a[l+1, r-1], ... a[r-1, r-1];
                // The both ways need to be counted
                ans+=(r-l+1);   
                r++;
            }
            cout<<ans<<ln;
        }
        else cout<<0<<ln;
        
    }

    return 0;
}
