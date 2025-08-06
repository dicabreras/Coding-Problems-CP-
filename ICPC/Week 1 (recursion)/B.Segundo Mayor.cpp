#include <bits/stdc++.h>
using namespace std; 
long long second_max(long long, long long, long long, vector<long long>);
int main(int argc, char const *argv[])
{
    int t;
    vector <long long> a;
    long long n;
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>n;
        a.push_back(n);
    }
    long long ans = a[0];
    if(a.size()>1)ans = second_max(a[0], 0, 0, a);
    
    cout<<ans;
    return 0;
}

long long second_max(long long max,long long s_max, long long i, vector<long long> a){
    if(i == a.size())return s_max;
    if(max>a[i] && a[i]>s_max) {
        s_max = a[i];
    }
    else if(a[i]>max){
        s_max = max;
        max = a[i];
    }
    return second_max(max, s_max, i+1, a);
}
