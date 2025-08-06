#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, R; 
    cin>>n>>R;
    int c[n][3];
    int ans=0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<3; j++) cin>>c[i][j];
    }

    for(int x = -R; x<=R; x++){
        for(int y = -R; y<=R; y++){
            for(int h = 0; h<n; h++){
                int r = c[h][0], i = c[h][1], j = c[h][2];
                if(((x-i)*(x-i)+(y-j)*(y-j)<=r*r) && (x*x + y*y <= R*R)){                
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}