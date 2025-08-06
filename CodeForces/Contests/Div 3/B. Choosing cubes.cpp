#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int solve(){
    int n, f, k; cin>> n >> f >> k;
    int a[n];
    for(int i = 0; i<n; i++)cin>>a[i];

    int fav = a[f-1];
    sort(a, a+n, greater<int>());

    if(a[k-1]<=fav && a[k]<fav) return 1;
    if(a[k-1]==fav && a[k]==fav) return 2;
    if(a[k-1]>fav) return -1;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int ans = solve();
        if(ans == 1)cout<<"YES\n";
        else if(ans == -1) cout<<"NO\n";
        else if(ans == 2) cout<<"MAYBE\n";
    }
    return 0;
}
