#include <bits/stdc++.h>

using namespace std; 
// SOLUTION FROM TUTORIAL :(
bool solve();
int main()
{
    int t;  
    cin>>t;
    while(t--){
        cout<<(solve()? "YES":"NO")<<"\n";
    }
    return 0;
}

bool solve(){
    int array_length;
    cin>>array_length;
    vector<int> array_unsorted(array_length), array_sorted(array_length);
    for(int i = 0; i<array_length; i++){
        cin>>array_unsorted[i];
        array_sorted[i] = array_unsorted[i];
    }
    sort(array_sorted.begin(), array_sorted.end());

    for(int i = 0; i<array_length; i++){
        if(array_unsorted[i]%2 != array_sorted[i]%2){
            return false;
        }
    }
    return true;
}



/*  FORCE BRUTE SOLUTION - DOES NOT PASS IN SOME CASES BECAUSE OF THE TIME LIMIT (MY SOLUTION)
int main()
{
    int t, array_length; 
    cin>>t;
    for (int i = 0; i<t; i++){
        cin>>array_length;
        long long array_int[array_length], num;
        vector<int> idx_even, idx_odd;
        bool flag = true;
        for(int j = 0; j<array_length; j++){
            cin>>num;
            array_int[j]=num;
            if(num%2==0){
                idx_even.push_back(j);             
            }
            else{
                idx_odd.push_back(j);
            }
        }
        for(int h = 0; h<idx_even.size();h++){
            for(int e_0 = idx_even.size()-2, e_1 = idx_even.size()-1; 0<=e_0; e_0--, e_1--){
                int a_i = idx_even[e_0], a_j = idx_even[e_1];
                if(array_int[a_j]<array_int[a_i]){
                    int temp = array_int[a_i];
                    array_int[a_i] = array_int[a_j];
                    array_int[a_j] = temp;
                }
            }
        }

        for(int k = 0; k<idx_odd.size(); k++){
            for(int o_0 = idx_odd.size()-2, o_1 = idx_odd.size()-1; 0<=o_0; o_0--, o_1--){      
                int a_i = idx_odd[o_0], a_j = idx_odd[o_1]; 
                if(array_int[a_j]<array_int[a_i]){
                    int temp = array_int[a_i];
                    array_int[a_i] = array_int[a_j];
                    array_int[a_j] = temp;
                }    
            }
        }

        for(int idx_i=0, idx_j = 1; idx_j<array_length; idx_i++, idx_j++){
            if(array_int[idx_i]>array_int[idx_j]){
                flag = false;
                break;
            } 
        }

        if(flag == false){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
*/