#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int check_sum(int [], int, int);

int main()
{
    int n, num, missing_number;
    bool flag = false;
    cin>>n;
    vector <int> n_integers;
    for(int i =0; i<n-1; i++){
        cin>>num;
        n_integers.push_back(num);
    }
    sort(n_integers.begin(), n_integers.end());

    for(int j = 0; j<n-2 ;j++){

        if(n_integers[j+1]-n_integers[j]!=1 && n_integers.size()>1){
            missing_number= n_integers[j]+1;
            flag = true;
            break;
        }
        
    }
    if(n_integers.size()==1){
        if (n_integers[0]==1)
            missing_number =2;
        else 
            missing_number =1;
        flag = true;    
    }
    if(flag == false){
        if(n_integers[n_integers.size()-1] != n)   // Manage the cases when the missing number is either n or 1
            missing_number=n;
        else
            missing_number = 1;    
    }
    cout<<missing_number;

    return 0;
}

