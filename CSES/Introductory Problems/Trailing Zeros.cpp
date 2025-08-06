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
    ll n; cin>>n;
    ll ans = 0;
    while(n>0){
        ans+=(n/5);
        n/=5;
    } 
    cout<<ans;
}

//The idea behind this is that by dividing, even when the number is not a mutiple of 5,
// each time that we can divide by 5 represents a track of the 5s that are in the factorization
//this is a way of counting the number of 5s which are in a number factorization.