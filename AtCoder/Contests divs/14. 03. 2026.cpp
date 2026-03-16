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
    

    // Topic : Sliding window;
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    
    ll cnt[26] = {}, ans = 0; // letters' frequencies in the window (valid range) 

    // Open window ahead of the i-th letter 
    for(int i = l; i<=r; i++){
        cnt[s[i] - 'a']++;
    }
    
    for(int i = 0; i+l<n; i++){
        ans+=cnt[s[i] - 'a'];
        cnt[s[i+l] - 'a']--;
        if(i+r+1<n){
            cnt[s[i+r+1] - 'a']++;
        }
    }
        
    cout<<ans;

    return 0;
}