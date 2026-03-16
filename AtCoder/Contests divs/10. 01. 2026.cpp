/*
Coded by Diego Cabrera
Codeforces username: CaSala
*/
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

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */

    int t; 
    cin >> t;
    while(t--){
        ll n, w;
        cin >> n >> w;
        ll c[n], k = 2*w, sum = 0;
        for(ll i = 0; i<n; i++){
            cin >> c[i];
            if(i%k<w){
                sum+=c[i];
            }
        }
        ll mn = 1e15, temp = sum;
        for(ll i = 0; i<w; i++){
            for(ll j = i, f = 0; j<n; j+=w, f++){
                if(f%2){
                    temp+=c[j];
                }
                else temp-=c[j];
            }
            mn = min(mn, temp);
        }
        temp = sum;
        for(ll i = w-1; i>=0; i--){
            for(ll j = i, f = 0; j<n; j+=w, f++){
                if(f%2){
                    temp+=c[j];
                }
                else temp-=c[j];
            }
            mn = min(mn, temp);
        }

        cout<<mn<<ln;
    }

    
    return 0;
}