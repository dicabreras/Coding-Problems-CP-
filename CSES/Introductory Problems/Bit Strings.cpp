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
    int n; cin>> n;
    int ans=1;
    for(int i = 0; i<n; i++){
        ans*=2;
        ans%=M;
    }
    cout<<ans;
    return 0;
}