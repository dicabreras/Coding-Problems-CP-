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

    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        int a[n], pfx_sum[n] = {};
        for(int i = 0; i<n; i++){
            cin >> a[i];
            pfx_sum[i] = a[i];
            if(i>0) pfx_sum[i]+=pfx_sum[i-1];
        }
        if(pfx_sum[n-1]<s){
            cout<<-1<<ln;
            continue;
        }
        int mx = 0;
        for(int i = 0; i<n; i++){
            int l = i, r = n;
            while(l+1<r){
                int mid = l + (r-l)/2;
                if(f(pfx_sum, i, mid, s)){
                    l = mid;
                }
                else r = mid;
            }
            int sum = pfx_sum[l];
            if(i>0) sum-=pfx_sum[i-1];
            if(sum!=s) continue; 
            int x = l-i+1;
            mx = max(mx, x);
        }
        cout<<n-mx<<ln;
        
    }
    return 0;
}