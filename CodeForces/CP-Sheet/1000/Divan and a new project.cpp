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
    
    int t; cin>> t; 
    while(t--){
        int n; cin >> n; 
        n++;
        ll a[n], b[n]; 
        a[0] = 0; b[0] = 0;
        for(int i = 1; i<n; i++){
            cin >> a[i];
            b[i]=a[i];
        }
        sort(b, b+n);

        map<ll, queue<ll>> m;
        n--;

        ll k = n/2;
        ll ans = 0;
        //if(n%2==1) k++;
        m[0].push(0);

        for(ll i = -k, j = 1, h = k + (n%2==1); i<0; i++, j++, h--){
            m[b[j]].push(h);
            j++;
            m[b[j]].push(i);

            ans+=(abs(i)*2*b[j] + abs(h)*2*b[j-1]);
        }
        if(n%2==1){
            m[b[n]].push(1);
            ans+=(2*b[n]);
        }
        cout<<ans<<ln;

        for(auto i : a){
            cout<<m[i].front()<<" ";
            m[i].pop();
        }
        cout<<ln;       
        
    }

    return 0;
}