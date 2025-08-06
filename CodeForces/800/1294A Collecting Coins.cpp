#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, coins[3], max_owner, P_coins;

    cin>>t;

    for(int i = 0; i<t; i++){
        for(int c = 0; c<3; c++){
            cin>>coins[c];
        }
        cin>>P_coins;
        max_owner = *max_element(coins, coins+3); // function to get the max element in an array
        for(const int &k_sister: coins){
            if(k_sister!=max_owner){
            P_coins-=(max_owner-k_sister);
            }
        }
        if(P_coins%3 ==0 && P_coins>=0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}

