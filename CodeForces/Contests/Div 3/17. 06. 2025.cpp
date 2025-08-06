/*
Coded by Diego Cabrera
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
    
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int d1[10] = {}, d2[10]= {}, d3[10] = {};
        int x = l, y = r, i = 0, n1, n2, n3, z = abs(x-y);
        while(x>0){
            d1[i] = x%10;
            x/=10;
            i++;
        }
        n1 = i;
        i = 0;
        while(y>0){
            d2[i] = y%10;
            y/=10;
            i++;
        }
        n2 = i;
        i = 0;
        while(z>0){
            d3[i] = z%10;
            z/=10;
            i++;
        }
        n3 = i;
        int mn = 2*max(n1,n3);
        for(int j = 0; j<max(n1,n3); j++){
            if(abs(d1[j]-d3[j])==1 || abs(d1[j]-d3[j])==9) mn-=1;
            else if(abs(d1[j]-d3[j])>1) mn-=2;

        }
        cout<<mn<<ln;
    }
    return 0;
}