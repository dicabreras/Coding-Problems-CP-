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

const int M = 1e9+7;


int A[1000010] = {};
int DP[1000010] = {};
int S[1000010] = {};

int RESULTS[200][10];
int MEDIANS[200];


ll random(ll a, ll b){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dristrib(a,b);
    ll random_value = dristrib(gen);
    return random_value;
}

void Generate_Random_Values(int n){
    for(ll i = 0; i<n; i++){
        A[i] =random(0,100);
    }
    //cout<<"The random array generated of size: "<<n<<"  form 1 to 100 is:\n";
    //for(int i = 0; i<n; i++) cout<<A[i]<<" ";
    //cout<<ln;
}


int Longest_Subsequence(int n){
    if(n == 0) return 1;
    if(DP[n] != 0) return DP[n];

    for(int k = n; k>=0; k--){
        int l = 1, id = k;
        for(int i = k-1; i>=0; i--){
            int temp = l;
            if(A[k]>A[i]){
                temp = max(temp, Longest_Subsequence(i)+1);
            }
            if(temp>l){
                l = temp;
                id = i;
            }
        }
        DP[k] = l;
        S[k] = id;
        if(k==0) return DP[n];
    }
    return 0;
}

int Calculate_Idx(int n){
    int mx = 0, idx;
    for(int i = 0; i<n; i++){
        if(DP[i]>mx) {
            mx = DP[i];
            idx = i;
        }
    }
    return idx;
}

int Print_Longest_Subsequence(int n){
    int i = Calculate_Idx(n), idx = i, l = DP[i];
    int LS[l];
    while(l>0){
        LS[l-1] = A[i];
        i=S[i];
        l--;
    }
    for(auto a : LS) cout<<a<<" ";
    cout<<ln;
    return DP[idx];
}

int findMedian(int i){
    sort(RESULTS[i],RESULTS[i]+10);
    return (RESULTS[i][5] + RESULTS[i][6])/2;
}

int main(){
    ofstream myfile;
    myfile.open("results.txt");
    myfile << "N, L\n";
    int t = 200;
    for(int i=1; i<=t; i++){
        int n=i;
        cout << i << "\n";
        for(int j=0; j<10; j++){
            Generate_Random_Values(n);
            DP[0] = 1;
            Longest_Subsequence(n-1);
            int idx = Calculate_Idx(n);
            int l = DP[idx];
            RESULTS[i][j] = l;
        }
        MEDIANS[i] = findMedian(i);
        myfile << n << " " << MEDIANS[i] << "\n";
        cout << MEDIANS[i];
    }

}