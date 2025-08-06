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
    
    
        int t; cin>> t;
        while(t--){
            int n;  cin >> n;
            int a[n], b[n];
            for(int i = 0; i<n; i++) cin >> a[i];
            for(int i = 0; i<n; i++) cin >> b[i];
            int f = 1;
            for(int i = n-1; i>0; i--){
                if(a[i]>a[i-1] || gcd(a[i-1], a[i]) == 1) f = 0;  
            }
            for(int i = 0; i+1<n; i++){
                if(b[i]>b[i+1] || gcd(b[i+1], b[i]) == 1) f = 0;
            }
            if(f) cout<<yes<<ln;
            else cout<<no<<ln;
            

        }
    return 0;
}