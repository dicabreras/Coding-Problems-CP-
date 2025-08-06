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
        int n, q; cin>> n >> q;
        int p[n], pfx_min[n], pfx_mx[n], mn = 1e9+7, mx = 0; 
        for(int i = 0; i<n; i++){
            cin>>p[i];
            
            

        }


        string s; 
        cin>> s;
        int cnt_idx = 0;
        while(q--){
            int x; cin>> x;
            x--;
            bool flag = true;
            
            for(int i = 0, j = 1; j<n; i++, j++){
                if(s[i]=='L' && s[j]=='R'){
                    cnt_idx++;
                }
            }
            if(s[x] == 'L'){
                s[x] = 'R';
                if(x-1>=0 && s[x-1] == 'L') cnt_idx++;
            }
            else{
                s[x] = 'L';
                if(x+1<n && s[x+1] == 'R') cnt_idx++;
            }


            
            
            


        }
    }    
    return 0;
}