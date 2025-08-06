#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t; cin>> t;
    while(t--){
        set<char> S;
        map<char, char> mp;
        int n; cin>>n;
        string s; cin>>s;
        for(char a : s)S.insert(a);
        string r;
        for(auto& str:S){
            r.push_back(str);
            //cout<<(int)str<<endl;
        }
        int m = r.length();
        for(int i = 0, j=m-1; i<=m/2; i++, j--){
            mp[r[i]]=r[j]; 
            mp[r[j]]=r[i]; 
        }
        //cout<<r;
        string ans;

        for(char a : s){
            ans+=mp[a];
        }
        cout<<ans<<"\n";


    }
    return 0;
}
