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
 

int f(ll mid, ll* a, int n, int c){
    int cnt = 1;
    ll current = a[0];
    for(int i = 1; i<n; i++){
        if(a[i]-current>=mid){
            cnt++;
            current = a[i];
        }
    }
    if(cnt >= c) return 1;
    return 0;
}


int main(){
    int t; cin >> t; 
    while(t--){
        int n, c; cin >> n >> c;
        ll a[n]; 
        for(int i = 0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        ll l = 0, r = a[n-1]-a[0]+10;
        while(l+1<r){
            ll mid = l + (r-l)/2;
            if(f(mid, a, n, c)){
                l = mid;
            }
            else r = mid;
        }
        cout<<l<<ln;
    }

    return 0;
}