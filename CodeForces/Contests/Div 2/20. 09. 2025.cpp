/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
*/
#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;  
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2*n] = {};
        a[n-1] = n;
        a[2*n-1] = n;
        if(n == 1){
            cout<<1<<" "<<1<<ln;
        }
        else if(n == 2){
            cout<<1<<" " <<2<<" "<<1<<" "<<2<<ln;
        }
        else{
            a[n] = n-1;
            a[1] = n-1;
            a[0] = n-2;
            a[]
            for(int i = 0, x = n-1; x>=1; i++, x=-2){
                if(n == 1) continue;
                a[i] = x;
                a[n-i-1] = x;
            }
            for(int i = 1, x = n-3; x>=1; i++, x-=2){ 
                a[n+i] = x;
                a[2*n-2-i] = x;
            }
            for(auto i : a) cout<<i<<" ";
            cout<<ln;
        }

    } 

    return 0;
}
