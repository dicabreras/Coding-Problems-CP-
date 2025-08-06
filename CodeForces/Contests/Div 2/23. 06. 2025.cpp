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
        int fr[100005] = {}, cnt[100006] ={};
        int a[n], mx = 0;
        map<int, int> m;
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            a[i] = x;
            fr[x]++;
            mx = max(mx, x);
            m[x]++;
        }
        for(int i = 100004; i>=1; i--){
            cnt[i] = cnt[i+1] + fr[i]; 
        }
        int r = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int red = a[i] + a[j];
                int temp = cnt[red];
                r+=temp;
                temp = mx-red;
                r+=m[temp];
                if(a[i]==temp || a[i+1] == temp) r--;
                m[temp] = 0;
                
            }
        }


        int ans = n*(n-1)*(n-2)/6;
        ans-=r;
        if(ans<0) ans = 0;
        cout<<ans<<ln;

    }
    return 0;
}