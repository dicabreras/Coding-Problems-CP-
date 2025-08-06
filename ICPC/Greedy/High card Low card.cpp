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

    ifstream fin("cardgame.in");  
    ofstream fout("cardgame.out"); 
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    int n; fin >> n;
    vi v1, v2;
    int a[2*n+1]={}, mn[2*n+1] = {}, mx[2*n+1] = {};
    for(int i = 0; i<n; i++){
        int x; fin >> x;
        if(i<n/2) mx[x] = 1;
        else mn[x] = 1;
        a[x] = 1;
        //v1.pb(x);
    }
    for(int i = 1; i<=2*n; i++){
        if(!a[i])v2.pb(i);
    }

    sort(v2.begin(), v2.end());
   
    for(int i = n-1; i>=n/2; i--){
        mx[v2[i]] = -1;
    }
    for(int i = 0; i<n/2; i++){
        mn[v2[i]] = -1;
    }
    int onesMx = 0, onesMn = 0;
    for(int i = 1; i<=2*n; i++){
        if(mx[i]==1) onesMx++;
        if(mx[i]==-1 && onesMx>0)onesMx--;
    }

    for(int i = 1; i<=2*n; i++){
        if(mn[i]==-1) onesMn++;
        if(mn[i]==1 && onesMn>0)onesMn--;
    }
    fout<<n-onesMx-onesMn;
    
 
    fin.close();
    fout.close();

    return 0;
}