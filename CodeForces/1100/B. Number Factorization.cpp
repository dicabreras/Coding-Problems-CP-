#include <bits/stdc++.h>
using namespace std; 
vector<vector<int>> bubbleSort(vector<vector<int>> a, int n);
int main(int argc, char const *argv[])
{
    int t; 
    cin>>t;
    while(t--){
        long long n, sum=1, p_sum=0;
        int cont=50, p=0;
        vector <vector <int>> a;
        cin>>n;
        for(int i = 2, j=1; n!=1; j+=2){
            if(j!=1){
                while(n%j==0){
                    n/=j;
                    p++;
                    cout<<"n=  "<<n<<"    j = "<<j<<endl;
                }
            }
            else{
                while(n%i==0){
                    n/=i;
                    p++;
                    cout<<"n=  "<<n<<"    i = "<<i<<endl;
                }
            }
            if(p>0){
                if(j!=1){
                    a.push_back({p,j});
                    cout<<"Im here j\n";
                }
                else{
                    a.push_back({p,i});
                    cout<<"im here i\n";
                }
                if(p<cont){
                    cout<<"p min = "<<p<<endl;
                    cont=p;
                }
                p=0;
            }
        }
        a = bubbleSort(a, a.size());
        for(int i = 0; i<a.size(); i++){
            
           cout<<a[i][0]<<endl;
            /*
            sum*=a[i];
            p_sum+=(a[i]*(b[i]-cont));
            cout<<"sum already =  "<<sum<<endl;
            cout<<"p_sum already = "<<p_sum<<endl;
            */
        }
        /*
        sum*=cont;
        sum+=p_sum;
        cout<<sum<<"\n";
        */
    }
    return 0;
}

vector<vector<int>> bubbleSort(vector<vector<int>> a, int n){
    bool swapped;
    for(int i = 0; i<n-1; i++){
        swapped = false;
        for(int j = 0; j<n-i-1; j++){
            if(a[j][0]>a[j+1][0]){
                swapped = true;
                cout<<"a_j = "<<a[j][0]<<"    a_j+1 = "<<a[j+1][0]<<endl;
                swap(a[j], a[j+1]);
                cout<<"IM HEREE SWAPPING\n";
                cout<<"a_j = "<<a[j][0]<<"    a_j+1 = "<<a[j+1][0]<<endl;
            }            
        }
        if(swapped == false){
            break;
        }
    }
    return a;
}
