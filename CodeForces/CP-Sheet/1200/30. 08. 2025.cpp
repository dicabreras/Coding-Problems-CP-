/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
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
    freopen("output.txt", "w", stdout);
    #endif
    */

    int n;
    string s; 
    cin >> n >> s;
    int a[n], b[n];
    for(int i = 0, j = 0, k = 0; i<2*n; i++){
        if(s[i] == 'A'){
            a[j] = i;
            j++;
        }
        else{
            b[k] = i;
            k++;
        }
    }
    int ans = 0;
    for(int i = 0; i+1<n; i++){
    
    }

    return 0;
}
