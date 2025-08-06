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
        string s1, s2; cin>> s1 >> s2;
        int l = min(s2.length(), s1.length());
        int x = 0;
        for(int i = 0; i<l; i++){
            if(s1[i]!=s2[i]) break;
            x++;
        }
        int ans = s1.length()-x + s2.length()-x + x;
        if(x>0)ans++;
        cout<<ans<<ln;
    }    
    return 0;
}