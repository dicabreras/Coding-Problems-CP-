#include <bits/stdc++.h>
using namespace std;

int reversado(int n, int ans);
int main(int argc, char const *argv[])
{
    int num;
    cin>>num;
    cout<<reversado(num, 0);
    return 0;
 }

int reversado(int n, int ans){
    if(n==0){
        return ans;
    }

    return reversado(n/10, ans*10 + n%10);
}