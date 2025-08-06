#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, n; //length
    cin>>t;
    for(int x = 0; x<t; x++){
        cin>>n;
        int permutation[n];
        for(int i = 0; i<n; i++){ // Filling the array
            cin>>permutation[i];
        }

        int i_num, j_num, k_num, i_index=1, j_index, k_index;
        bool check = false;

        i_num = permutation[0];
        for (int j = 1; j<n; j++){
            j_num = permutation[j];
          //  cout<<"j value:  "<<"   j-->  "<<j<<"\n";
            if(j_num<i_num){
                i_num = j_num;
                i_index = j+1;
            }
            else{
            //    cout<<"ich bin hier"<<"   j-->  "<<j<<"\n";
                j_index=j+1;
                for(int k = j+1; k<n; k++){
                    k_num = permutation[k];
                    if(k_num<j_num){
                        k_index = k+1;
                        check = true;
                        break;
                    }
                }
                if(check == true){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        if (check == true){
          //  cout<<"i:  "<<i_num<<"    j:  "<<j_num<<"    k:  "<<k_num<<"\n";
           // cout<<"i index:  "<<i_index<<"    j index:  "<<j_index<<"    k index:  "<<k_index<<"\n";
           cout<<"YES"<<"\n"<<i_index<<" "<<j_index<<" "<<k_index<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }       
    }
    return 0;
}
