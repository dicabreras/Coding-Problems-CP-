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
        int n, s; cin >> n >>  s; 
        int a[n], sum = 0, ones = 0, two = 0, zero = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            sum+=a[i];
            if(a[i] == 1) ones++;
            else if(a[i] == 2) two++;
            else zero++;
        }
        int x = s-ones-two*2;
        if(x!=1 && x>=0){
            cout<<-1<<ln;
        }
        else{
            while(zero--)cout<<0<<" ";
            while(two--) cout<<2<<" ";
            while(ones--) cout<<1<<" ";
            cout<<ln;
        }

    }
    return 0;
}