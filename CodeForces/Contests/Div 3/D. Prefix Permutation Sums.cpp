#include <bits/stdc++.h>
using namespace std;
bool solve();
int main()
{
    int t; 
    cin>>t;
    while (t--)
    {
        cout<<(solve()? "YES":"NO")<<"\n";
    }  
    return 0;
}
bool solve(){
    long long n;
    cin>>n;
    long long permutation[n]={0}, sum = (n*(n+1))/2;

    for(long long i = 0; i<n-1; i++){
        cin>>permutation[i+1]; 
    }
    long long last_num = permutation[n-1];

    if(last_num > sum){
        return false;
    }
    else{
        long long numbers[n]={}, weird_num = 0, cont = 0, num = 0, p_sum=0;   
        for(long long i = 0, j = 1; j<n; i++, j++){
            num = permutation[j]-permutation[i];
            sum-=num;

            if(sum<0){
              
                return false;
            }
            else{
                if(num>n || numbers[num-1]!=0){
                    weird_num = num;
                }
                
                else{                  
                    numbers[num-1] = num;                      
                }
            }
        }     
        for(long long i = 0; i<n; i++){
            if (cont>2){
                return false;
            }
            else if(numbers[i] == 0){               
                cont++;
                p_sum+=(i+1);
            }  
        }
        if(cont == 1){
            return true;
        }
        else if(p_sum == weird_num){
            return true;
        }
        else{
            return false;
        }
    }
}
