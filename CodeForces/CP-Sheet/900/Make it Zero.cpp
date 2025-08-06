#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

int main(){
    int t; cin>> t;
    while(t--){
        int n; cin>> n;
        vector<pi> a;
        int ar[n];
        for(int i = 0; i<n; i++)cin>>ar[i];
        if(n%2 == 0){
            a.pb(mp(1,n));
            a.pb(mp(1,n));            
        }
        else{
            a.pb(mp(1,n-1));
            a.pb(mp(1, n-1));
            a.pb(mp(n-1, n));
            a.pb(mp(n-1, n));
        }
        cout<<a.size()<<ln;
        for(auto p : a) cout<<p.ff<<" "<<p.ss<<ln;
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1869/A