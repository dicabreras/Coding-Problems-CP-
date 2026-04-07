    /*
Coded by Diego Cabrera
Codeforces username: CaSala
Problem: https://atcoder.jp/contests/abc452/tasks/abc452_c
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
#define between(a, b, c) (a<=b && b<=c)

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const ll M = 998244353;



int main(){
   // ios::sync_with_stdio(false);
   // cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n; 
    cin >> n; 

    vector<pi> pos (n);
    
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        pos[i]={a,b};
    }


    int m; 
    cin >> m;
    vector<string> chains (m);
    vector<set<pair<char, int>>> idx (10);

    for(int i = 0; i<m; i++){
        cin >> chains[i];
        int N = chains[i].size();
        for(int j = 0; j<N; j++){
            idx[N-1].insert({chains[i][j], j});
        }
    }

    int ans[m];

    for(int i = 0; i<m; i++) ans[i] = 1;

    for(int i = 0; i<m; i++){
        int N = chains[i].size();
        if(N != n){
            ans[i] = 0;
            continue;
        }
        for(int j = 0; j<n; j++){
            int sz = pos[j].ff - 1, x = pos[j].ss - 1;
            if(idx[sz].size() == 0) continue;
            if(!idx[sz].count({chains[i][j], x})){
                ans[i] = 0;
                break;
            }
        }
    }
    for(int i = 0; i<m; i++){
        if(ans[i]){
            cout<<"Yes"<<ln;
        }
        else cout<<"No"<<ln; 
    }

    return 0;
}