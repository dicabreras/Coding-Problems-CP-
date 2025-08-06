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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int t; cin >> t;
    while(t--){
        string s; cin >> s; 
        set<char> S; 
        int n = s.size(), f = 1;
        string p;
        for(int i = 0; i<n; i++){
            if(!S.count(s[i]) && f){
                p.pb(s[i]);
            }
            else f = 0;
            S.insert(s[i]);
        }
        f = 1;
        int nn = p.size();
        for(int i = 0; i<n; i++){
            int j = i%nn;
            if(s[i] != p[j]) f = 0;
        }
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;
            
    }
    return 0;
}