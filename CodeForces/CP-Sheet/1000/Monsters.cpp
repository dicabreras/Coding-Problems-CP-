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
        int n, k; cin>> n >> k;
        priority_queue<pi> q;
        for(int i = 0; i<n; i++){
            int x; cin>> x;
            if(x%k>0) x = x%k;
            else x = k; 
            q.push(mp(x,-i-1));
        }
        while(!q.empty()){
            pi current = q.top();
            q.pop();
            cout<<-current.ss<<" ";
        }
        cout<<ln;          
    }   
    return 0;
}