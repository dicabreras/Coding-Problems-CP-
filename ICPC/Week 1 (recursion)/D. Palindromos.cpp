#include <bits/stdc++.h>
using namespace std;
bool palindrome(vector<char> a, int i, int j);
int main(int argc, char const *argv[]){
    string s;
    vector<char> a;
    cin>>s;
    for(int i = 0; i<s.length(); i++){
        a.push_back(s[i]);
    }
    bool flag = palindrome(a, 0, a.size()-1);
    if(flag)cout<<"yes";
    else cout<<"no";
    return 0;
}

bool palindrome(vector<char> a, int i, int j){
    if(a[i]!=a[j]) return false;
    if(i+2 == j || i+1 == j)return true;
    return palindrome(a, i+1, j-1);
}
