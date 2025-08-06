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
double c;
bool f(double x){
    double y = x*x + sqrt(x);
    return y <= c; 
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    cin >> c;
    double l = 0, r = 1e6;
    for(int i = 0; i<100; i++){
        double m = l + (r-l)/2;
        if(f(m)){
            l = m;
        }
        else r = m;
    } 
    cout<<setprecision(20)<<l;

    return 0;
}