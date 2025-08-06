#include <bits/stdc++.h>
using namespace std; 

bool solve();

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        cout<<(solve()? "YES":"NO")<<"\n";
    }   
    return 0;
}

bool solve(){
    int n, k;
    cin>>n>>k;
    int tails[n];
    vector<int> first_po, last_po;
    for(int i = 0; i<n; i++){
        cin>>tails[i];
        if(tails[i]==tails[0] && first_po.size()<k){
            first_po.push_back(i);
        }
    }

    if(first_po.size()==k){
        for(int i = n-1; i>first_po[first_po.size()-1]; i--){
            if(tails[i]==tails[n-1] && last_po.size()<=k){
                last_po.push_back(i);
            }
            if(last_po.size()==k){
                return true;
            }
        }
    }
    else{
        return false;
    }
    
    if(last_po.size() < k && tails[n-1]!=tails[0]){

        return false;
    }
    else{
        return true;
    }
}