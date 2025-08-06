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
        string s; cin>> s;
        int ones = 0, zeros = 0, pairs = 0;
        for(char c : s){
            if(c == '0') zeros++;
            else ones++;
        }
        pairs = min(ones, zeros);
        if(pairs%2 == 1) cout<<"DA\n";
        else cout<<"NET\n";    
    }    
    return 0;
}