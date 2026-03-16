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
    
    int n; 
    cin >> n; 
    int a[n], b[n] = {};
    vi ans;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<n; i++){
        if(b[i]!=0) continue;
        vi cicle;
        int j = i, N = 0, a0 = a[i];
        while(!b[j]){
            cicle.pb(j);
            j = a[j];
            N++;
        }
        if(a[j] = j){
            b[i] = -j;
            continue;
        }
        j = i;
        for(int h = 0; h<N; h++){
            b[j] = N;
            j = a[j];
        }
    }
    for(int i = 0; i<n; i++){
        int m = lcm(b[i], 10), p = 10, q = 1;
        while(p<m){
            p*=10;
            q++;
        }
        int x = p/m, r = p%m;
        while(q<=100){
            x = r*10;
            r = x%m;
            x/=m;
            q++;
        }
        int res = r%b[i], h = i;
        for(int j = 0; j<res; j++){
            int h = a[h];
        }
        ans.pb(h);
    }
    for(auto i : ans ) cout<<i<<" ";

    return 0;
}