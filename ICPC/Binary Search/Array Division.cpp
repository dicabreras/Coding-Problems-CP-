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
 

int f(ll mid, ll* a, int n, int k){
    ll p_sum = 0;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(a[i]>mid) return 0;
        else if(i == n-1 && p_sum+a[i]<=mid) cnt++;
        else if(i==n-1 && p_sum+a[i]>mid){
            cnt+=2;
            continue;
        }
        else if(p_sum+a[i]<=mid) p_sum+=a[i];
        else{
            cnt++;
            p_sum = a[i];
        }
    }
    if(cnt<=k) return 1;
    return 0;
}


int main(){
    int n, k; cin >> n >> k;
    ll a[n]; 
    for(int i = 0; i<n; i++) cin >> a[i];
    ll l = 0, r = 1e18+7;
    //ll l = 0, r = 10;
    while(l+1<r){
        ll mid = l + (r-l)/2;
        if(f(mid, a, n, k)) r = mid;
        else l = mid;
    }
    cout<<r;
    return 0;
}