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
        ll min, max;
        if(n%2>0 || n<4){
            cout<<-1<<ln;
            continue;
        }
        if(n%6 == 0) min = n/6;
        else min = n/6 + 1;
        if(n%4 == 0) max = n/4;
        else max = n/4;
        cout<< min <<" "<< max <<ln;
    }
    return 0;
}