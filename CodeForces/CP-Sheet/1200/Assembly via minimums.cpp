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
        int n; cin >> n;
        int x = n*(n-1)/2;
        int b[x], a[n];
        map<int, int> m, mm;
        for(int i = 0; i<x; i++){
            cin >> b[i];
            m[b[i]]++;
        }
        sort(b, b+x, greater<>());
        int mx = b[0], cnt = m[mx];
        int i = 2, j = 0;
        while(i*(i-1)<2*cnt) i++;
        while(j<i){
            a[j] = mx;
            j++;
        }
        m[mx] = 0;
        for(int i = 1; i<x; i++){
            if(m[b[i]]==0)continue;
            int y = b[i], current = 0;
            cnt = m[y];
            while(current<cnt){
                a[j] = y;
                current+=j;
                j++;
            }
            m[y] = 0;
        }
        for(auto ai : a) cout<<ai<<" ";
        cout<<ln;
    }
    return 0;
}