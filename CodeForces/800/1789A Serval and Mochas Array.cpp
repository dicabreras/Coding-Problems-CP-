#include <bits/stdc++.h>
using namespace std;

// The solution has to be approached applying the euclidean algorithm GCD (greates common divisor)

bool euclidean_algorithm(long long a[], int n){
    bool ans = false;
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            long long m0 = min(a[i], a[j]), m1 = max(a[i], a[j]);
            while(!ans){
                long long r = m1%m0;
                if(r==0){
                    if(m0<=2) ans=true;
                    else break;
                }
                else{
                    m1=m0; m0=r;
                }
            }
            if(ans) return ans;
        }
    }
    return ans;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long a[n];
        for(int i = 0; i<n; i++)cin>>a[i];

        bool ans = euclidean_algorithm(a, n);
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

//https://codeforces.com/problemset/problem/1789/A
