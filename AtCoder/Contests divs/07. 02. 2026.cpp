/*
Coded by Diego Cabrera
Codeforces username: CaSala
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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int N = a[n-1];
    int b[N] = {}, ones = n;
    for(int i = 0, j = 0; i<N; i++){
        while(i<a[j]){
            b[i]+=ones;
            i++;
        }
        i--;
        j++;
        ones--;
    }

    vi ans;
    for(int i = 0; i<N; i++){
        int d = b[i]%10, q = b[i]/10;
        if(i<N-1){
            b[i+1]+=q;
            ans.pb(d);
        }
        else{
            ans.pb(b[i]);
        }
    }

    for(int i = N-1; i>=0; i--){
        cout<<ans[i];
    }

    return 0;
}