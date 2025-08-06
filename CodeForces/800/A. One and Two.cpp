#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n, num; 
        cin>>n;
        vector <int> a;
        for(int i = 0; i<n; i++){
            cin>>num;
            if (num == 2){
                a.push_back(i+1);
            }
        }
        if(a.size()%2 ==0){
            if(a.size()/2 == 0){
                cout<<"1\n";
            }
            else{
            cout<<a[(a.size()/2)-1]<<"\n";
            }
        }
        else{
            cout<<"-1\n";
        }
    }   
    return 0;
}
