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

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif

    int t; cin>> t;
    while(t--){
        int n, k; cin>> n >> k;
        int a[n]; 
        for(int i = 0; i<n; i++) cin>>a[i];
        sort(a, a+n);
        int mx = 0;
        if(n>1){
            int count = 1;
            for(int i = 0, j = 1; j<n; i++, j++){
                if(a[j]-a[i]<=k) count++;
                else{
                    if(count>mx) mx = count;
                    count = 1;
                }
            }
            if(count>mx)mx=count;
            cout<<n-mx<<ln;
        }
        else{
            cout<<0<<ln;
        }
        
        
    }

    return 0; 
}