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
    int a[n+1], b[n+1]={0}; 
    for(int i = 1; i<=n; i++) cin>> a[i];
 
    for(int i = 2; i<=n; i++){
        int k = i-1;
        while(a[i]<=a[k] && k>0){
            k = b[k];
        }
        b[i] = k;
    }
    for(int i = 1; i<=n; i++) cout<< b[i] <<" ";
    cout<<ln;

    return 0;
}
