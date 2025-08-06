#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n, int q, int s){
    if(n%2==0 && n>2) return false;
    if(n%q==0) return false;
    if(q>s)return true;
    else{
        return isPrime(n, q+2, s);
    }
}

int main()
{
    int n; cin>>n;
    int s = sqrt(n);
    int ans=n;
    if(n==2)cout<<4;
    else{
        bool flag = isPrime(n, 3, s);
        if(flag)cout<<ans+1;
        else cout<<ans;
    } 
    return 0;
}
