#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    long long n, m, a, num_x, num_y;

    cin>>n>>m>>a;
    
    for(int x = 1; 0<n; n-=a, x++){
        num_x=x;
    }
    for(int y = 1; 0<m; m-=a, y++){
        num_y=y;
    }
    cout<<num_x*num_y;
    return 0;
}
