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
        int n, m; cin >> n >> m; 
        int a[n][m], r[n+1][m+1] = {}, c[n+1][m+1] = {}; 
        for(int i = 0; i<n; i++){
            string s; cin >> s;
            for(int j = 0; j<m; j++){
                if(s[j]=='1') a[i][j] = 1;
                else a[i][j] = 0;
                c[i+1][j+1] = a[i][j] + c[i+1][j];
            }
        }
        for(int j = 0; j<m; j++){
            for(int i = 0; i<n; i++){
                r[i+1][j+1] = a[i][j] + r[i][j+1];
            }
        }
        
        int f = 1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(a[i][j] && r[i+1][j+1]!=i+1 && c[i+1][j+1] != j+1){
                    f = 0;
                    break;
                }
            }
        }
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;

        /*

        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                cout<<c[i][j]<<" ";
            }
            cout<<ln;
        }
        cout<<"------------"<<ln;
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                cout<<r[i][j]<<" ";
            }
            cout<<ln;
        }
            */
           
    }
    return 0;
}