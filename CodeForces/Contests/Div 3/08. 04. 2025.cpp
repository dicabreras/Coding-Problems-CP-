/*
Coded by Diego Cabrera
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
#define yes "Yes"
#define no "No"

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
    int n;
    while(cin >> n){
        if(n==0) return 0;
        vector<vector<int>> a(n);
        vector<int> k(n, 0);
        for(int i=0; i<n; i++){
            a[i]=k;
        }

        for(int i=0; i<n; i++){
            cin>>k[i];
        }
        if(k[0] != k[n-1]) cout<<no<<ln;
        else{
            for(int i=0; i<n; i++){
                a[0][i] = k[i];
            }

            for(int i=0; i<n; i++){
                a[i][n-1] = k[i];
            }

            for(int i=0; i<n; i++){
                a[n-1][n-1-i] = k[i];
            }

            for(int i=0; i<n; i++){
                a[n-1-i][0] = k[i];
            }
            cout<<yes<<ln;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout<<a[j][i]<<" ";
                }
                cout<<ln;
            }
        }
        
        
    }
    return 0;
}