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


int A[1000010]={};
int MX = 1;


int Longest_Subsequence(int n){
    if(n==0) return 1;
    int l = 1;
    for(int i = n-1; i>=0; i--){
        if(A[n]>A[i])
        l = max(l, Longest_Subsequence(i)+1);
    }
    MX = max(l, MX);
    return l;
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++) cin>>A[i];
    for(int i = n-1; i>=0; i--){
        Longest_Subsequence(i);
    }
    cout<<MX;
    return 0;
}