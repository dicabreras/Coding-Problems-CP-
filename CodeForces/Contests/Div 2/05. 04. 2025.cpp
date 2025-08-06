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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int t; cin >> t;
    while(t--){
        int n, f = 1; cin >> n;
        int a[n], b[n], posA[n+1], posB[n+1];
        for(int i = 0; i<n; i++){
            cin>> a[i];
            posA[a[i]] = i+1;
        }
        for(int i = 0; i<n; i++){
            cin >> b[i];
            posB[b[i]] = i+1;
        }
        if(n%2 == 1){
            int cnt = 0;
            for(int i = 0; i<n; i++){
                if(b[i] == a[i])cnt++;
                if(f>1){
                    f = 0;
                    break;
                }
            }
        }
        else{
            for(int i = 0; i<n; i++){
                if(b[i] == a[i]){
                    f = 0;
                    break;
                }
            }
        }
        if(f){
            
            int p1[n+1], p2[n+1];
            for(int i = 0; i<n; i++){
                p1[a[i]] = b[i];
                p2[b[i]] = a[i];
            }
            vector<pi> v;
            for(int i = 1; i<=n/2; i++){
                if(p1[i] != p2[i]){
                    f = 0;
                    break;
                }
                else{
                    //int l = pos1[i];
                    v.pb({i, posA[i]});
                    v.pb({n-i+1, posB[i]});
                    int x = a[i-1], y = b[n-i];
                    posA[x] = posA[i];
                    posA[i] = i;
                    posB[y] = posB[i];
                    posB[i] = n-i+1;
                }
            }
            if(f){
                int nn = v.size();
                cout<<nn<<ln;
                for(auto pi : v){
                    cout<<pi.ff<<" "<<pi.ss<<ln;
                }
            }
            else cout<<-1<<ln;
        }
        else cout<<-1<<ln;
        
    }
    return 0;
}