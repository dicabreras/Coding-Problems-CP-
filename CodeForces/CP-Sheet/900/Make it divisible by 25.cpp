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
        int mn = 18;
        for(int i = s.length()-1, stp = 0; i>=0; i--, stp++){
            if(s[i]=='0'){
                for(int j = i-1, stps = stp; j>=0; j--, stps++){
                    if(s[j]=='0' || s[j] == '5'){
                        mn = min(mn, stps);
                        break;
                    }
                }
            }
            if(s[i] == '5'){
                for(int j = i-1, stps = stp; j>=0; j--, stps++){
                    if(s[j] == '2' || s[j] == '7'){
                        mn = min(mn, stps);
                        break;
                    }
                }
            }
        }

        cout<<mn<<ln;
    }    
    return 0;
}