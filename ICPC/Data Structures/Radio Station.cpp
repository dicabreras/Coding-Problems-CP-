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
    map<string, string>  MAP;
    string s1, s2, s;
    for(int i = 0; i<n; i++) {
        cin >> s1 >> s2;
        MAP[s2] = s1;
    }
    while(m--){
        cin >> s1 >> s2;
        s2.pop_back();
        s = MAP[s2];
        cout<<s1<<" "<<s2<<";"<<" #"<<s<<ln;
    }

    return 0;
}