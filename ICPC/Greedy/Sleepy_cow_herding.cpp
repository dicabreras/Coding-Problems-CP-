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

    ifstream fin("herding.in");  
    ofstream fout("herding.out"); 
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int c1, c2, c3; 
    fin >> c1 >> c2  >> c3;
    int mn, mx;
    if(c2-c1 == 1 && c3-c2 == 1){
        mn = 0;
        mx = 0;
        fout<<mn<<ln<<mx;
        fin.close();
        fout.close();
        return  0;
    }
    else if(c2-c1 == 2 || c3-c2 == 2) mn = 1;
    else mn = 2;
    mx = max(c2-c1-1, c3-c2-1);
    fout<<mn<<ln<<mx;

    fin.close();
    fout.close();
    
    return 0;
}