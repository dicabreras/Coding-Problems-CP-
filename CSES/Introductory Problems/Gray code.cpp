#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

const int M = 1e9;

int main(){
    int n; cin>>n;
    //int sz = pow(2, n);
    vector<string> S;
    S.pb("0"); S.pb("1");
 //   for(auto s : S) cout<<s<<ln;
    for(int i = 2; i<=n; i++){
        int z = pow(2,i);
        for(int j = 0; j<z/2; j++){
      //      cout<<"string in process:   "<<S[j]<<ln;
            S[j].push_back('0');
        //    cout<<"new string:   "<<S[j]<<ln;
        }
        for(int j = z/2-1; j>=0; j--){
            string s = S[j];
//            cout<<"string in process:   "<<s<<ln;
            s.pop_back(); 
  //          cout<<"string in deleted:   "<<s<<ln;
            s.push_back('1');
    //        cout<<"new  string:   "<<s<<ln;
            S.pb(s);
        }
    }
    for(auto s : S) cout<<s<<ln;

    return 0;
}