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
        int n, q; cin >> n >> q;
        int a[n], x[q], d = 0;
        vector<vi> v (31);
        for(int i = 0; i<n; i++){
            int num, j = 0; cin >> num;
            a[i] = num;
            while(num%2 == 0){
                num/=2;
                j++;
            }
            v[j].pb(i);
            d = max(d, j);
        }

        for(int i = 0; i<q; i++) cin >> x[i];

        
        for(auto i : x){
            if(i<=d){
                int two = 1;
                for(int k = 0; k<i-1; k++) two*=2;
                for(int j = i; j<=d; j++){
                    for(auto l : v[j]){
                        a[l]+=two;
                        v[i-1].pb(l);
                    }
                }
                d = min(i-1, d);
            }
        }
        for(auto i : a) cout<<i<<" ";
        cout<<ln;
    }
    return 0;
}