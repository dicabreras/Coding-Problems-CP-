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
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n], f = 0; 
        for(int i = 0; i<n; i++) cin >> a[i];
        int x1 = 0, x2 = 0; 
        for(int i = 0; i<n/2; i++){
            if(a[i]!= a[n-i-1]){
                x1 = a[i];
                x2 = a[n-i-1];
                break;
            }
        }
            
        vi v, vr;
        for(int i = 0; i<n; i++){
            if(a[i] != x1) v.pb(a[i]);
        }
        vr = v;
        reverse(vr.begin(), vr.end());
        if(v == vr) f = 1;
        else{
            v.clear();
            for(int i = 0; i<n; i++){
                if(a[i] != x2) v.pb(a[i]);
            }
            vr = v;
            reverse(vr.begin(), vr.end()); 
            if(vr == v) f = 1;
        }
        if(f)cout<<yes<<ln;
        else cout<<no<<ln;
        
    }
    return 0;
}