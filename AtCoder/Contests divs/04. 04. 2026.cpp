    /*
Coded by Diego Cabrera
Codeforces username: CaSala
Problem: https://atcoder.jp/contests/abc449/tasks/abc449_c
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

const int M = 1e9+7;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    

    int n, m; 
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i<n; i++) cin >> a[i] >> b[i]; 
    cin >> m;
    string s[m];
    int len[m];
    map<int, set<char>> dict_letter; 
    map<int, set<int>> dict_pos;
    for(int i = 0; i<m; i++){
        cin >> s[i];
        len[i] = s[i].size();
        for(int j = 0; j<len[i]; j++){
            dict[j].insert({}):
        }
    }

    for(int i = 0; i<m; i++){
        if(len[i] != n) continue;



    }

    return 0;
}