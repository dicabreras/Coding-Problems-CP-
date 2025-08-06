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
        int n, x; cin >> n >> x; 
        int a[3][n], y = 0; 
        for(int i = 0; i<3; i++){
            int f = 1;
            for(int j = 0; j<n; j++){
                cin >> a[i][j];
                int temp = a[i][j]|x;
                if(temp == x && f) y|=a[i][j];
                else f = 0;
            }
        }
        if(y == x) cout<<yes<<ln;
        else cout<<no<<ln;
    }
    return 0;
}
