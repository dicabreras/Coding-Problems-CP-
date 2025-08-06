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
        int n, m, sum = 0, zeros = 0, mn = 101; cin >> n >> m;
        vi v; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int x; cin >> x;
                if(x<0) v.pb(x);
                else if(x == 0) zeros = 1;
                else{
                    sum+=x;
                    mn = min(mn, x);
                }

            }
        }
        int f = 0;
        sort(v.begin(), v.end()); 
        if(v.size()%2==1 && zeros) f=1;
        else if(v.size()%2 == 0) f = 1;

        if(!f){
            if(-v.back()>mn) sum-=(mn*2);
            else{
                sum+=v.back();
                v.pop_back();
            }
        }
        for(auto i : v){
            sum+=(-i);
        }
        cout<<sum<<ln;
    }

    return 0;
}