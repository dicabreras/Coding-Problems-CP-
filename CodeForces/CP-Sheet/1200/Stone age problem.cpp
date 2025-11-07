/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
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

int f(int* pfx_sum, int l, int r, int s){
    int sum = pfx_sum[r];
    if(l>0) sum-=pfx_sum[l-1];
    if(sum>s) return 0;
    else return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    ll n, q; cin >> n >> q;
    ll a[n], sum = 0, b[n] = {}; 
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll prev = 0, x;
    set<int> s;
    while(q--){
        int t; cin >> t; 
        if(t==1){
            int i; 
            cin >> i >> x;
            if(!b[i-1] && prev>0){
                a[i-1] = prev;  
            }
            b[i-1] = 1;
            sum-=a[i-1];
            sum+=x;
            a[i-1] = x;
            s.insert(i-1);
        }
        else{
            cin >> x;
            prev = x;
            sum = x*n;
            for(auto i : s) b[i] = 0;
            s.clear();
        }
        cout<<sum<<ln;
    }
    return 0;
}