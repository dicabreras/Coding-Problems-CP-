#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int, int> vi;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

//https://codeforces.com/problemset/problem/1883/B

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>> n >> k;
        string abc = "abcdefghijklmnopqrstuvwxyz";
        map<char, int> m;
        for(char a : abc) m[a]=0;  //initializing keys and values
        string s; cin>>s;
        int count = 0;
        for(auto c : s)m[c]++;
        
        for(auto c : s){
            if(m[c]%2!=0){
                count++;    
                m[c]--;
            }
            if(count>k+1)break;
        }

        if(count>k+1)cout<<no<<ln;
        else cout<<yes<<ln; 
    }
    return 0;
}
