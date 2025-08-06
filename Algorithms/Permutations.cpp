#include <bits/stdc++.h>
using namespace std;

// This code calculates all the permutations of a given string.
// The data structures used are queues and a vector for saving the answer.
// The logic behind this is a tree.

vector<string> permutations(string s, int N){
    vector<string> ans;
    queue<string> q;
    queue<int> level;
    q.push(s);
    level.push(0);
    while(!q.empty()){
        int l = level.front();
        string a = q.front();
            for(int j = l; j<N; j++){
                char temp = a[l];
                a[l] = a[j];
                a[j] = temp;
                q.push(a);               
                level.push(l+1);  
                if(l+1==N)ans.push_back(a);
            }
            q.pop();
            level.pop();
    }
    return ans;
    
}

int main()
{
    string s;
    vector<string> ans;
    cin>>s;
    int N = s.length();
    ans = permutations(s, N);
    for(int i = 0; i<ans.size(); i++) cout<<"#"<<i+1<<" "<<ans[i]<<"\n";
    return 0;
}
