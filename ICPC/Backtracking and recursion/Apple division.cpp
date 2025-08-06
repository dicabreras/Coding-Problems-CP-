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

const int M = 1e9+7;
int sets[20]={}, n;
ll totalSum, a[20], mn = 1e9+7;

void minWeight(int current){
    if(current == n){
        ll sum1 = totalSum;
        for(int i = 0; i<n; i++){
            if(!sets[i])sum1-=a[i];
        }
        ll sum2 = totalSum -sum1;
        mn = min(mn, abs(sum1-sum2));
    }
    else{
        sets[current+1] = 1;
        minWeight(current+1);
        sets[current+1] = 0;
        minWeight(current+1);
    }
}

int main(){
    cin >> n; 
    for(int i = 0; i<n; i++){
        cin >> a[i];
        totalSum+=a[i];
    }
    sets[0] = 1;
    minWeight(0);
    cout<<mn;

    
    return 0;
}