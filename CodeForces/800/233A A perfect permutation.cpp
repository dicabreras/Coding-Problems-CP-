#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    if(n%2!=0)cout<<-1;
    else{
        int a[n];
        for(int i = 0, num = 1; i<=n; i+=2, num+=2){
            a[i]=num+1; a[i+1]=num;     
        }
        for(int i = 0; i<n; i++) cout<<a[i]<<" ";
    }  
    return 0;
}
// https://codeforces.com/problemset/problem/233/A
