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
        int n; cin >> n; 
        int a[n], d = 0;
        for(int i = 0; i<n; i++){
            cin >> a[i];
            if(i>0){
                d+=abs(a[i]-a[i-1]);
            }
        }
        int x = 0, l = 0; 
        for(int i = 1; i+1<n; i++){
            if(a[i]<a[i+1] && a[l]>a[i]){ // decreasing array
                x++;
                l = i;
            }
            else if(a[i]>a[i+1] && a[l]<a[i]){ // increasing array
                x++;
                l = i;
            } 
        }
        x+=2;
        if(d == 0) x = 1;
        else if(n <= 2) x = n;
        cout<<x<<ln;
    }
    return 0;
}