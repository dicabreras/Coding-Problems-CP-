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
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        map<int, int> m;
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            if(!m.count(x)) m[x] = 1;
            else m[x]++;
        }
        priority_queue<int> q;
        for(auto i : m){
            q.push(i.ss);
        }
        int mx = q.top();
        q.pop();

        while(!q.empty()){
            int temp = q.top();
            mx-=temp;
            if(mx<=0){
                mx = -mx;
            }
            q.pop();
        }
        cout<<mx<<ln;
    }

    return 0;
}