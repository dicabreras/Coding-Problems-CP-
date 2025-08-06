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
        ll x, n; cin>> x >> n;
        if(n%2==0){
            if((n/2)%2==1){
                if(x%2 == 0) x++;
                else x--;
            }
        }
        else{
            if(x%2==0){
                if((n-1)%4==0) x-=n;
                else x+=n+1;
            }
            else{
                if((n-1)%4==0) x+=n;
                else x-=(n+1);
            }
        }
        cout<<x<<ln;

    }    
    return 0;
}