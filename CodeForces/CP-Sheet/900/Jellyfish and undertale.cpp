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

int main(){
    int t; cin>> t;
    while(t--){
        int a, b, n; cin>> a >> b >> n;
        ll sec = b;
        for(int i = 0; i<n; i++) {
            int xi; cin>>xi;
            if(xi <= a-1) sec+=xi;
            else sec+=(a-1);
        }
        cout<<sec<<ln;
    }
    return 0;
}

//https://codeforces.com/contest/1875/problem/A
