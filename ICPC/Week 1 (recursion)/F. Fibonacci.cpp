#include <bits/stdc++.h>
using namespace std;
int n_fibonacci(int f);
int main(int argc, char const *argv[]){
    int f; 
    cin>>f;
    cout<<n_fibonacci(f);
    return 0;
}
int n_fibonacci(int f){
    if(f==0)return f;
    if(f==1)return f;
    return n_fibonacci(f-2)+n_fibonacci(f-1);
}
