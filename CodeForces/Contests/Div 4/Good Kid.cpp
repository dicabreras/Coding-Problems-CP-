#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
    int t; 
    cin>>t;
    while(t--){
        int n, min = 9, ans = 1; cin>>n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i]; 
            if(a[i]<min) min = a[i];
        }
        bool flag = false;
        for(int i: a){
            if(i==min && !flag){
                flag = true;
                i++;
            }
            ans*=i;
        }
        cout<<ans<<"\n";
    }
}