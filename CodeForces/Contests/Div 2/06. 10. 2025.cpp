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

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s; 
        cin >> s;
        int a[n] = {}, l = 0, r = n-1, N = s.size(), cnt = 0;
        for(int i = 0; i<N; i++){
            if(s[i] == '0'){
                a[l] = -1;
                l++;
            }
            else if(s[i] == '1'){
                a[r] = -1;
                r--;
            }
            else{
                cnt++;
            }
        }
        char ans[n];
        int f  = 0;
        for(int i = 0; i<n && a[i] == -1; i++){
            ans[i] = '-';
            l = i;
            f = 1;
        }
        for(int i = n-1; i>=0 && a[i] == -1; i--){
            ans[i] = '-';
            r = i;
            f = 1;
        }

        for(int i = l+1, j = 0; i<n && j<cnt; i++, j++){
            ans[i] = '?';
            l = i;
            f = 1;
        }
        for(int i = r-1, j = 0; i>=0 && j<cnt; i--, j++){
            ans[i] = '?';
            r = i;
            f = 1;
        }
        l++;
        while(l<r){
            ans[l] = '+';
            l++;
            f = 1;
        }
        for(auto i : ans){
            if(!f) i = '-';
            cout<<i;
        }
        cout<<ln;
        
    }

    return 0;
}
