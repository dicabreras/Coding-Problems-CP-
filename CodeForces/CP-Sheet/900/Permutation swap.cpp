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

int GCD_recursive(int a, int b){
    if(a==0 || b == 0) return max(a, b);
    if(a%b == 0) return b;
    return GCD_recursive(b, a%b);
}


int GCD(int a, int b){
    if(a==0 || b == 0) return max(a, b);
    int c = a%b;
    while(c>0){
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin>>t;
    while(t--){
        int n, r = 0; cin>>n;
        for(int i = 1; i<=n; i++){
            int x; cin>> x; 
            r = GCD(r, abs(x-i));
        }
        cout<<r<<ln;

        
    }
    return 0;
}