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
        ll n; cin>> n;
        ll a = n, b = n, three = 0, two = 0;
        if(n == 1){
            cout<<0<<ln;
            continue;
        }

        while(a%3 == 0){
            a/=3;
            three++;
        }
        while(b%2 == 0){
            b/=2;
            two++;
        }
        
        bool flag = true;
        int x = three-two;
        if(two>three || three == 0) flag = false;
        if(flag){
            int ans = three+x;
            while(x>0){
                n*=2;
                x--;
            }

            while(n%6==0) n/=6;
            if(n == 1)cout<<ans<<ln;
            else cout<<-1<<ln;
        }
        else cout<<-1<<ln;

    }    
    return 0;
}