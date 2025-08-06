#include <bits/stdc++.h>
using namespace std; 

#define between(a, b, c) (a<=b && b<=c)  
int drX[] = {-1, 0, 1, 0}; //axis x means moving through the columns, which in a
                        // matrix represents the index j  
int drY[] = {0, 1, 0, -1}; //axis y means moving through the rows, which in a
                        // matrix represents the index i  

int main(){
    int t; cin>>t;
    while(t--){       
        int n, m; cin>>n>>m;
        int a[n][m];
        int no_greater[n][m]={};
        memset(no_greater, 0, sizeof(no_greater));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++)cin>>a[i][j];
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(no_greater[i][j]==-1)continue;
                bool flag = true;
                int mx = 0;
                for(int k = 0; k<4; k++){
                    if(between(0, j+drX[k], m-1) && between(0, i+drY[k], n-1)){
                        if(a[i+drY[k]][j+drX[k]]>=a[i][j]) flag = false;  
                        else{
                            no_greater[i+drY[k]][j+drX[k]] = -1;
                            if(a[i+drY[k]][j+drX[k]]>mx) mx = a[i+drY[k]][j+drX[k]];
                        }  
                    }
                }  
                if(flag) a[i][j]=mx;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}
