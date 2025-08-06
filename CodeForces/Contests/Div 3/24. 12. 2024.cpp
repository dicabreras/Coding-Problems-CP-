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
        int n, d; cin >> n >> d;
        int a[4]={};
        if(n>=3 || d%3 == 0) a[0] = 1;
        if(d == 5) a[1] = 1;
        if(n>=3 || d == 7) a[2] = 1; 
        if(n>=6 || d == 9) a[3] = 1;
        if(n>=3 && (d == 3 || d == 6)) a[3] = 1;

        cout<<1<<" ";
        for(int i = 0, x = 3; i<4; i++, x+=2){
            if(a[i]) cout<<x<<" ";
        }
        cout<<ln;
        
    }
    return 0;
}