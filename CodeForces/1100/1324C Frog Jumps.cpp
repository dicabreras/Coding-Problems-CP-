#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    for (int k = 0; k<t; k++){
        vector <int> s;
        string chain;
        int ans=0;
        cin>>chain;
        s.push_back(0);
        for(int i = 0; i<chain.size(); i++){
            if(chain[i]=='R'){
                s.push_back(i+1);
            }
        }
        s.push_back(chain.size()+1);

        for(int i = 0, j = 1 ; j<s.size(); i++, j++){
            ans = max(ans, s[j]- s[i]);
        }

        cout<<ans<<"\n"; 
    }
    return 0;
}
