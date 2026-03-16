/*
Coded by Diego Cabrera
Codeforces username: CaSala
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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        ll a[n]; 
        priority_queue<pair<ll, int>> p;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            a[i] = n-a[i];
            p.push({a[i], i});
        }
        int cnt = 1; 
        ll ans = 0;
        int visited[n] = {};
        while(!p.empty()){
            pair<ll, int> current = p.top();
            visited[current.ss] = 1;
            int x = a[current.ss];
            int c1 = current.ss - 1, c2 = current.ss +1, temp = current.ff; 
            if(c1>=0 && !visited[c1]){
                cnt++;
                if(abs(a[c1]-x)>1){
                    ans+=abs(a[c1] - x)-1;
                    p.push({x-1, c1});
                    a[c1] = x-1;
                }
            }
            if(c2<n && !visited[c2]){
                cnt++;
                if(abs(a[c2]-x)>1){
                    ans+=abs(a[c2] -x)-1;
                    p.push({x-1, c2});
                    a[c2] = x-1;
                }
            }
            p.pop();
        }
        cout<<ans<<ln;
    }
    
    return 0;
}