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
        int n, m, k; cin >> n >> m >> k;
        int a[n][m], h = 0, l = 0;
        for(int i = 0; i<n; i++){
            l++;
            for(int j = 0; j<m; j++){
                if(i%2==0)a[i][j] = k-h;
                else a[i][j] = h+1;
                h++;
                h%=k;
            }
            if(a[i][m-1]== h+1) h--;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) cout<<a[i][j]<<" ";
            cout<<ln;
        }
    }
    return 0;
}