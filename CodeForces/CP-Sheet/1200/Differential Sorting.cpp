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
        int n, f = 1; 
        cin >> n;
        int a[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        if(a[n-1]<a[n-2]){
            // It is impossible to modify the last 2 elements;
            f = 0;
        }
        else if(a[n-1]<0){
            // each element of the array must be negative if the last number is negative
            f++;
            for(int i = 0; i+1<n; i++){
                if(a[i]>a[i+1]) f = 0;
            }
        }
        if(!f){
            cout<<-1<<ln;
            continue;
        }
        else if(f == 2){
            cout<<0<<ln;
            continue;
        }
        cout<<n-2<<ln;
        for(int i = 1; i<=n-2; i++){
            cout<<i<<" "<<n-1<<" "<<n<<ln;
        }
    }

    return 0;
}
