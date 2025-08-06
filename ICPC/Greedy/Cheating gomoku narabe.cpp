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
    int h, w, k; cin >> h >> w >> k;
    string S[h];
    for(int i = 0; i<h; i++) cin >> S[i];

    int mnH = INT_MAX, mnV = INT_MAX;

    for(int i = 0; i<h; i++){
        int op[w+1]={};
        for(int j = 1; j<=w; j++){

            if(S[i][j-1]=='x'){
                op[j] = op[j-1]+k+1;
            }
            else if(S[i][j-1]=='.'){
                op[j] = op[j-1] + 1;
            }
            else{
                op[j] = op[j-1];
            }
        }
        for(int x = k; x<=w; x++){
            mnH = min(op[x]- op[x-k], mnH);
        }

    }

    for(int j = 0; j<w; j++){
        int op[h+1]={}; 

        for(int i = 1; i<=h; i++){

            if(S[i-1][j]=='x'){
                op[i] = op[i-1]+k+1;
            }
            else if(S[i-1][j]=='.'){
                op[i] = op[i-1] + 1;       
            }
            else{
                op[i] = op[i-1];      
            }
        }
        for(int x = k; x<=h; x++){
            mnV = min(op[x]- op[x-k], mnV);
        }
    }

    int mn = min(mnH, mnV);
    if(mn<0) mn = 0;
    else if(mn > k) mn = -1;
    cout<<mn;
    return 0;
}