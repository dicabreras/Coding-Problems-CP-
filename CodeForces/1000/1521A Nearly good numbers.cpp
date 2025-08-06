#include <bits/stdc++.h>
using namespace std; 

int main()
{
    long long t, A, B;
    cin>>t;
    while(t--){
        cin>>A>>B;
        long long j = 1; 
        bool flag = true; 
    do{        
        if(B==1){
            cout<<"NO\n";
            flag = false;
        }
        else{
            long long good_num = A*B*j;
            for(long long i = 1; i<(B*j); i++){
                long long x=good_num-(A*i), y=A*i;
                if(x==y){                    
                    continue;
                }
                else{
                    cout<<"YES\n"<<x<<" "<<y<<" "<<good_num<<"\n";
                    flag = false;
                    break;
                }
            }
            j++;                 
        }
    }
    while(flag);
    }
    return 0;
}
//link:  https://codeforces.com/problemset/problem/1521/A