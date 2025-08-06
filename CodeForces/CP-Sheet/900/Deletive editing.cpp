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
        string s, o; 
        cin>> s >> o;
        int abc[26] = {};
        int flag = true;
        int j = s.size()-1;
        for(int i = o.size()-1; i>=0; i--){
            int c = (int) o[i]-65;
            if(abc[c] == 1){
                flag = false;
                break;
            }
            while(o[i]!=s[j]){
                if(j<0){
                    flag = false;
                    break;
                }
                abc[(int) s[j] - 65]  = 1;
                j--;
            }
            j--;
        }
        if(flag) cout<<yes<<ln;
        else cout<<no<<ln;
    }
    return 0;
}