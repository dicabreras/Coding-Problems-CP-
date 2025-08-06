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
        int n, c1, c2; cin >> n >> c1;
        c2 = c1;
        vector<pi> v(n);
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            v[i]={x+i+1, x+n-i};
        }
        /*
        for(auto p : v){
            cout<<p.ff<<"----"<<p.ss<<ln;
        }*/
        sort(v.begin(), v.end());
        
       /* 
        cout<<"#####################"<<ln;
        for(auto p : v){
            cout<<p.ff<<"----"<<p.ss<<ln;
        }*/
            
        int a[n], f = 0, ans = 0;
        map<int, int> m;
        for(int i = 0; i<n; i++){
            a[i] = min(v[i].ff, v[i].ss);
            m[v[i].ff] = 1;
        }
        sort(a, a+n);
        int i = 0;
        while(c1-a[i]>=0 && i<n){
            if(m.count(a[i])) f=1;
            c1-=a[i];
            i++;
            ans++;
        }
        if(!f){
            int mn = INT_MAX, k;
            ans = 0;
            for(int j = 0; j<i; j++){
                mn = min(v[j].ff, mn);
                if(mn == v[j].ff) k = j;
            }
            if(c2-v[k].ff>=0){
                ans++;
                c2-=v[k].ff;
                i=0;
                while(c2-a[i]>=0 && i<n){
                    if(i == k){
                        i++;
                        continue;
                    }
                    c2-=a[i];
                    ans++;
                    i++;
                }
            }
        }
        cout<<ans<<ln;
    }
    return 0;
}