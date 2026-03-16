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

bool f(int mid, int j, int i){
    int x = mid*mid + j*j;
    if(x<i) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
  
    int n; 
    cin >> n; 
    int a[n+2] = {}, sq = sqrt(n);
    for(int i = 1; i<=sq; i++){
        int j = i+1;
        while(i*i + j*j <= n && i*i + j*j > 4){
            int x = i*i + j*j;
            j++;
            a[x]++;
        }
    }

    vi v;
    for(int i = 1; i<=n; i++){
        if(a[i] == 1) v.pb(i);
    }
    cout<<v.size()<<ln;
    for(auto i : v) cout<<i<<" ";
    cout<<ln;
    
    
    return 0;
}