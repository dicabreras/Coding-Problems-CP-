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
   // cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int n, q; cin>> n >> q;
    string s; cin>>s;
    int a[n] = {};
    int C = 0, N = 0, x = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '-'){
            if(C && !N){
                a[i] = -1;
            }
            if(N){
                a[i] = 1;
            }
            if(!C){
                a[i] = 3;
            }
        }
        if(s[i] == 'C'){
            a[i] = 2;
            C=1;
        }
        if(s[i] == 'N'){
            a[i] = 2;
            N = 1;
        }

    }
    while(q--){
        int i; cin>> i;
        i--;
        if(a[i] == -1) cout<<'?'<<ln;
        else if(a[i] == 1) cout<<'N'<<ln;
        else if(a[i] == 3) cout<<'C'<<ln;
        else if(a[i] == 2) cout<<"!"<<ln;
    }
    return 0;
}