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

const int M = 1e9+7;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        
        int n, k; cin>> n >> k; 
        int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        sort(a, a+n);
        int remainders[2*k]={}, pfxsum_r[2*k]={};
        for(int i = 0; i<n; i++){
            remainders[a[i]%(2*k)]++;
            pfxsum_r[a[i]%(2*k)]++;
        }
        
        for(int i = a[0]%(2*k); i<a[0]+2*k; i++){
            int current = i%(2*k), prev0, prev1;
            if(current>0) prev0=current-1;
            else prev0 = 2*k-1;
            if(current-k>=0) prev1 = current-k;
            else prev1 = (2*k) + (current-k);
            pfxsum_r[current]+=pfxsum_r[prev0];
            pfxsum_r[current]-=remainders[prev1];
        }
        bool flag = false;  
        int s = a[n-1];
        for(int i = s; i<s+k; i++){
            if(pfxsum_r[i%(2*k)]==n) {
                flag = true;
                cout<<a[n-1] + (i-a[n-1])<<ln;
                break;
            } 
        }
        if(!flag) cout<<-1<<ln;
    }
    return 0;
}