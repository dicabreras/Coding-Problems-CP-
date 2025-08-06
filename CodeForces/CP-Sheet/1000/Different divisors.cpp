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
int zahlen[20020];
vector<int> primes;

void generate_n_primes(){
    for(int i = 1; i<=20020; i++) zahlen[i-1] = i;
    for(int i = 2; i<=2020; i++){
        int x = i+i;
        for(int j = x; j<=20020; j+=i){
            zahlen[j-1] = 0;
        }
    }
    for(auto p : zahlen){
        if(p == 1) continue;
        if(p>0) primes.pb(p);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; cin>> t;
    generate_n_primes(); 
    while(t--){
        int d; cin >> d;
        int x = 1, i = 0, cnt = 1;
        while(true){
            int p = primes[i];
            if(abs(p-x)>=d){
                x*=p;
                cnt++;
            }
            else i++;
            if(cnt == 3) break;
        }
        cout<<x<<ln;
    }

    return 0;
}