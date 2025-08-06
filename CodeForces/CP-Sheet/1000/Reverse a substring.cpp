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
    
    int n, l = 0, r; cin >> n;
    string s; cin >> s;
    for(int i = 0; i+1<n; i++){
        if(s[i+1]<s[i]){
            l = i+1;
            r = i+2;
          /*  char temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;*/
            break;
        }
    }
    if(!l) cout<<no<<ln;
    else{
        cout<<yes<<ln;
        cout<<l<<" "<<r<<ln;
    }
    
    return 0;
}