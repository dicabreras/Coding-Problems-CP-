    /*
Coded by Diego Cabrera
Codeforces username: CaSala
Problem: https://codeforces.com/problemset/problem/1582/C
*/

#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;  
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"
#define between(a, b, c) (a<=b && b<=c)

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;


bool isPalindrome(string s){
    int N = s.size();
    for(int i = 0; i<N/2; i++){
        if(s[i]!=s[N-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
/*    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    */
    
    int t; 
    cin >> t;
    while(t--){
        int n; 
        string s;
        cin >> n >> s; 
        int idx = -1; 
        for(int i = 0; i<n/2; i++){
            // Finding the first index s_i that do not satisfy the palindrome condition if it exists
            if(s[i] != s[n-i-1]){
                idx = i;
                break;
            }
        }
        if(idx>=0){
            // Delete the left character 
            int mn = 1e6, l = idx+1, r = n-idx-1, f = 0;
            char letter = s[idx];
            set<int> idxs;
            idxs.insert(idx);
            while(l<r){
                
                if(s[l]!=s[r]){
                    if(s[l] == letter){
                        idxs.insert(l);
                        l++;
                    }
                    else if(s[r] == letter){
                        idxs.insert(r);
                        r--;
                    }
                    else break;
                }
                else{
                    l++;
                    r--;
                }
            }
            string temp = ""; 
            for(int i = 0; i<n; i++){
                if(idxs.count(i)) continue;
                temp.pb(s[i]);
            }
            //verifiy if it is a palindrome
            
            if(isPalindrome(temp)){
                mn = min(mn, n - (int)temp.size());
                f = 1;
            }

            idxs.clear();
            idxs.insert(n-idx-1);
            letter = s[n-idx-1];
            l = idx;
            r = n-idx-2; // Delete the rigth character

            while(l<r){    
                if(s[l]!=s[r]){
                    if(s[l] == letter){
                        idxs.insert(l);
                        l++;
                    }
                    else if(s[r] == letter){
                        idxs.insert(r);
                        r--;
                    }
                    else break;
                }
                else{
                    l++;
                    r--;
                }
            }
            temp = "";

            for(int i = 0; i<n; i++){
                if(idxs.count(i)) continue;
                temp.pb(s[i]);
            }

            //verifiy if it is a palindrome
            if(isPalindrome(temp)){
                mn = min(mn, n - (int)temp.size());
                f = 1;
            }
            if(f){
                cout<<mn<<ln;
            }
            else cout<<-1<<ln;

        }
        else{
            cout<<0<<ln;
        }
        
    }



    return 0;
}