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

// BitMasking problem

ll A[20];
int n;
int s[20];
ll sumT;
ll mn = M;

void solve(int size){
   if(size == n){
      ll sum1 = sumT;
      for(int i = 0; i<n; i++){
         if(s[i] == 0) sum1-=A[i]; 
      }
      ll sum2 = sumT-sum1;
      if(abs(sum1 - sum2) < mn) mn = abs(sum1-sum2);
   }
   else{
      s[size] = 1;
      solve(size+1);
      s[size] = 0;
      solve(size+1);
   }
}

int main(){

    #if LOCAL
    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
    #endif
    cin>>n;
    for(int i = 0; i<n; i++){
      cin>>A[i];
      sumT+=A[i];
    }
    solve(0);
    cout<<mn;
  
    return 0;
}