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
        int n, m; cin >> n >> m;
        string s; cin >> s;
        ll a[n+1][m+1];
        for(int i = 0; i<n; i++){
            ll sum = 0;
            for(int j = 0; j<m; j++){
                cin>>a[i][j];
                sum+=a[i][j];
            }
            a[i][m] = sum;
        }        
        for(int j = 0; j<m; j++){
            ll sum = 0;
            for(int i = 0; i<n; i++){
                sum+=a[i][j];
            }
            a[n][j] = sum;
        }
        int i = 0, j = 0;
        for(auto c : s){
            if(c == 'D'){
                a[i][j] = -a[i][m];
                a[n][j]+=a[i][j];
                i++;
            }
            else{
                a[i][j] = -a[n][j];
                a[i][m]+=a[i][j];
                j++;
            }

        }
        a[i][j] = - a[n][j];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<ln;
        }
    }
 
    return 0;
}