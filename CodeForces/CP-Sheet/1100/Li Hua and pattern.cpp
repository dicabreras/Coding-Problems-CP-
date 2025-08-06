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
        int n, k; cin >> n >> k;
        int a[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin >> a[i][j];
            }
        }
        int x = 0;
        for(int i = 0; i<n/2+(n%2); i++){
            int sum = 0;
            for(int j = 0; j<n; j++){
                if(a[i][j]!=a[n-i-1][n-1-j]) sum++;
            }
            if(n%2 && i == n/2) sum/=2;
            x+=sum;
        }
        if(x<=k && x%2 == k%2) cout<<yes<<ln;
        else if(n%2 && x<=k)cout<<yes<<ln;
        else cout<<no<<ln;

    }
    return 0;
}