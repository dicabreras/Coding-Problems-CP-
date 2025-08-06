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
        string s; cin>> s;
        int ones = 0, zeros = 0;
        for(auto c : s){
            if(c=='0') zeros++;
            else ones++;
        }
        int ans = s.length();
        
        if(zeros> 0 && ones > 0 && ones != zeros){

            for(int i = 0; i<(int)s.length(); ++i){
               if(s[i] == '0')ones--;
                else zeros--;
                if(zeros == -1 || ones == -1){
                    ans = s.length() - i;
                    break;
                }
            }
        }
        if(ones == zeros) ans = 0;
        cout<<ans<<ln;
             
    }   
    return 0;
}
