#include <bits/stdc++.h>
using namespace std; 
void fedors_army(int a[],int f_num, int n);

int main()
{
    int n, m, k, f_ans=0;
    cin>>n>>m>>k;
    int bi_fedor[n]={};
    long long x_i, m_players[m+1];
    for(int i = 0; i<m+1; i++){
        cin>>m_players[i];
    }
    fedors_army(bi_fedor, m_players[m], n);   
    for(int i = 0; i<m; i++){
        int bi[n]={}, j = 0, cont = 0, num;
        bool flag = true;
        x_i = m_players[i];
        for(int h = 0; h<n; h++){
            num = x_i%2;
            bi[j]=num;
            if(num!=bi_fedor[j]){
                cont++;
            }
            if(cont>k){
                flag = false;
                break;
            }
            if(x_i == 1){
                x_i = 0;
            }
            x_i/=2;
            j++;            
        }
        if(flag==true){
            f_ans++;
        }
    }
    cout<<f_ans;
    return 0;
}

void fedors_army(int a[], int f_num,int n){
    int j = 0;
    while(f_num!=1){
        a[j] = f_num%2;
        f_num/=2;
        j++;
    }
    a[j]=1;
}

// https://codeforces.com/contest/467/problem/B