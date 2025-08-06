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
    
    
        int t; cin>> t;
        while(t--){
            int n; cin >> n;
            int a[n], mx = 0;
            for(int i = 0; i<n; i++){
                cin >> a[i];
                mx = max(mx, a[i]);
            }
            int d = mx, j = n; 
            for(int i = 0; i+1<n; i++){
                if(a[i]==1) continue;
                int temp = gcd(a[i], a[i+1]);
                d = gcd(temp, d);
                if(d == a[i]) j = i;
            }
            int x = 1, h = 0;
            /*
            while(h<j){
                x = max(x, a[h]/d);
                h++;
            }*/
            set<int> s;
            for(int i = 0; i+1<n; i++){
                int d = gcd(a[i], a[i+1]);
                int y = a[i]/d;
                if(!s.count(y)){
                    x*=y;
                    s.insert(y);
                } 
            }
            cout<<x<<ln;
        }
    return 0;
}