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
        int a[n][2], siz = 0;
        map<pi, int> m;
        string s = "";
        vi v, b;
        set<int> u;
        for(int i = 0; i<n; i++){
            int l, r; cin >> l >> r;
            pi p = {l, r};
            a[i][0] = l;
            a[i][1] = r;
            if(!m.count(p)){
                m[p] = 1;
            }
            else m[p]++;
            if(l == r){
                u.insert(l);
                siz = max(siz, l);
            }
        }

        for(auto i : u) v.pb(i);

        if(!v.empty()){
        sort(v.begin(), v.end());
        siz++;
        b.resize(siz);
        
        int f = 1;

        for(int i = 0; i+1<(int)v.size(); i++){
           // int x = v[i], y = v[i+1];
            if(v[i]+1 == v[i+1]){
                b[v[i]] = f;
                b[v[i+1]] = f;
            }
            else{
                f++;
                b[v[i+1]] = 0;
            }
        }
        }

        for(int i = 0; i<n; i++){
            int l = a[i][0], r = a[i][1];
            if(l == r){
                if(m[{l, r}]>1)s.pb('0');
                else s.pb('1');
            }
            else{
                if(r<siz){
                   // int x = b[l], y=b[r];
                    if(b[l] == b[r] && b[l]>0) s.pb('0');
                    else s.pb('1');
                }
                else s.pb('1');
            }
        }

        cout<<s<<ln;

        
    }

    return 0;
}