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
        ll n, x, y; cin >> n >> x >>y;
        ll t1 = n/x, t2 = n/y, m = lcm(x,y), z = n/m;
        ll sum = 0;
        t1-=z;
        t2-=z;
        ll q1 = n-t1, ss1 = q1*(q1+1)/2;
        ll s1 = n*(n+1)/2 - ss1, s2 = t2*(t2+1)/2;
        sum+=(s1-s2);

        cout<<sum<<ln;
    }
    return 0;
}