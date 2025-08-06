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
        int n;
        char c;
        string s;
        cin>> n >> c >> s;
        int a[n];
        memset(a, -1, sizeof(a));
        int l = s.size(), current = -1, i = l-1;
        while(a[i] == -1){
            if(s[i] == 'g') current = i;
            a[i] = current;
            i--;
            if(i==-1) i = l-1;
        }
        int mx = 0, d;
        for(int i = 0; i<l; i++){
            if(s[i] == c){
                d = i;
                if(a[i] < i){
                    d = l-i;
                    d*=(-1);
                }
                mx = max(mx, a[i]-d);
            }
            
        }
        cout<<mx<<ln;
        
    }   
    return 0;
}