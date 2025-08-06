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
 
const int M = 1e9+7;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin>>t;
    while(t--){
        ll n, p; cin>> n >> p;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        ll a[n], b[n];
        for(int i = 0; i<n; i++) cin>> a[i];
        for(int i = 0; i<n; i++) cin>> b[i];
        for(int i = 0; i<n; i++){
            pi x = mp(b[i], a[i]);
            q.push(x);
        }
        ll ans=0;
        ans+=p;
        n--;
        while(n>0){
            pi temp = q.top();
            q.pop();
            ll cost = temp.ff, num = temp.ss;
            if(cost>p){
                ans+=(n*p);
                num=n;
                break;
            }
            if(n>num) ans+=(cost*num);
            else ans+=(n*cost);
            n-=num;
        }
        cout<<ans<<ln;
             
    }   
    return 0;
}