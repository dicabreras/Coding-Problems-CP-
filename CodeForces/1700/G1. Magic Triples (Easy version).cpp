#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a, a+n);
        int cont = 3;
        for(int i=0, j=1, k=2; k<n; k++){
            int a_i = a[i], a_j = a[j], a_k = a[k];
            if(a_i == a_j && a_j != a_k && k<8){
                i++; j++; cont=3;
            }
            else{
                k++;
                cont++;
            }
        }
    }
    return 0;
}
