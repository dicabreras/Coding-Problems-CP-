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
    
    int t; cin>> t; 
    while(t--){
        int a, b; cin >> a >> b;
        int mn = 1e9+7, aux = a, ans, f = 0;
        if(b==1){
            b++;
            f++;
        }

        while(true){
            ans = f;
            while(aux>0){
                aux/=b;
                ans++;
            }
            if(ans>mn) break;
            mn = ans;
            f++;
            b++;
            aux = a;
        }
        cout<<mn<<ln;
    }

    return 0;
}