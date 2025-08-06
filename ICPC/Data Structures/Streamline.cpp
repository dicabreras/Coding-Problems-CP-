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
    int n, m; cin >> n >> m;
    int a[m]; 
    for(int i = 0; i<m; i++) cin >> a[i];
    sort(a, a+m);
    priority_queue<int> q;
    for(int i = 0; i+1<m; i++){
        int x = a[i+1]-a[i];
        q.push(x);
    }
    int ans = 0;
    n--;
    while(n-- && !q.empty()) q.pop();
    while(!q.empty()){
        ans+=(q.top());
        q.pop();
    }
    cout<<ans;
    return 0;
}
