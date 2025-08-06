#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    int t, n_passengers, m_steps, k_height, vlad_h; 
    cin>>t;
    for(int i = 0; i<t; i++){
        cin>>n_passengers>>m_steps>>k_height>>vlad_h;
        int passengers_h[n_passengers], num_people=0;
        for(int h = 0; h<n_passengers; h++){
            cin>>passengers_h[h];
        }
        for(int passenger: passengers_h){
            if((vlad_h-passenger)%k_height == 0 && (vlad_h-passenger)!=0){
                if((m_steps-1)*k_height>=abs(vlad_h-passenger)){
                    num_people++;
                }
            }
        }
        cout<<num_people<<"\n";
    }
    return 0;
}

// link problem:  https://codeforces.com/contest/1851/problem/A

