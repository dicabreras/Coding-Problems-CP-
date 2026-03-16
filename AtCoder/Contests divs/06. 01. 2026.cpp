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
vector<vi> chains;
vi chain;


void search(int n, int k){
    if(chain.size() == k){
        chains.pb(chain);
    }
    else{
        for(int i = 1; i<=n; i++){
            chain.pb(i);
            search(n, k);
            chain.pop_back();
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */

    int n, k, x;
    cin >> n >> k >> x;
    vector<string> v;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        v.pb(s);
    }
    sort(v.begin(), v.end());
    search(n, k);
    vi p = chains[x-1];
    for(auto i : p){
        cout<<v[i-1];
    }
    
    return 0;
}