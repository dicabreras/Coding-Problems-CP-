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
    
    int t; cin>> t;
    while(t--){
        int n, f = 0; cin >> n;
        map<int, int> m;
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            if(!m.count(x)) m[x] = 1;
            else{
                m[x]++;
                f = 1;
            }
        }
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;
    }

    return 0;
}