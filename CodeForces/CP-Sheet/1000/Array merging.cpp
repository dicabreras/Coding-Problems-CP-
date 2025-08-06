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
        int n; cin >> n;
        int a[400010] = {}, b[400010] = {};
        int prev, cnt = 1; cin>> prev;
        set<int> s;
        s.insert(prev);

        for(int i = 1; i<n; i++){
            int current; cin >> current;
            if(current == prev) cnt++;
            else{
                a[prev] = max(a[prev], cnt);
                cnt = 1;
            }
            prev = current;
            s.insert(current);
        }
        a[prev] = max(a[prev], cnt);
        cnt = 1;
        cin>> prev;
        s.insert(prev);

        for(int i = 1; i<n; i++){
            int current; cin >> current;
            if(current == prev) cnt++;
            else{
                b[prev] = max(b[prev], cnt);
                cnt = 1;
            }
            prev = current;
            s.insert(current);
        }
        b[prev] = max(b[prev], cnt);
        int ans = 0;

        for(auto i : s){
            ans = max(ans, a[i]+b[i]);
        }

        cout<<ans<<ln;           
    }   
    return 0;
}