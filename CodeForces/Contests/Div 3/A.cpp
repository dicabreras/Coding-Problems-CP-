#include <bits/stdc++.h>
using namespace std;


int X(int x, int y){

    int two  = y/2; 
    two+= y%2;
    return two;
}

int Y(int x, int y){
    int one = x/15;
    if(x%15>0)one++;
    return one;
}
int XY(int x, int y){
    int ans = 0;
    int two  = y/2; 
    two+= y%2;
    ans+=two;
    int squares = (15*two) - (4*y);
    if(x>squares){
        ans+=((x-squares)/15);
        if((x-squares)%15>0)ans++;
    }
    return ans;
}


int main()
{
    int t; cin>>t; 

    while(t--){
        int ans;
        int x, y; cin>> x >> y;   
        if(x==0 && y!=0) ans = X(x,y);
        else if(x!=0 && y == 0) ans=Y(x,y);
        else if(x==0 && y == 0)ans = 0;
        else ans = XY(x,y);
        cout<<ans<<"\n";
    }
    return 0;
}
