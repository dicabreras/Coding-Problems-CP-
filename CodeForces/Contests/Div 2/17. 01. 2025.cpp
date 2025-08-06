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
        int n; cin >> n;
        int a[n];
        a[0] = 1; a[n-1] = 1; a[1] = 1;
        int j = 2;
        for(int i = 2; i<n-1; i++){
            a[i] = j;
            j++;
        }
        for(auto i : a) cout<<i<< " ";
        cout<<ln;
        
    }
    return 0;
}