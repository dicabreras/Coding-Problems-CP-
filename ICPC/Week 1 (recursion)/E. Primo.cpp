#include <bits/stdc++.h>
using namespace std; 
bool prime(int n, int k);
int main(int argc, char const *argv[]){
    int n; 
    cin>>n;
    int k;
    if((int)sqrt(n)%2==0)k=(int)sqrt(n)+1;
    else k = (int)sqrt(n);
    if(prime(n, k))cout<<"si";
    else cout<<"no";
    return 0;
}
bool prime(int n, int k){
    if(n==1 || (n%2==0&&n!=2))return false;
    if(k == 1 || n == 2)return true;
    if(n%k==0)return false;
    else return prime(n, k-2);
}
