#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a, b, c, ans = -1;
    cin>>a>>b>>c;
    if(a+1 != c) cout<<-1<<'\n';
    else{
        int n = a+b+c;
        queue<int> q;
        int z = 1;
        q.push(z);
        while(n>0){
            z = 0;
            int capacity = q.front(); 
            while(capacity>0){
                if(a>0){
                    a--; n--;
                    z+=2;
                    capacity--;
                }
                else if(b>0){
                    b--; n--;
                    z++;
                    capacity--;
                }
                else if(c>0){
                    c--; n--;
                    capacity--;
                }            
            }
            q.pop();
            q.push(z);
            ans++;
        }
        cout<<ans<<'\n';
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        solve();

    }
    
    return 0;
}
