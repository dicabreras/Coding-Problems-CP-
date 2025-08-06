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
    int n; cin >> n;
    int a[3][n];
    map<int, int> m;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            cin>> a[i][j];
            if(i == 1){
                m[a[i][j]] = 0;
            }
            else if(i == 2){
                int x = a[i][j]-1, y = a[1][x];
                m[y]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i<n; i++){
        if(m.count(a[0][i])){
            int k = m[a[0][i]];
            ans+=k;
        }
    }
    cout<<ans;

    return 0;
}