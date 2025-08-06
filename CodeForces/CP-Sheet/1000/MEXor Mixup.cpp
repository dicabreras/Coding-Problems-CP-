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
        int a, b; cin >> a >> b;
        int pXor;
        if(a%4 == 0) pXor = 0;
        else if(a%4 == 1) pXor = a-1;
        else if(a%4 == 2) pXor = 1;
        else if(a%4 == 3) pXor = a;

        if(pXor==b) cout<<a<<ln;
        else if((pXor^b) != a) cout<<a+1<<ln;
        else cout<<a+2<<ln;
    }

    return 0;
}