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
 

 
int main(){
    ll n; cin>>n;
    if((n*(n+1))/2 % 2 == 0){
        cout<<yes<<ln;
        ll a[n+1]={};
        ll x = ((n*(n+1))/2)/2;
        set<ll> S1, S2;
        for(ll i = n; i>0; i--){
            if(x-i>=0) {
                x-=i;
                a[i]=1;
                S1.insert(i);
            }
        }
        cout<<S1.size()<<ln;
        for(auto j : S1) cout<<j<<" ";
        cout<<ln;
            
        for(int i = 1; i<=n; i++){
            if(a[i]==0) S2.insert(i);
        }

        cout<<S2.size()<<ln;
        for(auto j : S2) cout<<j<<" ";
        cout<<ln;
    }
    else cout<<no;

    return 0;
}