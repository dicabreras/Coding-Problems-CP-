#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, cont_1 = 0, num; cin>>n;
        int array_num[n];
        for(int i = 0; i<n; i++){
            cin>>num;
            if(num%2!=0){
                cont_1++;
            }
        }
        if(cont_1%2!=0){
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }

    }
    return 0;
}
