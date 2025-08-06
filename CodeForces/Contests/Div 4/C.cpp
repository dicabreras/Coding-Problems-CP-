#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int t; cin>>t;
    while(t--){
        bool ans= true;
        int r[13] = {};
        int a[4];
        for(int i = 0; i<4; i++){
            cin>>a[i];
            if(i<2)r[a[i]]= 1;
            else r[a[i]]=2;
        }
        sort(a, a+4);
        int temp=r[a[0]];
        for(int i = 1; i<4; i++ ){
            if(temp == r[a[i]])
                ans = false;
            else temp = r[a[i]];
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}