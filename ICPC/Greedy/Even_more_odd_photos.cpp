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
    //ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);

   // ifstream fin("herding.in");  
   // ofstream fout("herding.out"); 
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int n; cin >> n; 
    int c, odd = 0, even = 0, g; 
    for(int i = 0; i<n; i++){
        cin >> c;
        if(c%2) odd++;
        else even++; 
    }
    while(even<odd){
        even++;
        odd-=2;
    }
    g = odd*2;
    if(even>odd) g++;
    cout<<g;
    return 0;
}