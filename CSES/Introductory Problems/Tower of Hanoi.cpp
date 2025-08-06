#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

void solve(int n, int A, int C, int B){
    if(n == 1){
        cout<< A <<" "<< C <<ln;
    }
    else{
        solve(n-1, A, B, C);
        cout<< A <<" "<< C <<ln;
        solve(n-1, B, C, A);
    }
}

int main(){
    int n; cin>> n;
    cout<<pow(2, n) -1<<ln;
    solve(n, 1, 3, 2);

    return 0;
}