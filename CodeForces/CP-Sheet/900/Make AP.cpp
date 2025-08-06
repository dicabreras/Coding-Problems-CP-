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
    
    int t; cin>>t;
    while(t--){
        int a, b, c; cin>> a >> b >> c;
        bool flag = false;
        int A[3] = {c-b, (c-a)/2, b-a};
        for(int i = 0; i<3; i++){
            int aa=0, bb, cc, m;
            if(i == 0){
                aa = b-A[i];
                cc = aa+2*A[i];
                m = aa/a;
                if(aa%a == 0 && m>0 && c == cc) flag = true;
            }
            else if(i == 1){
                bb = a+A[i];
                cc = bb+A[i];
                m = bb/b;
                if(bb%b == 0 && m>0 && cc == c) flag = true;
            }
            else{
                cc = b+A[i];
                aa = cc-2*A[i];
                m = cc/c;
                if(cc%c == 0 && m>0 && a == aa) flag = true;
            }
        }
        if(flag) cout<<yes<<ln;
        else cout<<no<<ln;
    
    }    
    return 0;
}