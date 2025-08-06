#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s; cin>>s;
    int n = s.length();
    queue <string> q_suffix;
    queue <int> a, b;
    int ans = 0;
    for(int i = 0; i<n; i++){
        q_suffix.push(s.substr(0));
    }
    
    return 0;
}
