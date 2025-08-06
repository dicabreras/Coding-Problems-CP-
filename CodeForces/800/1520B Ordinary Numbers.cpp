#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, n;
    cin>>t;
    for (int i = 0; i<t; i++){
        int result =0, ordinary_num = 0;
        cin>>n;
        for(int j = 0; j<=9; j++){
            int num_exp = pow(10, j);
            if (n>=num_exp && n<=num_exp*10){
               // cout<<"j:  "<<j<<"  exponente:  "<<num_exp<<endl;
                int num_modul = (n/num_exp);
                result+=((9*j)+num_modul);  
                for(int h = 0; h<=j; h++){
                    ordinary_num+=(pow(10,h)*num_modul);
                 //   cout<<"ordinary number limit:   "<<ordinary_num<<"\n";
                }
                
            if(n<ordinary_num || n == num_exp*10){
                result-=1;
            }  
                break;             
            }
            else{
                continue;
            }
           
        }
        cout<<result<<"\n";
    }
    return 0;
}
