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

int dp[101][10007];
int total_sum[101]={}; 

// The dp minimize the result of 2*ai*aj + 2*bi*bj

int f(int* a, int* b, int i, int sum){
    if(i == -1) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int ans = INT_MAX;
    // doesnt make the swap
    ans = min(ans, f(a, b, i-1, sum+a[i]) + 2*a[i]*sum + 2*b[i]*(total_sum[i+1]-sum)); 
    // make the swap
    ans = min(ans, f(a, b, i-1, sum+b[i]) + 2*b[i]*sum + 2*a[i]*(total_sum[i+1]-sum));
    dp[i][sum] = ans;
    // We can caracterize the dp's states by saving the sum's values of array A/B;
    // f(a, b, i-1, sum + a[i]) sums the result of 2*ai*aj + 2*bi*bj until i-1
    return ans;
}

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
        int a[n], b[n];
        for(int i = 0; i<n; i++) cin >> a[i];
        for(int i = 0; i<n; i++) cin >> b[i];
        memset(dp, -1, sizeof(dp));
        
        for(int i = n-1; i>=0; i--){
            total_sum[i] = total_sum[i+1] + a[i] + b[i];
        }
        int sumA = 0, sumB = 0;
        for(int i = 0; i<n; i++){
            sumA+=a[i]*a[i]*(n-1);
            sumB+=b[i]*b[i]*(n-1);
        }
        int s = sumA + sumB + f(a, b, n-1, 0);
        cout<<s<<ln;
        memset(dp, -1, sizeof(dp));
        memset(total_sum, 0, sizeof(total_sum));
    }
    return 0;
}