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

const int M = 1e9+7;

int main(){
    int t; cin>>t;
    while(t--){
        int n, s, m; cin>> n >> s >> m;
        int mx=0;
        int l=0;
        for(int i = 0; i<n; i++){
            int l0, r0; cin>> l0 >> r0;
            if(l0-l>mx)mx=l0-l;
            l = r0;
        }
        if(m-l>=mx) mx = m-l;
        if(mx>=s)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}