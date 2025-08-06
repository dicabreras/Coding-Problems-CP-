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

    ifstream fin("sleepy.in");  
    ofstream fout("sleepy.out"); 
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int n; fin>> n;
    int a[n];
    for(int i = 0; i<n; i++)fin >> a[i];
    int mx = 0;
    for(int  i = 0; i+1<n; i++){
        if(a[i]>a[i+1]) mx = max(i+1, mx);
    }
    fout<<mx;
    fin.close();
    fout.close();

    return 0;
}