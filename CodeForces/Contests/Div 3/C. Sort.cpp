#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        int n, q; cin>> n >> q;
        string S[2];
        cin>>S[0]; cin>>S[1];
        int pfx_sums[2][26][n+1];
        for(int i = 0; i<26; i++) {
            pfx_sums[0][i][0] = 0;
            pfx_sums[1][i][0] = 0;
        }

        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<26; j++){
                int h = (int) S[0][i-1]-97, k = (int) S[1][i-1]-97;
                if(j == h){
                    pfx_sums[0][j][i] = pfx_sums[0][j][i-1]+1;
                }
                if(j == k){
                    pfx_sums[1][j][i] = pfx_sums[1][j][i-1]+1;
                } 
                if(j!=h){
                    pfx_sums[0][j][i] = pfx_sums[0][j][i-1];
                }
                if(j!=k){
                    pfx_sums[1][j][i] = pfx_sums[1][j][i-1];
                }
            }
        }

        while(q--){
            int l, r; cin>> l >> r;
            int ans = 0;
            for(int i = 0; i<26; i++){
                int num0 = pfx_sums[0][i][r] - pfx_sums[0][i][l-1];
                int num1 = pfx_sums[1][i][r] - pfx_sums[1][i][l-1];
                ans+=abs(num0-num1);
            }
            cout<<ans/2<<ln;
        }   
    }
    return 0;
}

//https://codeforces.com/contest/1996/problem/C