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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        int a[n][n] = {};
        for(int i = 0; i<n; i++){
            cin >> s;
            for(int j = 0; j<n; j++){
                if(s[j] =='1') a[i][j] = 1;
            }
        }
        int visited[n][n] = {}, total = n*n, cnt = 0, ans = 0;
        for(int i = 0; i<n && cnt<total; i++){
            for(int j = 0; j<n && cnt<total; j++){
                int ones = 0, zeroes = 0, y = i, x = j;
                for(int k = 0; k<4 && cnt<total; k++){
                    if(!visited[y][x]){
                        cnt++;
                        visited[y][x] = 1;
                        if(a[y][x]) ones++;
                        else zeroes++;
                        int temp = x;
                        x = n-1-y;
                        y = temp;
                        /*
                        if(k == 0){
                            temp = x;
                            x = n-1-y;
                            y = temp;
                        }
                        else if(k == 1){
                            temp = x;
                            x = n-1-y;
                            y = temp;
                        }
                        */
                        

                    }
                }
                ans+=min(zeroes, ones);
            }
        }
        cout<<ans<<ln;
    }
    return 0;
}