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


int A[1000010] = {};
int DP[1000010] = {};
int S[1000010] = {};


int Longest_Subsequence(int n){
    if(n == 0) return 1;
    if(DP[n] != 0) return DP[n];

    for(int k = n; k>=0; k--){
        int l = 1, id = k;
        for(int i = k-1; i>=0; i--){
            int temp = l;
            if(A[k]>A[i]){
                temp = max(temp, Longest_Subsequence(i)+1);
            }
            if(temp>l){
                l = temp;
                id = i;
            }    
        }
        DP[k] = l;
        S[k] = id;
        if(k==0) return DP[n];
    }
}

int Calculate_Idx(int n){
    int mx = 0, idx;
    for(int i = 0; i<n; i++){
        if(DP[i]>mx) {
            mx = DP[i];
            idx = i;
        }
    }
    return idx;
}

int Print_Longest_Subsequence(int n){
    int i = Calculate_Idx(n), idx = i, l = DP[i];
    int LS[l];
    while(l>0){
        LS[l-1] = A[i];
        i=S[i];
        l--;
    }
    for(auto a : LS) cout<<a<<" ";
    cout<<ln;
    return DP[idx];
}


int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++) cin>>A[i];
    DP[0] = 1;
    Longest_Subsequence(n-1);
    /*
    for(int i = 0; i<n; i++)cout<<DP[i]<<" ";
    cout<<ln;
    for(int i = 0; i<n; i++)cout<<S[i]<<" ";
    cout<<ln;
    */
    
    int l = Print_Longest_Subsequence(n);
    cout<<l;
    return 0;
}