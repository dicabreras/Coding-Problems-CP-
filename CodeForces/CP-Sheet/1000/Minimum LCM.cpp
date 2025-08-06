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
    
    int t; cin>>t;
    while(t--){
        int n; cin>> n;
        if(n%2 == 0){
            cout<<n/2<<" "<<n/2<<ln;
        }
        else{
            int i = 3, a=1;
            while(i*i<=n){
                if(n%i==0){
                    a = (n/i)*(i-1);
                    break;
                }
                else i+=2;
            }
            int b = n-a;
            cout<<a<<" "<<b<<ln;
        }
        
    }   
    return 0;
}