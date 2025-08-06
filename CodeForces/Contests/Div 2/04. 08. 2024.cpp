#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
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
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        int n; cin>> n; 
        ll mx_odd = 0;
        vector<int>A_even;
        for(int i = 0; i<n; i++){
            ll num; cin>>num;
            if(num%2==0)A_even.pb(num);
            else if(num>mx_odd) mx_odd = num;
        }
        sort(A_even.begin(), A_even.end());
        if(mx_odd==0 || A_even.size()==0)cout<<0<<ln;
        else{
            int ans = 0; 
            for(int i = 0; i<A_even.size(); i++){
                if(A_even[i]<mx_odd){
                    ans++;
                    mx_odd+=A_even[i];
                }
                else{
                    ans = A_even.size()+1;
                    break;
                }
                if(mx_odd>1e9)mx_odd = 1e9+7;
            }
            cout<<ans<<ln;
        }
    }
    return 0;
}