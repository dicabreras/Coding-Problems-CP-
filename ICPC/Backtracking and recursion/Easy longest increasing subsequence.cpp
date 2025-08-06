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

int dp[11]={}; 

int longestIncreasingSubsequence(int* a, int n){
    if(dp[n]>0) return dp[n];

    int l = 1; 
    for(int i = n-1; i>=0; i--){
        if(a[n]>a[i]){
            l = max(l, longestIncreasingSubsequence(a, i) + 1);
        }
    }
    dp[n] = l;
    return dp[n];

}

int main(){
    dp[0] = 1;
    int n; cin >> n;
    int a[n], mx = 0;
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = n-1; i>=0; i--){
        longestIncreasingSubsequence(a, i);
    } 
    for(auto i : dp) mx = max(mx, i);
    cout<<mx;
    return 0;
}