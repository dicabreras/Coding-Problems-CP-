#include <bits/stdc++.h>
using namespace std; 

#define ln '\n';
#define INF 1e9;
#define mod 1e9+7;
typedef long long ll;

#define between(a, b, c) (a<=b && b<=c)


vector<string> grid; 
int dp[1010][1010] = {};
int n;


int solve(int y, int x){
    //BASE CASE
    if( x == 0 &&  y == 0) return 1; 
    if(dp[y][x] != 0) return dp[y][x];
    if(grid[y][x] == '*' ) return 0;

    if(between(0, y-1, n-1)) dp[y][x] += solve(y-1, x); // Either coming from up or coming from left
                                                      // which means down and up moves
    if(between(0, x-1, n-1)) dp[y][x] += solve(y, x-1);                                       
   // cout<<"x: "<<x<<"  "<<"y: "<<y<<" dp:  "<< dp[y][x]<<ln;
    return dp[y][x];
}


int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        string s;
        cin>> s;
        grid.push_back(s);
    }
    
    cout<<solve(n-1, n-1);

    return 0;
}