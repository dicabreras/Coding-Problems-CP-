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

bool f(int *c, int *t, int r, int n, int m)
{
    int h = 0, f = 0;
    for(int i = 0; i<m && h<n; i++){
        for(int j = h; j<n; j++){
          //  int x = t[i], y = c[j];
            h = j;
            if(abs(t[i]-c[j])>r) break;
            if(h+1==n) f = 1;
        }
    }
    if(f) return true;
    return false;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int n, m ; cin >> n >> m;
    int c[n], t[m];
    set<int> S;
    for(int i = 0; i<n; i++) cin >> c[i];
    for(int i = 0; i<m; i++){
        cin >> t[i];
        S.insert(t[i]);
    }
    int cc[n], j = 0;
    for(int i = 0; i<n; i++, j++){
        if(S.count(c[i])){
            j--;
            continue;
        }
        cc[j] = c[i];
    }

    sort(cc, cc+j);
    sort(t, t+m);     
    int l = 0, r = 2*1e9+7;
   // int l = 0, r = 20;
    while(l+1<r && j>0){
        int mid = l + (r-l)/2;
        if(f(cc, t, mid, j, m)) r = mid;
        else l = mid;
    }
    if(j == 0){
        cout<<0<<ln;
    }
    else cout<<r;
    
    return 0;
}