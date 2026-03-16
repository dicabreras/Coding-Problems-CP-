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
        int d, n; 
        cin >> n >> d;
        int a[n], b[n], aux[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
            aux[i] =a[i];
        }

        for(int i = 0; i<n; i++){
            cin >> b[i];
        }
        int days[n] = {}, sumB = b[0], j = 0;
        days[0] = a[0] - b[0]; // stores the eggs at the end of the day i
        aux[j]-=b[0];
        for(int i = 1; i<n; i++){
            sumB+=b[i];
            if(b[i]>days[i-1]){
                b[i]-=days[i-1];
                days[i] = a[i] - b[i];
            }
            else{
                days[i-1]-=b[i];
                days[i] = days[i-1] + a[i];
            }

            if(b[i]>=aux[j]){
                aux[j]  = 0;
                j++;
            }
            else{
                aux[j]-=b[i];
            }

            if(i>=d){
                days[i]-=aux[i-d];
                j++;
            }
            
            
        }
        cout<<days[n-1]<<ln;
    }

    return 0;
}