#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t; cin>> t;
    while(t--){
        int n; cin>>n; 
        ll a[n];
        string triples[n];
        string s;
        for(int i = 0, j=0; i<n; i++){
            char e;
            cin>>e;
            s.push_back(e);
            if(i>2){
                string ss = s.substr(j,i);
                cout<<ss<<endl;
                j++;
            }
            
        } 
        for(string f: triples)cout<<f<<"\n";

    }
}