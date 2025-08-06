#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,solvedProblems = 0, cont = 0;
    string chain;
   // getline(cin, chain);
    cin>>n;
    for(int i=0; i<n+1; i++){
        //cout<<"chain ingresada:  "<<chain<<endl;
        getline(cin, chain);
        for(char num: chain){
            if(num=='1')
                cont++;
        }
        if(cont >=2){
            solvedProblems++;
        }
        cont = 0;
    }
    cout<<solvedProblems;
    return(0);
}