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

    ifstream fin("herding.in");  
    ofstream fout("herding.out"); 
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n; cin >> n; 
    int a[n][n]; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin >> a[i][j];
    }
    int mxR = 0, mxC = 0;
    for(int i = 0; i<n; i++){
        int mx = -1;
        for(int j = 0; j<2; j++){
            int sum = 0;
            for(int k = j; k<n; k+=2){
                sum+=a[i][k];
            }
            mx = max(mx, sum);
        }
        mxR+=mx;
    }
    for(int i = 0; i<n; i++){
        int mx = -1;
        for(int j = 0; j<2; j++){
            int sum = 0;
            for(int k = j; k<n; k+=2){
                sum+=a[k][i];
            }
            mx = max(mx, sum);
        }
        mxC+=mx;
    }
    cout<<max(mxR, mxC);

    return 0;
}