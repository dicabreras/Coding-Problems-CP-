/*
Coded by Diego Cabrera
*/
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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n];
        map<int, int> m;
        for(int i = 0; i<n; i++){
            cin >> a[i]; 
            m[a[i]]++;
        }
        int ans = 0, prev_cnt = 0, prev = 0;
        for(auto [x, cnt] : m){
            if(!prev){
                prev = x;
                prev_cnt = cnt;
            }
            else{
                if(prev+1<x){
                    ans+=prev_cnt;
                    prev = x;
                    prev_cnt = cnt;
                }
                else if(cnt>=prev_cnt){
                    prev_cnt = cnt;
                    prev = x;
                }
                else{
                    ans+=(prev_cnt-cnt);
                    prev_cnt = cnt;
                    prev = x;

                }
            }
        }
        ans+=prev_cnt;
        cout<<ans<<ln;
        
    }
    return 0;
}