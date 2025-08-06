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
            int a[n]; 
            for(int i = 0; i<n; i++) cin >> a[i];
            int l = 0, r = n-1, mn = 1, mx = n;
            while(l<r){
                if(a[l]!=mn && a[l]!=mx && a[r]!=mn && a[r]!=mx) break;
                else if(a[l] == mn){
                    l++;
                    mn++;
                }
                else if(a[l] == mx){
                    l++;
                    mx--;
                }
                else if(a[r] == mx){
                    r--;
                    mx--;
                }
                else if(a[r] == mn){
                    r--;
                    mn++;
                }

            }
            if(r-l>=3) cout<<l+1<<" "<<r+1<<ln;
            else cout<<-1<<ln;

        }
    return 0;
}