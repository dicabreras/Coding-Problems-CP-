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
        int n, m; cin>> n >> m;
        int mn = min(m,n);
        vector<string> vec(n); 
        for(int i = 0; i<n; i++){
            string temp; cin>>temp;
            vec[i] = temp;
        }
       // for(auto s: vec) cout<<s<<ln;
       int ans = 0;
        
        while(mn>0){
            stack<char> q; 
            int k = 0, f = 1;

            for(int i = 0; i<n; i++){
                for(int j = k; j<m; j++){
                    char c = vec[i][j];
                    q.push(c);
                }
                k = m-1;
            }
            k = m-2;

            for(int i = n-1; i>0; i--){
                for(int j = k; j>=0; j--){
                    char c = vec[i][j];
                    q.push(c);
                }
                k = 0;
            }
            mn-=2;
            m-=2; n-=2;
            string s;
            int i = 0, l = 0;
            vector<char> x;
            while(!q.empty()){
                x.pb(q.top());
                q.pop();
            }
            

            for(int i = 0; i+3<x.size(); i++){
                if(x[i] == '1' && x[i+1] == '5' && x[i+2] == '4' && x[i+3] == '3')ans++;
            }
            int y = 0;
            for(int i = x.size()-4; i<x.size(); i++, y++){
                if(x[i] == '1' && x[i+1] == '5' && x[i+2] == '4' && x[y] == '3') ans++;
                if(x[i] == '1' && x[i+1] == '5' && x[y-1] == '4' && x[y] == '3') ans++;
                if(x[i] == '1' && x[i+1] == '5' && x[y-1] == '4' && x[y] == '3') ans++;
            }
        }

        
    }   
    return 0;
}