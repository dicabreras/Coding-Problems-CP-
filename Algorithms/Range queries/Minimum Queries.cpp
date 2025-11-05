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

    int n; 
    cin >> n; 
    vector<vi> minA;
    vi current; 
    for(int i = 0; i<n; i++){
        int x; 
        cin >> x;
        current.push_back(x);
    }
    minA.push_back(current);
    
    // Building the sparse table
    for(int p = 1, i = 1; n-p>=0; p*=2, i++){
        current.clear();
        for(int j = 0; j+p<n-p+1; j++){
            int mn = min(minA[i-1][j], minA[i-1][j+p]);
            current.push_back(mn);
        }
        minA.push_back(current);
    }
    int p = 1;
    for(auto v : minA){
        cout<<p<<": ";
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<ln;
        p*=2;
    }

    

    return 0;
}
