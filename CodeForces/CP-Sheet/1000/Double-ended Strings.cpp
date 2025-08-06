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
    
    int t; cin>> t; 
    while(t--){
        string a, b; cin >> a >> b;
        int l1 = a.size(), l2 = b.size(), mx = 0;
        map<char, vi> m;
        if(l1<=l2){
            for(int i = 0; i<l2; i++){
                m[b[i]].pb(i);
            }
            for(int i = 0; i<l1; i++){
                //char current = a[i]; 
                int l = m[a[i]].size();
                for(int j = 0; j<l; j++){
                    int x = m[a[i]][j], f = 1, h = x, k = i;
                    while(h<l2 && k<l1){
                        if(a[k] != b[h]){
                            f = 0;
                            mx = max(mx, h-x);
                            break;
                        }
                        h++;
                        k++;
                    }
                    if(f) mx = max(mx, h-x);
                }
                    
            }
        }
        else{
            for(int i = 0; i<l1; i++){
                m[a[i]].pb(i);
            }
            for(int i = 0; i<l2; i++){
                //char current = b[i]; 
                int l = m[b[i]].size();
                for(int j = 0; j<l; j++){
                    int x = m[b[i]][j], f=1, k = i, h = x;
                    while(h<l1 && k<l2){
                        if(a[h] != b[k]){
                            f = 0;
                            mx = max(mx, h-x);
                            break;
                        }
                        h++;
                        k++;
                    }
                    if(f) mx = max(mx, h-x);
                }
                    
            }

        }
        int ans = l1+l2-2*mx;
        cout<<ans<<ln;
    }

    return 0;
}