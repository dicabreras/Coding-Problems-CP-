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
int dp[31];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int t; cin >> t;
    int x = 1;
    dp[0]=1;
    for(int i = 1; i<31; i++){
        x*=2;
        dp[i] = x;
    }
    while(t--){
        int l, r; cin >> l >> r;
        // Finding the most significant bit that differs form l & r;
        int j1=0, j2 = 0, l_aux = l, r_aux = r, a[3], sum=0;
        while(true){
            while(l_aux>=dp[j1]) j1++;
            while(r_aux>=dp[j2]) j2++;

            sum+=dp[j2-1];
            if(j2>j1) break;
            else{
                l_aux-=dp[j1-1];
                r_aux-=dp[j2-1];
                j1 = 0; 
                j2 = 0;
            }

        }
        a[0] = sum;
        a[1] = a[0]-1;
        if(a[1]-1<l) a[2]=a[0]+1;
        else a[2] = a[1] -1;
        for(auto i : a) cout<<i<<" ";
        cout<<ln;     
    }
    return 0;
}