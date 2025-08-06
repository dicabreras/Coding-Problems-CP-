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
        int n; cin>>n;
        string s; cin>>s;
        int mxl = 1, l = 0, mxr = 1, r = 0;
        char prev = s[0];
        if(prev == '<') l++;
        else r++;
        for(int i = 1; i<n; i++){
            if(s[i] == '<'){
                if(prev != '<') l = 0;
                l++;
                r = 0;
                prev = s[i];
            }
            else{
                if(prev != '>') r = 0;
                r++;
                l = 0;
                prev = s[i];
            }
            if(l>mxl) mxl = l;
            if(r>mxr) mxr = r;
        }
        cout<<max(mxl, mxr) + 1<<ln;
    }
    return 0;
}