#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int binary_search(int x){
    int l = 0, r = v.size()-1;
    int mid = l + (r-l)/2;
    while(l<r){
        if(v[mid]<x){
            l=mid+1;
            mid = l + (r-l)/2;
        }
        else if(v[mid]>x){
            r = mid;
            mid = l + (r-l)/2;
        }
        else if(v[mid]==x)return mid;  
    }
    return mid;
}

int main(){
    int n; cin>> n;
    int a[n];
    for(int i = 0; i<n; i++)cin>>a[i];
    v.push_back(a[0]);
    for(int i = 1; i<n; i++){
        if(a[i]>v.back())v.push_back(a[i]);
        else{
            int idx = binary_search(a[i]);
            v[idx]=a[i];
        }
        for(auto a : v) cout<<a<<" ";
        cout<<endl;
    }
    cout<<v.size();

    return 0;
}