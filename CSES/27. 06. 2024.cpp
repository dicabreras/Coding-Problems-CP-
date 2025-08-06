#include <bits/stdc++.h>
using namespace std;

#define ll long long 
int n;
int a[101];
int calculated[1000020] = {};
bool flag = false;

int solve(int sum){
    if(sum == 0){
        flag = true;
        return 0;
    }
    if(calculated[sum]>0) return calculated[sum];
    int mn = 1e7;
    for(int i = 0; i<n; i++){
        if(sum-a[i]>=0) mn = min(mn, solve(sum-a[i])+1);
    }
    calculated[sum] = mn;
    return mn;
}

int main(){
    int x; cin>> n >> x; 
    memset(calculated, 0, sizeof(calculated));
    for(int i = 0; i<n; i++)cin>>a[i];
    int ans = solve(x);
    if(flag)cout<<ans;
    else cout<<-1;
}
