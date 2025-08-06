#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

vector<char> p;
vector<bool> chosen(8, false);
int n;
string s;
set<string> S;

void solve(){
    if(p.size() == n){
        string permutation="";
        for(auto c : p) permutation.push_back(c);
        S.insert(permutation);
        p.empty();
    }
    for(int i = 0; i<n; i++){
        if(chosen[i]) continue;
        p.push_back(s[i]);
        chosen[i] = true;
        solve();
        p.pop_back();
        chosen[i]=false;

    }
    

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
 
    cin>>s;
    n = s.size();
    solve();
    cout<<S.size()<<ln;
    for(auto permutation : S)cout<<permutation<<ln;

    return 0;
}