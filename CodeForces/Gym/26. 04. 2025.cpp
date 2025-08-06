/*
Coded by Diego Cabrera
*/
#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;  
typedef vector<ll> vi;
 
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
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    ll n;
    while(cin >> n){
        if(!n) return 0;
        ll a, b, d; cin >> a >> b >> d;
        map<int, vi> x, y;
        while(n--){
            ll xi, yi; cin >> xi >> yi;
            x[xi].pb(yi);
            y[yi].pb(xi);
        }
        /*
        for(auto m : x){
            sort(m.ss.rbegin(), m.ss.rend());
        }
        cout<<"maps"<<ln;
        for(auto m : x){
            for(auto i : m.ss) cout<< i << " ";
            cout<<ln;
        }*/
        
        for(auto m : y) sort(m.ss.begin(), m.ss.end());
        ll X = 1, Y = 0;
        while(d>0){
            if(X!=0){
                if(y.count(b)){
                    ll nn = y[b].size(), dd = 0;
                    vi temp = y[b];
                  //  cout<<"mapss"<<ln;
                    sort(temp.begin(), temp.end());
                   // for(auto i : temp) cout<<i<<" ";
                    //cout<<ln;
                    if(X==1){
                        for(ll i = 0; i<nn; i++){
                            if(y[b][i]>a){
                                dd = abs( y[b][i]-1-a);
                                break;
                            }
                        }
                    }
                    else{
                        for(ll i = nn-1; i>=0; i--){
                            ll te = y[b][i];
                            if(y[b][i]<a){
                                dd = abs(y[b][i]+1-a);
                                break;
                            }
                        }
                    }
                    if(dd>d)dd = d;
                    if(dd>0){
                        d-=dd;
                        if(X==1){
                            a+=dd;
                        }
                        else{
                            a-=dd;
                        }
                    }
                    else{
                        if(X==1){
                            a+=d;
                        }
                        else{
                            a-=d;
                        }
                        d = 0;
                    }
                    if(X==1) Y = 1;
                    else Y = -1;
                    X=0;
                }
                else{
                    if(X == 1){
                        a+=d;
                    }
                    else{
                        a-=d;
                    }
                    d = 0;
                }
            }
            else{ /////////////////////////////////////////////////////////////
                if(x.count(a)){
                    ll nn = x[a].size(), dd = 0;
                    vi temp = x[a];
                   // cout<<"mapss"<<ln;
                    sort(temp.begin(), temp.end());
                   // for(auto i : temp) cout<<i<<" ";
                   // cout<<ln;
                    if(Y==1){
                        for(ll i = 0; i<nn; i++){
                            if(x[a][i]>b){
                                dd = abs(x[a][i]-1-b);
                                break;
                            }
                        }
                    }
                    else{
                        for(ll i = nn-1; i>=0; i--){
                            if(x[a][i]<b){
                                dd = abs(x[a][i]+1-b);
                                break;
                            }
                        }
                    }
                    if(dd>d)dd = d;
                    if(dd>0){
                        d-=dd;
                        if(Y==1){
                            b+=dd;
                        }
                        else{
                            b-=dd;
                        }
                    }
                    else{
                        if(Y==1){
                            b+=d;
                        }
                        else{
                            b-=d;
                        }
                        d = 0;
                    }
                    if(Y == 1) X = -1;
                    else X = 1;
                    Y=0;
                }
                else{
                    if(Y==1){
                        b+=d;
                    }
                    else{
                        b-=d;
                    }
                    d = 0;
                }
            }
            
        }
        cout<<a<<" "<<b<<ln;
    }
    return 0;
}