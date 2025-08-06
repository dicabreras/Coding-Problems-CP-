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

ll m, n;
ll a[1007][3];
ll p[4];

bool f(ll x){
    ll sum = 0, t, z, y, r, current;
    for(int i = 0; i<n; i++){
        t = a[i][0]; z = a[i][1]; y = a[i][2];
        r = x%(t*z+y);
        if(r>t*z)r = t*z;
        current =(x/(t*z+y)); 
        current*=z;
        current+=r/t;
        sum+=current;
        p[i] = current;
    }
    return sum >= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    cin>> m >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++){
            cin>>a[i][j];
        }
    }
    ll l = 0, r = 8;
    while(l+1<r){
        ll x = l + (r-l)/2;
        if(f(x)) r = x;
        else l = x;
    }
    cout<<r<<ln;
    for(int i = 0; i<n; i++) cout<< p[i] <<" ";
    
    return 0;
}
