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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    ll n, m; cin >> n >> m;
    ll a[n], b[m], mn = INT_MAX, mx1 = 0, mx2 = 0; 
    ll sum, sum1 = 0, sum2 = 0; 
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sum1+=a[i];
    }
    sort(a, a+n);
    mx1 = a[n-1], mx2 = a[n-2];
    sum1*=m;
    for(int i = 0; i<m; i++){
        cin >> b[i];
        mn = min(mn, b[i]);
        sum2+=b[i];
    }
    if(mx1>mn) cout<<-1;
    else{
        if(mx1 == mn){
            sum=sum1+sum2-mx1*m;
        }
        else{
            sum = sum1+sum2-mx1*(m-1)-mx2;
        }
        cout<<sum;
    }
    
    return 0;
}