#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    int n, m, steps, n_plus, m_mod;
    cin>>n>>m;
    if(m>n){
        cout<<-1;
        return 0;
    }

    else if(n%2 == 1){
        steps = (n/2)+1;
    }
    else{
        steps = n/2;
    }  
    n_plus = n/2;
    m_mod = steps%m;
    if(m>m_mod && m_mod!=0){
        steps+=(m-m_mod);
    }      
    else{
        steps+=m_mod;
    }
    cout<<steps;
    return 0;
}

//https://codeforces.com/problemset/problem/476/A