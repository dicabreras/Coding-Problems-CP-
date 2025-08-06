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

#define between(a, b, c) (a<=b && b<=c)   //Validate position
int drX[]={-1,1,0,0}, drY[]={0,0,-1,1};

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;


int a[1000][1000] = {};
int n, m;

void f(int y, int x){
    if(a[y][x] == -1 || a[y][x] == 1) return;
    a[y][x] = 1;
    for(int i = 0; i<4; i++){
        int h = drX[i], k = drY[i];
        if(between(0, y+k, n-1) && between(0, x+h, m-1) && a[y+k][x+h] == 0){
            f(y+k, x+h);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    */
    
    cin >> n >> m;
    string s; 
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++){
            if(s[j] == '.') a[i][j] = 0;
            else a[i][j] = -1;
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]==0){
               // cout<<"i:  "<<i<<"  j:"<<j<<ln;
                ans++;
                f(i, j);
            }
        }
    }
    cout<<ans;

    return 0;
}