#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n; cin>>n;
    long long a[n], sum_0 = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        sum_0+=a[i];
    }
    long long b[n-1], sum_1 = 0;
    for(int i = 0; i<n-1; i++){
        cin>>b[i];
        sum_1+=b[i];
    }
    long long c[n-2], sum_2 = 0;
    for(int i = 0; i<n-2; i++){
        cin>>c[i];
        sum_2+=c[i];
    }
    cout<<sum_0-sum_1<<"\n"<<sum_1-sum_2;
    return 0;
}
