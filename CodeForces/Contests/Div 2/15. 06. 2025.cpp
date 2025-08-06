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
        int w, h, a, b; 
        cin >> w >> h >> a >> b;
        int x1, x2, y1, y2, f = 0; 
        cin >> x1 >> y1 >> x2 >> y2;
        
        if((x1+a - x2)%a==0 && abs(x1-x2)>0) f= 1;

        if((y1+b-y2)%b == 0 && abs(y1-y2)>0 ) f = 1;
        
        if(f) cout<<yes<<ln;
        else cout<<no<<ln;
        
    }
    return 0;
}