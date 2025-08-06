#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; 
    cin>>n>>m;
    int a[m] = {};
    for(int i = 0; i<n; i++){
        int idx; 
        cin>>idx;
        a[idx-1]++;
    }
    double ans;
    for(int i: a){
        ans = i/12;
        if(i %12 >0)ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
