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
    
    int n; cin>> n;
    int a[n];
    map<int, int> m1, m2;
    for(int i = 0; i<n; i++){
        cin>> a[i];
        if(m1.count(a[i])) m1[a[i]]++;
        else m1[a[i]] = 1;
    }
    ll ans = 0;
    for(auto x : a){
        if(m2.count(x)) continue;
        m2[x] = 1;
        if(m1[x]<x) ans+=m1[x];
        else{
            ans+=(m1[x]-x);
        }
    }
    cout<<ans;

    return 0;
}