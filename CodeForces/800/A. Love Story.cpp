#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S = "codeforces";
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cont = 0;
        for(int i = 0; i<10; i++){
            if(s[i]!= S[i]) cont++;
        }
        cout<<cont<<"\n";
    }
    return 0;
}

