#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    if(n-2<=1 && n!=1) cout<<"NO SOLUTION";
    else{
        int temp_0 = n+2, temp_1 = n+1;
        while(temp_1!=2 && temp_1!=1) {
            temp_1 = temp_1-2;
            cout<<temp_1<<" ";
        }
        while(temp_0!=2 && temp_0!=1){
            temp_0= temp_0-2;
            cout<<temp_0<<" ";
        }
    }
}