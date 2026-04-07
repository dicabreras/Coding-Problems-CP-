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

const ll M = 998244353;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    

    ll n, m; 
    cin >> n >> m;
    ll a[n+1], b[m+1], sum_a = 0;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        sum_a+=a[i];
    }
    ll z_blocks[m+1];
    for(ll j = 1; j<=m; j++){
         cin >> b[j];
         ll q = n/j, r = n%j, z_block;
         z_block= ((((j*(j-1))/2)%M)*q)%M + ((r*(r+1))/2)%M; 
         z_block%=M;
         z_blocks[j] = z_block;
    }
    ll A = 0, B = 0, ans = 0;
    
    for(int j = 1; j<=m; j++){
        A = (sum_a*(z_blocks[j]*b[j])%M)%M; 
        B+=(sum_a*(z_blocks[j]*b[j])%M)%M;
        B%=M;
    }
    ans= B%M;

    cout<<ans;



    return 0;
}