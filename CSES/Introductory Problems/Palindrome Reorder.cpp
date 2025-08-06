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

const int M = 1e9;

int main(){
    string s; cin>> s;
    int a[26]={};
    int count = 0;
    for(auto c : s)a[(int)c - 65]++;
    for(auto i : a){
        if(i%2==1) count++;
        if(count > 1) {
            cout<<"NO SOLUTION\n";
            break;
        }
    }
    if(count<=1){
        int mid = s.size()/2;
        char S[s.size()];
        int l = 0, r = s.size()-1;
        for(int i = 0; i<26; i++){
            if(a[i]%2==1){
                S[mid] = (char) (i+65);
                a[i]--;
            }
            for(int k = 0; k<a[i]/2; k++){
                S[l] = char(i+65); 
                S[r] = char(i+65);
                l++;
                r--;
            }
        }
        for(auto c : S) cout<<c;
    }
    
    return 0;
}