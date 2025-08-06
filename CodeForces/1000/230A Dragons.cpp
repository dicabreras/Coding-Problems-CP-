#include<bits/stdc++.h>
using namespace std; 

int main()
{
    int kirito_str, t, flag = 1;
    cin>>kirito_str>>t;
    int cases[t][2];
    for(int i = 0; i<t; i++){
        cin>>cases[i][0]>>cases[i][1];
        for(int j = i-1, g=i; j>=0; j--, g--){
            if(cases[g][0]<cases[j][0]){
                int temp_0 = cases[j][0], temp_1 = cases[j][1];
                cases[j][0]=cases[g][0], cases[j][1]=cases[g][1];
                cases[g][0]=temp_0, cases[g][1]=temp_1;            //sorting the bidimensional array
                continue;
            }
            else{                
                break;
            }            
        }
    }
    for(int m = 0; m<t; m++){ 
        if(kirito_str > cases[m][0]){
            kirito_str+=cases[m][1];        
        }
        else{
            flag = 0;
            break;
        }
    }
    switch (flag)
    {
    case 1:
        cout<<"YES\n";
        break;
    
    case 0:
    cout<<"NO\n";
        break;
    default:
        flag = 1;    
    }
    return 0;
}


