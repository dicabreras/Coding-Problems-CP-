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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n, q; cin >> n >> q;
    int a[n], b[q], pos[51]={}; 
    for(int i = 0; i<n; i++){
        cin >> a[i];
        if(!pos[a[i]]) pos[a[i]] = i+1;
    }
    for(int i = 0; i<q; i++) cin >> b[i]; 
    
    vi ans;
    int ptr;
    for(int i = 0; i<q; i++){
        ptr = pos[b[i]];

        for(int j = 1; j<51; j++){
            if(pos[j]<ptr) pos[j]++;
        }
        ans.pb(ptr);
        pos[b[i]] = 1;
    }
    for(auto i : ans) cout<<i<<" ";
    cout<<ln;
        
    return 0;
}