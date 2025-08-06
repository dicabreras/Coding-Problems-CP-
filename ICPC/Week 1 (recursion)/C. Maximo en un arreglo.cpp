#include <bits/stdc++.h>
using namespace std; 
int max_in_array(int a[], int i, int size, int max);
int main(int argc, char const *argv[])
{
    int n; cin>>n;
    int a[n];
    for(int i = 0; i<n; i++)cin>>a[i];
    cout<<max_in_array(a, 1, n, a[0]);
    return 0;
}
int max_in_array(int a[], int i, int size, int max){
    if(i == size)return max;
    if(a[i]>max)max = a[i];
    return max_in_array(a, i+1, size, max);
}
