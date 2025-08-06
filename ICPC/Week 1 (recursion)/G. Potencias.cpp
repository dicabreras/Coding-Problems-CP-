#include <bits/stdc++.h>
using namespace std;
long long power(long long ans, int b, int e);
int main(int argc, char const *argv[]){
    int b, e;
    cin>>b>>e;
    if(e==0)cout<<1;
    else cout<<power(b, b, e);
    return 0;
}
long long power(long long ans, int b, int e){
    if(e==1)return ans;
    return power(ans*b, b, e-1);
}