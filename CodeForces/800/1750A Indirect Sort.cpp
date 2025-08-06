#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n, m=11; cin>>n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i]<m) m=a[i];
        }
        cout<<(m==a[0]? "Yes":"No")<<'\n';
    }
    return 0;
}
