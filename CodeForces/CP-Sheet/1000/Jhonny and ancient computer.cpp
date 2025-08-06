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
        ll a, b; cin >> a >> b;
        int a2 = 0, b2 = 0;
        while(a%2==0){
            a2++;
            a/=2;
        }
        while(b%2==0){
            b2++;
            b/=2;
        }
        if(a!=b){
            cout<<-1<<ln;
        }
        else{
            int temp = abs(a2-b2);
            int ans = temp/3, r = temp%3; 
            temp = r;
            temp/=2;
            r = r%2;
            ans+=temp+r; 
            cout<<ans<<ln;
        }
    }

    return 0;
}