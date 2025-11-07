#include <bits/stdc++.h>
using namespace std;

int times_num[200020], partial_sums[200020]; 

int main()
{
    int n; cin>>n;
    int a[n]; 
    set<int> b;
    int sum = 0, num;
    
    for(int i=0; i<n; i++){
        cin>>num;
        times_num[num]++;
        a[i]=num; b.insert(num);
        sum+=num;
    }

    vector<int> c;
    for(auto x : b) c.push_back(x);  
    int k = c.size();

    for(int i = 0; i<k; i++){
        sum= sum-(times_num[c[i]]*c[i]);
        partial_sums[c[i]]= sum;
    }
    for(int i = 0; i<n; i++){
        cout<<partial_sums[a[i]]<<" ";
    }
    return 0;
}
