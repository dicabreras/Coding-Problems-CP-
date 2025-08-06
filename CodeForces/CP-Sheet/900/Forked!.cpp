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



int main(){
    int t; cin>>t;
    while(t--){
        int a, b , k1, k2, q1, q2; 
        cin>> a >> b >> k1 >> k2 >> q1 >> q2;
        
        int drX[] = {a, a , -a , -a, b, b, -b, -b};  //Knight's attack coming from
        int drY[] = {b, -b, -b, b, a, -a, -a, a};

        set<pair<int , int>> Sk, Sq, S; 
        int K1, K2, Q1, Q2;
        for(int i = 0; i<8; i++){
            K1 = k1 + drX[i]; 
            K2 = k2 + drY[i];
            Q1 = q1 + drX[i];
            Q2 = q2 + drY[i];
            Sk.insert(mp(K1, K2));
            Sq.insert(mp(Q1, Q2));
        }

        for(auto s : Sk) S.insert(s);
        for(auto s : Sq) S.insert(s);
        int ans = (Sk.size()+Sq.size())-S.size();
        cout<<ans<<ln;
    }
    return 0;
}
