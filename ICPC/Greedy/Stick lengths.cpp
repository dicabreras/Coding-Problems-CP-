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
 
const int M = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int n; cin >> n;
    ll a[n];
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int x;
    if(n%2) x = a[n/2];
    else x = (a[n/2]+a[n/2 - 1])/2;
    ll sum = 0;
    for(auto i : a) sum+=(abs(x-i));
    cout<<sum;
    
    
    return 0;
}