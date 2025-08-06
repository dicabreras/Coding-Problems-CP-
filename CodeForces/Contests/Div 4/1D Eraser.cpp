#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int t; cin>>t;
    while(t--){
        int n, k, ans = 0;
        cin>>n>>k;
        char a[n];
        queue<int> pos_b;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i]=='B'){
                pos_b.push(i);
            }
        }
        while(!pos_b.empty()){
            int current = pos_b.front(); pos_b.pop();
            while(!pos_b.empty() && current + (k-1) >= pos_b.front()) pos_b.pop();
            ans+=1;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}
//https://codeforces.com/contest/1873/problem/D
