#include <bits/stdc++.h>
using namespace std; 
int main(int argc, char const *argv[])
{
    long long t;
    cin>>t;
    while (t--)
    {
        int n, cont = 1; cin>>n;  
        int m = (n*(n-1))/2, max_num = n-1, array_num[m], real_array[n];
        for(int i = 0; i<m; i++){
            cin>>array_num[i];
        }
        sort(array_num, array_num+m);
        int num = array_num[0], j=0;
        for(int i  = 0; i<m; i+=--n){
             cout<<array_num[i]<<" ";      
        }        
        cout<<"1000000000\n";      
    }    
    return 0;
}
