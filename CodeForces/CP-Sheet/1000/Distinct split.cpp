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
        int n;
        string s;
        cin >> n >> s; 
        int a[n], b[n];
        set<int> s1, s2;
        for(int i = 0, j = n-1; i<n; i++, j--){
            s1.insert(s[i]); s2.insert(s[j]);
            a[i] = s1.size(); 
            b[j] = s2.size();
        }
        int mx = 0; 
        for(int i = 0; i<n-1; i++){
            mx = max(mx, a[i] + b[i+1]);
        }
        cout<<mx<<ln;
    }   
    return 0;
}