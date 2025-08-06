#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, m_idx; cin>>n>>m;
    int array_a[n];
    set <int> b;  // sets in c++
    for(int i = 0; i<n; i++){
        cin>>array_a[i];
        b.insert(array_a[i]);
    }
    
    int m_array[b.size()], x_nums = b.size();
    if(x_nums!=n){
  //  cout<<x_nums<<endl;

    for(int i = n-1, j = 0; j<x_nums; i--){
         auto finder = b.find(array_a[i]);
         if(finder != b.end()){
            m_array[j]= i+1;
            b.erase(array_a[i]);
            j++;
         }    
        // cout<<"i:  "<<i<< "  -  j: "<<j<<endl; 
    }
/*
    for(int num : m_array){
        cout<<num<<" ";
    }
    cout<<"\n";
*/  
    for(int i = 0; i<m; i++){
        int ans;
        cin>>m_idx;
        for(int j = x_nums-1; j<x_nums; j--){
         //   cout<<"index:  "<<m_array[j]<<endl;
            if(m_idx<=m_array[j]){
                ans = j+1;
                break;
            }
        }
      //  cout<<"ans =  "<<ans<<"\n";
      cout<<ans<<"\n";
    }
    }

    else{
        for(int i = 0; i<m; i++){
            cin>>m_idx;
            cout<<n-m_idx+1<<"\n";
        }
    }
    return 0;
}
